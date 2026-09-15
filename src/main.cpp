#include "output_driver.h"
#include "usb_driver.h"
#include "key_inputs.h"
#include <memory>
// matrix driver

extern "C" void app_main() {
    std::shared_ptr<output_driver> out;

    // add logic for usb or bte
    out = usb_singleton;


    // start matrix driver



    // add some check that matrix driver has properly assigned key_input_singleton

    // start output driver
    out->start_handler_thread();
}
