//
// Created by jerry on 2/09/2026.
//

#ifndef CUST_KB_ESP32S3_USB_DRIVER_H
#define CUST_KB_ESP32S3_USB_DRIVER_H

#include "output_driver.h"
#include "../../../../../Users/jerry/.platformio/packages/toolchain-riscv32-esp/riscv32-esp-elf/include/c++/15.2.0/memory"
#include "class/hid/hid.h"

class usb_driver : public output_driver
{
public:
    usb_driver();
    static uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance);
    static uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen);
    static void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize);
    ~usb_driver() override;

private:
    void event_handler(std::stop_token stop) override;
};

inline std::shared_ptr<usb_driver> usb_singleton;

#endif //CUST_KB_ESP32S3_USB_DRIVER_H
