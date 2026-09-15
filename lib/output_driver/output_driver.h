//
// Created by jerry on 2/09/2026.
//

#ifndef UNTITLED_OUTPUT_DRIVER_H
#define UNTITLED_OUTPUT_DRIVER_H
#include <thread>

class output_driver
{
protected:
    void start_handler_thread();
    void kill_handler_thread();

private:
    virtual void event_handler(std::stop_token stop) = 0;
    virtual ~output_driver() = default;

    std::jthread o_thread;
};


#endif //UNTITLED_OUTPUT_DRIVER_H
