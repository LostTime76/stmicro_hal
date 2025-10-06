#include <stm32/u5/power.h>

void llif_set_power_range(uint8_t range)
{
	// Set the power range
	PWR->VOSR = (PWR->VOSR & ~PWR_VOSR_VOS_MASK) | (range << PWR_VOSR_VOS_SHIFT);
	
	// Wait for the range to lock
	while (~PWR->VOSR & PWR_VOSR_VOSRDY);
}

void llif_boost_on(void)
{	
	// Enable the EPD booster
	PWR->VOSR |= PWR_VOSR_BOOSTEN;
	
	// Wait for the EPD booster to lock
	while (~PWR->VOSR & PWR_VOSR_BOOSTRDY);
}