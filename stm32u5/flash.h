#pragma once

#include <stmicro/stm32u5/stm32u5.h>

/*!
 * @brief Sets the number of flash wait states
 *
 * @param wait_states
 *        The number of wait states to set
 *
 * @param prefetch
 *        True to turn on the prefetch buffer, false otherwise
 */

void llif_set_flash_ws(uint8_t wait_states, bool prefetch);