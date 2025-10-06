#pragma once

#include <uos/hal/gpio.h>
#include <stm32/u5/stm32u5.h>

/*!
 * @brief Gpio pin pull resistor setting
 */
typedef enum
{
	/*! No pull resistor on the pin */
	GPIO_PULL_NONE,
	
	/*! Set a pull up on the pin */
	GPIO_PULL_UP,
	
	/*! Set a pull down on the pin */
	GPIO_PULL_DOWN
} Gpio_Pull_Resistor;

/*!
 * @brief Gpio pin mode setting
 */
typedef enum
{
	/*! Set the pin to an input */
	GPIO_INPUT,
	
	/*! Set the pin to an output */
	GPIO_OUTPUT,
	
	/*! Set the pin to alternate function mode */
	GPIO_ALT_FUNC,
	
	/*! Set the pin to analog mode */
	GPIO_ANALOG
} Gpio_Mode;

/*!
 * @brief Gpio pin output drive setting
 */
typedef enum
{
	/*! Set the pin to push pull mode */
	GPIO_PUSH_PULL,
	
	/*! Set the pin to open drain mode */
	GPIO_OPEN_DRAIN
} Gpio_Drive;

/*!
 * @brief Gpio pin slew rate setting
 */
typedef enum
{
	/*! Set the lowest slew rate */
	GPIO_LOW_SPEED,
	
	/*! Set a medium speed slew rate */
	GPIO_MED_SPEED,
	
	/*! Set a high speed slew rate */
	GPIO_HIGH_SPEED,
	
	/*! Set the fastest possible slew rate */
	GPIO_VHIGH_SPEED
} Gpio_Slew;

/*!
 * @brief Configures all the main settings of a gpio pin at once
 *
 * @param port
 *        The gpio port containing the pin to configure
 *
 * @param pin
 *        The number of the pin within the port to configure
 *
 * @param mode
 *        The mode of the pin
 *
 * @param resistor
 *        The pull resistor setting of the pin
 *
 * @param drive
 *        The drive setting of the pin
 *
 * @param slew
 *        The slew rate setting of the pin
 */
void llif_gpio_config(GPIO_REGS* port, uint16_t pin,
	Gpio_Mode mode, Gpio_Pull_Resistor resistor, Gpio_Drive drive, Gpio_Slew slew);

/*!
 * @brief Sets the alternate function for a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to set the alternate function of
 *
 * @param pin
 *        The number of the pin within the port to set the alternate function of
 *
 * @param function
 *        The atlernate function to set for the pin
 */
void llif_gpio_set_alt_func(GPIO_REGS* port, uint16_t pin, uint8_t function);

/*!
 * @brief Sets mode of a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to set the mode of
 *
 * @param pin
 *        The number of the pin within the port to set the mode of
 *
 * @param mode
 *        The mode of the pin
 */
void llif_gpio_set_mode(GPIO_REGS* port, uint16_t pin, Gpio_Mode mode);

/*!
 * @brief Sets the pull resistor applied to a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to set the pull resistor of
 *
 * @param pin
 *        The number of the pin within the port to set the to set the pull resistor of
 *
 * @param resistor
 *        The pull resistor setting of the pin
 */
void llif_gpio_set_pull(GPIO_REGS* port, uint16_t pin, Gpio_Pull_Resistor resistor);

/*!
 * @brief Sets the output drive type for a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to set the drive type of
 *
 * @param pin
 *        The number of the pin within the port to set the drive type of
 *
 * @param drive
 *        The drive mode setting of the pin
 */
void llif_gpio_set_drive(GPIO_REGS* port, uint16_t pin, Gpio_Drive drive);

/*!
 * @brief Sets the slew rate for a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to set the slew rate of
 *
 * @param pin
 *        The number of the pin within the port to set the slew rate of
 *
 * @param slew
 *        The slew rate setting of the pin
 */
void llif_gpio_set_slew(GPIO_REGS* port, uint16_t pin, Gpio_Slew slew);