//
// Created by jerry on 2/09/2026.
//

#ifndef CUST_KB_ESP32S3_OUTPUT_DRIVER_H
#define CUST_KB_ESP32S3_OUTPUT_DRIVER_H
#include <thread>

class output_driver
{
public:
    void start_handler_thread();
    void kill_handler_thread();
    virtual ~output_driver() = default;

private:
    virtual void event_handler(std::stop_token stop) = 0;

    std::jthread o_thread;
};


#endif //CUST_KB_ESP32S3_OUTPUT_DRIVER_H
