#include <stm32/u5//flash.h>

void llif_set_flash_ws(uint8_t wait_states, bool prefetch)
{
	FLASH->ACR = (FLASH->ACR & ~(FLASH_ACR_LATENCY_MASK | FLASH_ACR_PRFTEN)) |
		(prefetch ? FLASH_ACR_PRFTEN : 0) | wait_states;
}