#include <stmicro/stm32u5/clock_priv.h>

void llif_set_sysclk_source(uint8_t source)
{
	// Set the new clock source
	RCC->CFGR1 = (RCC->CFGR1 & ~RCC_CFGR1_SW_MASK) | source;
	
	// Wait for the clock source to lock
	while (((RCC->CFGR1 & RCC_CFGR1_SWS_MASK) >> RCC_CFGR1_SWS_SHIFT) != source);
}

void llif_pll_config(llif_Pll_Port* port, const llif_Pll_Config* config)
{	
	// Set the pll multipliers and dividers
	*config->DIVR =
		((config->r_div - 1) << RCC_PLLDIVR_PLLR_SHIFT) |
		((config->q_div - 1) << RCC_PLLDIVR_PLLQ_SHIFT) | 
		((config->p_div - 1) << RCC_PLLDIVR_PLLP_SHIFT) | (config->n - 1);
		
	// Configure the pll
	*config->CFGR =
		(config->boost_div << RCC_PLLCFGR_PLLMBOOST_SHIFT) |
		((config->m - 1) << RCC_PLLCFGR_PLLM_SHIFT) |
		((RCC_PLLCFGR_PLLRGE_HS_RANGE * config->hs_range) << RCC_PLLCFGR_PLLRGE_SHIFT) |
		config->source;
		
	// Initialize the port
	port->on_flag = config->on_flag;
	port->CFGR    = config->CFGR;
}

void llif_set_ahb_div(uint8_t divider)
{
	RCC->CFGR2 = (RCC->CFGR2 & ~RCC_CFGR2_HPRE_MASK) | divider;
}

void llif_hse_on(bool bypass)
{
	// Configure the bypass mode
	RCC->CR = (RCC->CR & ~RCC_CR_HSEBYP) | (bypass ? RCC_CR_HSEBYP : 0); 
	
	// Turn on the hse oscillator
	RCC->CR |= RCC_CR_HSEON;
	
	// Wait for the oscillator to lock
	while (~RCC->CR & RCC_CR_HSERDY);
}

void llif_hse_off(void)
{
	// Turn off the hse oscillator
	RCC->CR &= ~RCC_CR_HSEON;
	
	// Wait for the oscillator to unlock
	while (RCC->CR & RCC_CR_HSERDY);
}

void llif_pll_on(const llif_Pll_Port* port)
{
	// Turn on the pll
	RCC->CR |= port->on_flag;
	
	// Wait for the pll to lock
	while (~RCC->CR & (port->on_flag << 1));
}

void llif_pll_outputs_on(const llif_Pll_Port* port, uint32_t flags)
{
	*port->CFGR |= flags;
}

void llif_pll_outputs_off(const llif_Pll_Port* port, uint32_t flags)
{
	*port->CFGR &= ~flags;
}