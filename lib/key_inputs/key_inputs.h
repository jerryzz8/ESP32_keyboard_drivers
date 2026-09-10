//
// Created by jerry on 28/08/2026.
//

#ifndef USB_DRIVER_KEY_INPUTS_H
#define USB_DRIVER_KEY_INPUTS_H

#include <array>
#include <cstdint>
#include <mutex>

class key_inputs
{
    public:
    key_inputs();
    void send_matrix(std::array<std::array<bool, 6>, 18>& matrix);
    uint64_t get_output() const;

    private:
    uint8_t modifiers;
    uint8_t reserved;
    std::array<uint8_t, 6> keys;
    int key_count;
};

std::mutex key_mutex;
key_inputs key_singleton;


#endif //USB_DRIVER_KEY_INPUTS_H
