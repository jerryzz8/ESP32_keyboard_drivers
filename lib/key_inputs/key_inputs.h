//
// Created by jerry on 28/08/2026.
//

#ifndef CUST_KB_ESP32S3_KEY_INPUTS_H
#define CUST_KB_ESP32S3_KEY_INPUTS_H

#include <array>
#include <cstdint>
#include <mutex>

#include "../../../../../Users/jerry/.platformio/packages/toolchain-riscv32-esp/riscv32-esp-elf/include/c++/15.2.0/memory"

/**
 * This class reads the matrix driver output and maps it to the associated HID codes.
 *
 * Currently the implementation simply sends the first 6 pressed keys and ignores any following keys.
 * Extra complexity seems unnecessary at this point, however may revise design.
 */
class key_inputs
{
public:
    key_inputs();
    void translate_matrix(std::array<std::array<bool, 6>, 18>& matrix);
    uint64_t get_output() const;

private:
    mutable std::mutex mtx;

    uint8_t modifiers;
    uint8_t reserved;
    std::array<uint8_t, 6> keys;
    int key_count;
};

inline std::unique_ptr<key_inputs> key_singleton;

#endif //CUST_KB_ESP32S3_KEY_INPUTS_H
