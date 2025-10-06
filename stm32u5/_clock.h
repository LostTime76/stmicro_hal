#pragma once

#include <uos/hal/clock.h>
#include <stm32/u5/clock.h>

constexpr uint32_t RCC_PLLEN_FLAGS = RCC_PLLCFGR_PLLREN | RCC_PLLCFGR_PLLQEN | RCC_PLLCFGR_PLLPEN;