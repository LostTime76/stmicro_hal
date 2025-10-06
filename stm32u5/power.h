#pragma once

#include <uos/base.h>
#include <stmicro/stm32u5/stm32u5.h>

/*!
 * @brief Sets the power range in the vosr register
 *
 * @param range
 *        The power range value to set
 */
void llif_set_power_range(uint8_t range);

/*!
 * @brief Enables the epd booster
 */
void llif_boost_on(void);