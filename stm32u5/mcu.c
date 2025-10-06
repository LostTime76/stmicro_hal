#include <stmicro/stm32u5/stm32u5.h>
#include <uos/hal/cm33/nvic.h>

alignas(IVECT_TAB_ALIGN) interrupt_handler ivect_table[IVECT_TAB_ENTS];

#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
void llif_mcu_init(void)
{
	// Set the location of the interrupt vector table
	SCB->VTOR = (uint32_t)ivect_table;
}

uint8_t nvic_get_prio_bits(void)
{
	return NVIC_PRIO_BITS;
}