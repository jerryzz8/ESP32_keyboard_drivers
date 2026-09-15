//
// Created by jerry on 2/09/2026.
//

#ifndef UNTITLED_USB_DRIVER_H
#define UNTITLED_USB_DRIVER_H
#include <cstdint>

#include "output_driver.h"
#include "class/hid/hid.h"


class usb_driver : public output_driver
{
public:
    uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance);
    uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen);
    void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize);

private:
    void event_handler(std::stop_token stop) override;
    usb_driver();
    ~usb_driver() override;
};


#endif //UNTITLED_USB_DRIVER_H
