#pragma once

#include <stm32/u5/stm32u5.h>

/*!
 * @brief Structure used to configure a pll.
 */
typedef struct
{
	/*! The ON flag within the RCC_CR that corresponds to the target pll */
	uint32_t on_flag;
	
	/*! The target pll configuration register */
	volatile uint32_t* CFGR;
	
	/*! The target pll division register */
	volatile uint32_t* DIVR;
	
	/*! True if the input to the pll (after division) is between 8 and 16MHz, false otherwise */
	bool hs_range;
	
	/*! The pll clock source */
	uint8_t source;
	
	/*! The input clock source divider */
	uint8_t m;
	
	/*! The pll multiplier */
	uint16_t n;
	
	/*! The boost divider for the pll */
	uint8_t boost_div;
	
	/*! The divider for the r output */
	uint8_t r_div;
	
	/*! The divider for the q output */
	uint8_t q_div;
	
	/*! The divider for the p output */
	uint8_t p_div;
} llif_Pll_Config;

/*!
 * @brief Structure that represents a pll
 */
typedef struct
{
	/*! Flag within RCC_CR used to turn on the pll */
	uint32_t on_flag;
	
	/*! The pll configuration register */
	volatile uint32_t* CFGR;
} llif_Pll_Port;

/*!
 * @brief Sets the system clock source
 *
 * @param source
 *        The clock source to switch to
 */
void llif_set_sysclk_source(uint8_t source);

/*!
 * @brief Configures a pll
 *
 * @param port
 *        The pll port to configure
 *
 * @param config
 *        The configuration for the pll
 */
void llif_pll_config(llif_Pll_Port* port, const llif_Pll_Config* config);

/*!
 * @brief Sets the ahb clock divider value
 *
 * @param divider
 *        The ahb clock divider value
 */
void llif_set_ahb_div(uint8_t divider);

/*!
 * @brief Turns on the high speed external oscillator
 *
 * @param bypass
 *        True to use bypass mode (external clock), false to use an external oscillator
 */
void llif_hse_on(bool bypass);

/*!
 * @brief Turns off the high speed external oscillator
 */
void llif_hse_off(void);

/*!
 * @brief Turns on the pll
 *
 * @param port
 *        The pll to turn on
 */

void llif_pll_on(const llif_Pll_Port* port);

/*!
 * @brief Turns on the specified outputs of the pll
 *
 * @param flags
 *        The flags within the PLLCFGR representing the outputs to turn on
 */
void llif_pll_outputs_on(const llif_Pll_Port* port, uint32_t flags);

/*!
 * @brief Turns off the specified outputs of the pll
 *
 * @param flags
 *        The flags within the PLLCFGR representing the outputs to turn off
 */
void llif_pll_outputs_off(const llif_Pll_Port* port, uint32_t flags);