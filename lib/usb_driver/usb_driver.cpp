//
// Created by jerry on 2/09/2026.
//
// Code is heavily referenced off example code provided by TinyUSB
// https://github.com/espressif/esp-idf/tree/master
//

#include "usb_driver.h"

#include "board_consts.h"
#include "esp_log.h"
#include "key_inputs.h"
#include "common/tusb_common.h"
#include "tinyusb.h"
#include "tinyusb_default_config.h"
#include "../../managed_components/espressif__tinyusb/src/class/hid/hid_device.h"
#include "class/hid/hid_device.h"
#include "driver/gpio.h"

static const char *TAG = "custom keyboard";

// static bool suspended = false;
// static bool wakeup_host = false;

/*********** TinyUSB descriptors ***************/

#define TUSB_DESC_TOTAL_LEN (TUD_CONFIG_DESC_LEN + CFG_TUD_HID * TUD_HID_DESC_LEN)

/**
 * @brief HID report descriptor
 *
 * A HID report descriptor basically lets the connecting device know the structure of
 * data sent by the keyboard, which bytes correspond to what data
 */
constexpr uint8_t hid_report_descriptor[] = {
    TUD_HID_REPORT_DESC_KEYBOARD(HID_REPORT_ID(HID_ITF_PROTOCOL_KEYBOARD))
};

static const char *hid_string_descriptor[5] = {
    (char[]){0x09, 0x04},   // 0: is supported language is English (0x0409)
    "N/A",                  // 1: Manufacturer
    "custom keyboard run on ESP-32 S3",      // 2: Product
    "67676767",             // 3: Serials, should use chip ID
    "USB HID Interface",    // 4: HID
};

/**
 * @brief HID config descriptor
 *
 * Sets up connecting USB to match required configurations
 */
const uint8_t hid_configuration_descriptor[] = {
    // Configuration number, interface count, string index, total length, attribute, power in mA
    TUD_CONFIG_DESCRIPTOR(1, 1, 0, TUSB_DESC_TOTAL_LEN, TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP, 100),

    // Interface number, string index, boot protocol, report descriptor len, EP In address, size & polling interval
    TUD_HID_DESCRIPTOR(0, 4, false, sizeof(hid_report_descriptor), 0x81, KEY_PACKET_SIZE, 10), // 10 ms probs fine
};

/********* TinyUSB HID callbacks ***************/

// Invoked when received GET HID REPORT DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const *usb_driver::tud_hid_descriptor_report_cb(uint8_t instance)
{
    // We use only one interface and one HID report descriptor, so we can ignore parameter 'instance'
    return hid_report_descriptor;
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t usb_driver::tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen)
{
    (void) instance;
    (void) report_id;
    (void) report_type;
    (void) buffer;
    (void) reqlen;

    return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void usb_driver::tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize)
{
}

/*************** Application *******************/

usb_driver::usb_driver()
{
    ESP_LOGI(TAG, "USB initialization");
    // Full speed not necessary, is compatible with the ESP32-S3 though
    tinyusb_config_t tusb_cfg = TINYUSB_DEFAULT_CONFIG();

    tusb_cfg.descriptor.device = NULL;
    tusb_cfg.descriptor.full_speed_config = hid_configuration_descriptor;
    tusb_cfg.descriptor.string = hid_string_descriptor;
    tusb_cfg.descriptor.string_count = std::size(hid_string_descriptor) / sizeof(hid_string_descriptor[0]);
#if (TUD_OPT_HIGH_SPEED)
    tusb_cfg.descriptor.high_speed_config = hid_configuration_descriptor;
#endif // TUD_OPT_HIGH_SPEED

    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));
    ESP_LOGI(TAG, "USB initialization DONE");
}

usb_driver::~usb_driver()
{
    kill_handler_thread();

    // close usb connection etc.
}

static void app_send_hid_demo()
{
    ESP_LOGI("", "Sending Keyboard report");
    const uint64_t data = key_singleton->get_output();
    const uint8_t modifier = data & 0xFF;
    uint8_t keycode[KEY_BUFFER_SIZE];

    for (int i = 2; i < KEY_BUFFER_SIZE + 2; i++)
    {
        keycode[i] = (data >> i * 8) & 0xFF;
    }

    tud_hid_keyboard_report(HID_ITF_PROTOCOL_KEYBOARD, modifier, keycode);
}

void usb_driver::event_handler(std::stop_token stop)
{
    while (!stop.stop_requested())
    {
        app_send_hid_demo();

        std::this_thread::sleep_for(std::chrono::milliseconds(OUTPUT_DELAY));
    }
}
