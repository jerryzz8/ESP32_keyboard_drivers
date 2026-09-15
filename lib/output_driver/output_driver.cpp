//
// Created by jerry on 2/09/2026.
//
// Code is heavily referenced off example code provided by TinyUSB
// https://github.com/espressif/esp-idf/tree/master
//

#include "output_driver.h"

void output_driver::start_handler_thread()
{
    o_thread = std::jthread(&output_driver::event_handler, this);
}


void output_driver::kill_handler_thread()
{
    // probably unnecessary to o_thread stop as thread stopping should be automatic
    o_thread.request_stop();
}
