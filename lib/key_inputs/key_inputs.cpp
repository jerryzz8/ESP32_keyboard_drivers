//
// Created by jerry on 28/08/2026.
//

#include "key_inputs.h"

#include "matrix_key_map.h"
#include "fn_key_map.h"
#include "board_consts.h"

key_inputs::key_inputs() : modifiers(0), reserved(0), keys({}), key_count(0)
{

}

void key_inputs::translate_matrix(std::array<std::array<bool, 6>, 18>& matrix)
{
    mtx.lock();

    modifiers = 0;
    reserved = 0;
    keys = {};
    key_count = 0;

    for (int i = 0; i < BOARD_COLS; i++)
    {
        for (int j = 0; j < BOARD_ROWS; j++)
        {
            int val;

            if (i == FN_COL && j == FN_ROW)
            {
                val = fn_key_map[i][j];
            } else
            {
                val = matrix_key_map[i][j];
            }

            if (val == KEY_NONE) continue;

            if (KEY_LEFTCTRL <= val && val <= KEY_RIGHTMETA) // block of mod keys "right/left {ctrl, alt, shift, meta}"
            {
                modifiers |= 1 << (val - KEY_LEFTCTRL);
                continue;
            }

            if (key_count >= KEY_BUFFER_SIZE) continue;

            keys[key_count] = val;
            key_count++;
        }
    }

    mtx.unlock();
}

uint64_t key_inputs::get_output() const
{
    mtx.lock();
    uint64_t output = 0 | modifiers;
    output |= reserved << 8;

    for (int i = 0; i < KEY_BUFFER_SIZE; i++)
    {
        output |= static_cast<uint64_t>(keys[i]) << ((i + 2) * 8);
    }
    mtx.unlock();

    return output;
}
