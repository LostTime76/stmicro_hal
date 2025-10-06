#include <stm32/u5/gpio.h>

static inline void _set_mode(GPIO_REGS* port, uint16_t pin, Gpio_Mode mode);
static inline void _set_pull(GPIO_REGS* port, uint16_t pin, Gpio_Pull_Resistor resistor);
static inline void _set_drive(GPIO_REGS* port, uint16_t pin, Gpio_Drive drive);
static inline void _set_slew(GPIO_REGS* port, uint16_t pin, Gpio_Slew slew);
static inline void _set_alt_func(GPIO_REGS* port, uint16_t pin, uint8_t function);

void hal_gpio_set(void* port, uint16_t pin)
{
	((volatile GPIO_REGS*)port)->BSRR = 1 << pin;
}

void hal_gpio_clear(void* port, uint16_t pin)
{
	((volatile GPIO_REGS*)port)->BRR = 1 << pin;
}

void hal_gpio_write(void* port, uint16_t pin, bool value)
{
	((volatile GPIO_REGS*)port)->BSRR = 1 << (pin + (!value << 4));
}

void hal_gpio_toggle(void* port, uint16_t pin)
{
	hal_gpio_write(port, pin, !hal_gpio_read(port, pin));
}

bool hal_gpio_read(void* port, uint16_t pin)
{
	return (((volatile GPIO_REGS*)port)->IDR & (1 << pin)) != 0;
}

void llif_gpio_config(GPIO_REGS* port, uint16_t pin,
	Gpio_Mode mode, Gpio_Pull_Resistor resistor, Gpio_Drive drive, Gpio_Slew slew)
{
	enter_crticial();
	
	_set_mode(port, pin, mode);
	_set_pull(port, pin, resistor);
	_set_drive(port, pin, drive);
	_set_slew(port, pin, slew);
	
	exit_critical();
}

void llif_gpio_set_alt_func(GPIO_REGS* port, uint16_t pin, uint8_t function)
{
	enter_crticial();
	
	_set_alt_func(port, pin, function);
	
	exit_critical();
}

void llif_gpio_set_mode(GPIO_REGS* port, uint16_t pin, Gpio_Mode mode)
{
	enter_crticial();
	
	_set_mode(port, pin, mode);
	
	exit_critical();
}

void llif_gpio_set_pull(GPIO_REGS* port, uint16_t pin, Gpio_Pull_Resistor resistor)
{
	enter_crticial();
	
	_set_pull(port, pin, resistor);
	
	exit_critical();
}

void llif_gpio_set_drive(GPIO_REGS* port, uint16_t pin, Gpio_Drive drive)
{	
	enter_crticial();
	
	_set_drive(port, pin, drive);
	
	exit_critical();
}

void llif_gpio_set_slew(GPIO_REGS* port, uint16_t pin, Gpio_Slew slew)
{
	enter_crticial();
	
	_set_slew(port, pin, slew);
	
	exit_critical();
}

static inline void _set_mode(GPIO_REGS* port, uint16_t pin, Gpio_Mode mode)
{
	uint32_t shift = pin << 1;
	
	port->MODER = (port->MODER & ~(3 << shift)) | (mode << shift); 
}

static inline void _set_pull(GPIO_REGS* port, uint16_t pin, Gpio_Pull_Resistor resistor)
{
	uint32_t shift = pin << 1;
	
	port->PUPDR = (port->PUPDR & ~(3 << shift)) | (resistor << shift);
}

static inline void _set_drive(GPIO_REGS* port, uint16_t pin, Gpio_Drive drive)
{
	port->OTYPER = (port->OTYPER & ~(1 << pin)) | (drive << pin);
}

static inline void _set_slew(GPIO_REGS* port, uint16_t pin, Gpio_Slew slew)
{
	uint32_t shift = pin << 1;
	
	port->OSPEEDR = (port->OSPEEDR & ~(3 << shift)) | (slew << shift);
}

static inline void _set_alt_func(GPIO_REGS* port, uint16_t pin, uint8_t function)
{
	volatile uint32_t* AFR = &port->AFR[pin >> 3];
	
	uint32_t shift = (pin & 0x7) << 2;
	
	*AFR = (*AFR & ~(0xF << shift)) | (function << shift);
}