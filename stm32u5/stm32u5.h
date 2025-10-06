#pragma once

#include <uos/hal/m33/m33.h>

constexpr int16_t WWDG_IRQN    = 0;
constexpr int16_t PVD_PVM      = 1;
constexpr int16_t RTC_IRQN     = 2;
constexpr int16_t RTC_S_IRQN   = 3;
constexpr int16_t TAMP_IRQN    = 4;
constexpr int16_t RAMCFG_IRQN  = 5;
constexpr int16_t FLASH_IRQN   = 6;
constexpr int16_t FLASH_S_IRQN = 7;
constexpr int16_t GTZC_IRQN    = 8;
constexpr int16_t RCC_IRQN     = 9;
constexpr int16_t RCC_S_IRQN   = 10;
constexpr int16_t EXTI0_IRQN   = 11;
constexpr int16_t EXTI1_IRQN   = 12;
constexpr int16_t EXTI2_IRQN   = 13;
constexpr int16_t EXTI3_IRQN   = 14;
constexpr int16_t EXTI4_IRQN   = 15;
constexpr int16_t EXTI5_IRQN   = 16;
constexpr int16_t EXTI6_IRQN   = 17;
constexpr int16_t EXTI7_IRQN   = 18;
constexpr int16_t EXTI8_IRQN   = 19;
constexpr int16_t EXTI9_IRQN   = 20;
constexpr int16_t EXTI10_IRQN  = 21;
constexpr int16_t EXTI11_IRQN  = 22;
constexpr int16_t EXTI12_IRQN  = 23;
constexpr int16_t EXTI13_IRQN  = 24;
constexpr int16_t EXTI14_IRQN  = 25;
constexpr int16_t EXTI15_IRQN  = 26;

constexpr uint8_t  NVIC_PRIO_BITS = 4;
constexpr uint16_t PERIPH_INTS    = 140;
constexpr uint16_t IVECT_TAB_ENTS = SYS_IVECT_TAB_ENTS + PERIPH_INTS;

constexpr uint32_t FLASH_ACR_PRFTEN       = 1UL << 8;
constexpr uint32_t FLASH_ACR_LPM          = 1UL << 11;
constexpr uint32_t FLASH_ACR_PDREQ1       = 1UL << 12;
constexpr uint32_t FLASH_ACR_PDREQ2       = 1UL << 13;
constexpr uint32_t FLASH_ACR_SLEEP_PD     = 1UL << 14;
constexpr uint32_t FLASH_ACR_LATENCY_MASK = 0xFUL;

typedef struct
{
	volatile uint32_t ACR;
	volatile uint32_t RSVD;
	volatile uint32_t NSKEYR;
	volatile uint32_t SECKEYR;
	volatile uint32_t RSVD2;
	volatile uint32_t PDKEY1R;
	volatile uint32_t PDKEY2R;
	volatile uint32_t NSSR;
	volatile uint32_t SECSR;
	volatile uint32_t NSCR;
	volatile uint32_t SECCR;
	volatile uint32_t OPSR;
	volatile uint32_t RSVD3[2];
	volatile uint32_t OPTR;
	volatile uint32_t NSBOOTADD0R;
	volatile uint32_t NSBOOTADD1R;
	volatile uint32_t SECBOOTADD0R;
	volatile uint32_t SECWM1R1;
	volatile uint32_t SECVM1R2;
	volatile uint32_t WRP1AR;
	volatile uint32_t WRP1BR;
	volatile uint32_t SECWM2R1;
	volatile uint32_t SECWM2R2;
	volatile uint32_t WRP2AR;
	volatile uint32_t WRP2BR;
	volatile uint32_t OEM1KEYR1;
	volatile uint32_t OEM1KEYR2;
	volatile uint32_t OEM2KEYR1;
	volatile uint32_t OEM2KEYR122;
	volatile uint32_t SECB1BR[8];
	volatile uint32_t SECBB2R[8];
	volatile uint32_t SECHDPCR;
	volatile uint32_t PRIVCFGR;
	volatile uint32_t RSVD4;
	volatile uint32_t PRIVBB1R[8];
	volatile uint32_t PRIVBB2R[8];
} FLASH_REGS;

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t VOSR;
	volatile uint32_t SVMCR;
	volatile uint32_t WUCR1;
	volatile uint32_t WUCR2;
	volatile uint32_t WUCR3;
	volatile uint32_t BDCR1;
	volatile uint32_t BDCR2;
	volatile uint32_t DBPR;
	volatile uint32_t UCPDR;
	volatile uint32_t SECCFGR;
	volatile uint32_t PRIVCFGR;
	volatile uint32_t SVMSR;
	volatile uint32_t BDSR;
	volatile uint32_t WUSR;
	volatile uint32_t WUSCR;
	volatile uint32_t APCR;
	volatile uint32_t PDCRA;
	volatile uint32_t PUCRB;
	volatile uint32_t PDCRB;
	volatile uint32_t PUCRC;
	volatile uint32_t PDCRC;
	volatile uint32_t PUCRD;
	volatile uint32_t PDCRD;
	volatile uint32_t PUCRE;
	volatile uint32_t PDCRE;
	volatile uint32_t PUCRF;
	volatile uint32_t PDCRF;
	volatile uint32_t PUCRG;
	volatile uint32_t PDCRG;
	volatile uint32_t PUCRH;
	volatile uint32_t PDCRH;
	volatile uint32_t PUCRI;
	volatile uint32_t PDCRI;
	volatile uint32_t PUCRJ;
	volatile uint32_t PDCRJ;
	volatile uint32_t RSVD[2];
	volatile uint32_t CR4;
	volatile uint32_t CR5;
} PWR_REGS;

constexpr uint32_t PWR_CR1_LPMS_MASK    = 3UL;
constexpr uint32_t PWR_CR1_RRSB1        = 1UL << 5;
constexpr uint32_t PWR_CR1_RRSB2        = 1UL << 6;
constexpr uint32_t PWR_CR1_ULPMEN       = 1UL << 7;
constexpr uint32_t PWR_CR1_SRAM1PD      = 1UL << 8;
constexpr uint32_t PWR_CR1_SRAM2PD      = 1UL << 9;
constexpr uint32_t PWR_CR1_SRAM3PD      = 1UL << 10;
constexpr uint32_t PWR_CR1_SRAM4PD      = 1UL << 11;
constexpr uint32_t PWR_CR1_SRAM5PD      = 1UL << 12;
constexpr uint32_t PWR_CR1_SRAM6PD      = 1UL << 13;
constexpr uint32_t PWR_CR1_FORCE_USBPWR = 1UL << 15;

constexpr uint32_t PWR_CR2_SRAM1PDS1   = 1UL;
constexpr uint32_t PWR_CR2_SRAM1PDS2   = 1UL << 1;
constexpr uint32_t PWR_CR2_SRAM1PDS3   = 1UL << 2;
constexpr uint32_t PWR_CR2_SRAM2PDS1   = 1UL << 4;
constexpr uint32_t PWR_CR2_SRAM2PDS2   = 1UL << 5;
constexpr uint32_t PWR_CR2_SRAM4PDS    = 1UL << 6;
constexpr uint32_t PWR_CR2_DC2RAMPDS   = 1UL << 7;
constexpr uint32_t PWR_CR2_ICRAMPDS    = 1UL << 8;
constexpr uint32_t PWR_CR2_DC1RAMPDS   = 1UL << 9;
constexpr uint32_t PWR_CR2_DMA2DRAMPDS = 1UL << 10;
constexpr uint32_t PWR_CR2_PRAMPDS     = 1UL << 11;
constexpr uint32_t PWR_CR2_PKARAMPDS   = 1UL << 12;
constexpr uint32_t PWR_CR2_SRAM4FWU    = 1UL << 13;
constexpr uint32_t PWR_CR2_FLASHFWU    = 1UL << 14;
constexpr uint32_t PWR_CR2_SRAM3PDS1   = 1UL << 16;
constexpr uint32_t PWR_CR2_SRAM3PDS2   = 1UL << 17;
constexpr uint32_t PWR_CR2_SRAM3PDS3   = 1UL << 18;
constexpr uint32_t PWR_CR2_SRAM3PDS4   = 1UL << 19;
constexpr uint32_t PWR_CR2_SRAM3PDS5   = 1UL << 20;
constexpr uint32_t PWR_CR2_SRAM3PDS6   = 1UL << 21;
constexpr uint32_t PWR_CR2_SRAM3PDS7   = 1UL << 22;
constexpr uint32_t PWR_CR2_SRAM3PDS8   = 1UL << 23;
constexpr uint32_t PWR_CR2_GPRAMPDS    = 1UL << 24;
constexpr uint32_t PWR_CR2_DSIRAMPDS   = 1UL << 25;
constexpr uint32_t PWR_CR2_JPEGRAMPDS  = 1UL << 26;
constexpr uint32_t PWR_CR2_SRDRUN      = 1UL << 31;

constexpr uint32_t PWR_CR3_REGSEL = 1UL << 1;
constexpr uint32_t PWR_CR3_FSTEN  = 1UL << 2;

constexpr uint32_t PWR_VOSR_USBBOOSTRDY = 1UL << 13;
constexpr uint32_t PWR_VOSR_BOOSTRDY    = 1UL << 14;
constexpr uint32_t PWR_VOSR_VOSRDY      = 1UL << 15;
constexpr uint32_t PWR_VOSR_VOS_RANGE4  = 0;
constexpr uint32_t PWR_VOSR_VOS_RANGE3  = 1;
constexpr uint32_t PWR_VOSR_VOS_RANGE2  = 2;
constexpr uint32_t PWR_VOSR_VOS_RANGE1  = 3;
constexpr uint32_t PWR_VOSR_VOS_SHIFT   = 16;
constexpr uint32_t PWR_VOSR_VOS_MASK    = 3UL << PWR_VOSR_VOS_SHIFT;
constexpr uint32_t PWR_VOSR_BOOSTEN     = 1UL << 18;
constexpr uint32_t PWR_VOSR_USBWREN     = 1UL << 19;
constexpr uint32_t PWR_VOSR_USBBOOSTEN  = 1UL << 20;
constexpr uint32_t PWR_VOSR_VDD11USBDIS = 1UL << 21;

constexpr uint32_t PWR_SVMCR_PVDE       = 1UL << 4;
constexpr uint32_t PWR_SVMCR_PVDLS_MASK = 7UL << 5;
constexpr uint32_t PWR_SVMCR_UVMEN      = 1UL << 24;
constexpr uint32_t PWR_SVMCR_IO2VMEN    = 1UL << 25;
constexpr uint32_t PWR_SVMCR_AVM1EN     = 1UL << 26;
constexpr uint32_t PWR_SVMCR_AVM2EN     = 1UL << 27;
constexpr uint32_t PWR_SVMCR_USV        = 1UL << 28;
constexpr uint32_t PWR_SVMCR_IO2SV      = 1UL << 29;
constexpr uint32_t PWR_SVMCR_ASC        = 1UL << 30;

constexpr uint32_t PWR_BDCR1_BREN  = 1UL;
constexpr uint32_t PWR_BDCR1_MONEN = 1UL << 4;

constexpr uint32_t PWR_BDCR2_VBE  = 1UL;
constexpr uint32_t PWR_BDCR2_VBRS = 1UL << 1;

constexpr uint32_t PWR_DBPR_DBP = 1UL;

constexpr uint32_t PWR_UCPDR_UCPD_DBDIS = 1UL;
constexpr uint32_t PWR_UCPDR_UCPD_STBY  = 1UL << 1;

constexpr uint32_t PWR_SR_CSSF  = 1UL;
constexpr uint32_t PWR_SR_STOPF = 1UL << 1;
constexpr uint32_t PWR_SR_SBF   = 1UL << 2;

constexpr uint32_t PWR_SVMSR_REGS        = 1UL << 1;
constexpr uint32_t PWR_SVMSR_PVDO        = 1UL << 4;
constexpr uint32_t PWR_SVMSR_ACTVOSRDY   = 1UL << 15;
constexpr uint32_t PWR_SVMSR_ACTVOS_MASK = 3UL << 16;
constexpr uint32_t PWR_SVMSR_VDDUSBRDY   = 1UL << 24;
constexpr uint32_t PWR_SVMSR_VDDIO2RDY   = 1UL << 25;
constexpr uint32_t PWR_SVMSR_VDDA1RDY    = 1UL << 26;
constexpr uint32_t PWR_SVMSR_VDDA2RDY    = 1UL << 27;

constexpr uint32_t PWR_BDSR_VBATH = 1UL << 1;
constexpr uint32_t PWR_BDSR_TEMPL = 1UL << 2;
constexpr uint32_t PWR_BDSR_TEMPH = 1UL << 3;

constexpr uint32_t PWR_APCR_APC = 1UL;

constexpr uint32_t PWR_CR4_SRAM1PDS4  = 1UL;
constexpr uint32_t PWR_CR4_SRAM1PDS5  = 1UL << 1;
constexpr uint32_t PWR_CR4_SRAM1PDS6  = 1UL << 2;
constexpr uint32_t PWR_CR4_SRAM1PDS7  = 1UL << 3;
constexpr uint32_t PWR_CR4_SRAM1PDS8  = 1UL << 4;
constexpr uint32_t PWR_CR4_SRAM1PDS9  = 1UL << 5;
constexpr uint32_t PWR_CR4_SRAM1PDS10 = 1UL << 6;
constexpr uint32_t PWR_CR4_SRAM1PDS11 = 1UL << 7;
constexpr uint32_t PWR_CR4_SRAM1PDS12 = 1UL << 8;
constexpr uint32_t PWR_CR4_SRAM3PDS9  = 1UL << 10;
constexpr uint32_t PWR_CR4_SRAM3PDS10 = 1UL << 11;
constexpr uint32_t PWR_CR4_SRAM3PDS11 = 1UL << 12;
constexpr uint32_t PWR_CR4_SRAM3PDS12 = 1UL << 13;
constexpr uint32_t PWR_CR4_SRAM3PDS13 = 1UL << 14;
constexpr uint32_t PWR_CR4_SRAM5PDS1  = 1UL << 16;
constexpr uint32_t PWR_CR4_SRAM5PDS2  = 1UL << 17;
constexpr uint32_t PWR_CR4_SRAM5PDS3  = 1UL << 18;
constexpr uint32_t PWR_CR4_SRAM5PDS4  = 1UL << 19;
constexpr uint32_t PWR_CR4_SRAM5PDS5  = 1UL << 20;
constexpr uint32_t PWR_CR4_SRAM5PDS6  = 1UL << 21;
constexpr uint32_t PWR_CR4_SRAM5PDS7  = 1UL << 22;
constexpr uint32_t PWR_CR4_SRAM5PDS8  = 1UL << 23;
constexpr uint32_t PWR_CR4_SRAM5PDS9  = 1UL << 24;
constexpr uint32_t PWR_CR4_SRAM5PDS10 = 1UL << 25;
constexpr uint32_t PWR_CR4_SRAM5PDS11 = 1UL << 26;
constexpr uint32_t PWR_CR4_SRAM5PDS12 = 1UL << 27;
constexpr uint32_t PWR_CR4_SRAM5PDS13 = 1UL << 28;

constexpr uint32_t PWR_CR5_SRAM6PDS1 = 1UL;
constexpr uint32_t PWR_CR5_SRAM6PDS2 = 1UL << 1;
constexpr uint32_t PWR_CR5_SRAM6PDS3 = 1UL << 2;
constexpr uint32_t PWR_CR5_SRAM6PDS4 = 1UL << 3;
constexpr uint32_t PWR_CR5_SRAM6PDS5 = 1UL << 4;
constexpr uint32_t PWR_CR5_SRAM6PDS6 = 1UL << 5;
constexpr uint32_t PWR_CR5_SRAM6PDS7 = 1UL << 6;
constexpr uint32_t PWR_CR5_SRAM6PDS8 = 1UL << 7;

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t RSVD;
	volatile uint32_t ICSCR1;
	volatile uint32_t ICSCR2;
	volatile uint32_t ICSCR3;
	volatile uint32_t CRRCR;
	volatile uint32_t RSVD2;
	volatile uint32_t CFGR1;
	volatile uint32_t CFGR2;
	volatile uint32_t CFGR3;
	volatile uint32_t PLL1CFGR;
	volatile uint32_t PLL2CFGR;
	volatile uint32_t PLL3CFGR;
	volatile uint32_t PLL1DIVR;
	volatile uint32_t PLL1FRACR;
	volatile uint32_t PLL2DIVR;
	volatile uint32_t PLL2FRACR;
	volatile uint32_t PLL3DIVR;
	volatile uint32_t PLL3FRACR;
	volatile uint32_t RSVD3;
	volatile uint32_t CIER;
	volatile uint32_t CIFR;
	volatile uint32_t CICR;
	volatile uint32_t RSVD4;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR1;
	volatile uint32_t AHB2RSTR2;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RSVD5;
	volatile uint32_t APB1RSTR1;
	volatile uint32_t APB1RSTR2;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB3RSTR;
	volatile uint32_t RSVD6;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR1;
	volatile uint32_t AHB2ENR2;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RSVD7;
	volatile uint32_t APB1ENR1;
	volatile uint32_t APB1ENR2;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB3ENR;
	volatile uint32_t RSVD8;
	volatile uint32_t AHB1SMENR;
	volatile uint32_t AHB2SMENR1;
	volatile uint32_t AHB2SMENR2;
	volatile uint32_t AHB3SMENR;
	volatile uint32_t RSVD9;
	volatile uint32_t APB1SMENR1;
	volatile uint32_t APB1SMENR2;
	volatile uint32_t APB2SMENR;
	volatile uint32_t APB3SMENR;
	volatile uint32_t RSVD10;
	volatile uint32_t SRDAMR;
	volatile uint32_t CCIPR1;
	volatile uint32_t CCIPR2;
	volatile uint32_t CCIPR3;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RSVD11[5];
	volatile uint32_t SECCFGR;
	volatile uint32_t PRIVCFGR;
} RCC_REGS;

constexpr uint32_t RCC_CR_MSISON     = 1UL;
constexpr uint32_t RCC_CR_MSIKERON   = 1UL << 1;
constexpr uint32_t RCC_CR_MSISRDY    = 1UL << 2;
constexpr uint32_t RCC_CR_MSIPLLEN   = 1UL << 3;
constexpr uint32_t RCC_CR_MSIKON     = 1UL << 4;
constexpr uint32_t RCC_CR_MSIKRDY    = 1UL << 5;
constexpr uint32_t RCC_CR_MSIPLLSEL  = 1UL << 6;
constexpr uint32_t RCC_CR_MSIPLLFAST = 1UL << 7;
constexpr uint32_t RCC_CR_HSION      = 1UL << 8;
constexpr uint32_t RCC_CR_HSIKERON   = 1UL << 9;
constexpr uint32_t RCC_CR_HSIRDY     = 1UL << 10;
constexpr uint32_t RCC_CR_HSI48ON    = 1UL << 12;
constexpr uint32_t RCC_CR_HSI48RDY   = 1UL << 13;
constexpr uint32_t RCC_CR_SHSION     = 1UL << 14;
constexpr uint32_t RCC_CR_SHSIRDY    = 1UL << 15;
constexpr uint32_t RCC_CR_HSEON      = 1UL << 16;
constexpr uint32_t RCC_CR_HSERDY     = 1UL << 17;
constexpr uint32_t RCC_CR_HSEBYP     = 1UL << 18;
constexpr uint32_t RCC_CR_CSSON      = 1UL << 19;
constexpr uint32_t RCC_CR_HSEEXT     = 1UL << 20;
constexpr uint32_t RCC_CR_PLL1ON     = 1UL << 24;
constexpr uint32_t RCC_CR_PLL1RDY    = 1UL << 25;
constexpr uint32_t RCC_CR_PLL2ON     = 1UL << 26;
constexpr uint32_t RCC_CR_PLL2RDY    = 1UL << 27;
constexpr uint32_t RCC_CR_PLL3ON     = 1UL << 28;
constexpr uint32_t RCC_CR_PLL3RDY    = 1UL << 29;

constexpr uint32_t RCC_ICSCR1_MSICAL3_MASK   = 0x1FUL;
constexpr uint32_t RCC_ICSCR1_MSICAL2_MASK   = 0x1F << 5;
constexpr uint32_t RCC_ICSCR1_MSICAL1_MASK   = 0x1F << 10;
constexpr uint32_t RCC_ICSCR1_MSICAL0_MASK   = 0x1F << 15;
constexpr uint32_t RCC_ICSCR1_MSIBIAS        = 1UL << 22;
constexpr uint32_t RCC_ICSCR1_MSIRGSEL       = 1UL << 23;
constexpr uint32_t RCC_ICSCR1_MSIKRANGE_MASK = 0xFUL << 24;
constexpr uint32_t RCC_ICSCR1_MSISRANGE_MASK = 0xFUL << 28;

constexpr uint32_t RCC_ICSCR2_MSITRIM3_MASK = 0x1FUL;
constexpr uint32_t RCC_ICSCR2_MSITRIM2_MASK = 0x1FUL << 5;
constexpr uint32_t RCC_ICSCR2_MSITRIM1_MASK = 0x1FUL << 10;
constexpr uint32_t RCC_ICSCR2_MSITRIM0_MASK = 0x1FUL << 15;

constexpr uint32_t RCC_ICSCR3_HSICAL_MASK  = 0xFFFUL;
constexpr uint32_t RCC_ICSCR3_HSITRIM_MASK = 0x1FUL << 16;

constexpr uint32_t RCC_CRRCR_HSI48CAL_MASK = 0x1FFUL;

constexpr uint32_t RCC_CFGR1_SW_MASK       = 0x3UL;
constexpr uint32_t RCC_CFGR1_SW_MSIS       = 0;
constexpr uint32_t RCC_CFGR1_SW_HSI16      = 1;
constexpr uint32_t RCC_CFGR1_SW_HSE        = 2;
constexpr uint32_t RCC_CFGR1_SW_PLL1_R     = 3;
constexpr uint32_t RCC_CFGR1_SWS_SHIFT     = 2;
constexpr uint32_t RCC_CFGR1_SWS_MASK      = 0x3UL << RCC_CFGR1_SWS_SHIFT;
constexpr uint32_t RCC_CFGR1_STOPWUCK      = 1UL << 4;
constexpr uint32_t RCC_CFGR1_STOPKERWUCK   = 1UL << 5;
constexpr uint32_t RCC_CFGR1_MCOSEL_MASK   = 0xFUL << 23;
constexpr uint32_t RCC_CFGR1_MCOSEL_NONE   = 0;
constexpr uint32_t RCC_CFGR1_MCOSEL_SYSCLK = 1;
constexpr uint32_t RCC_CFGR1_MCOSEL_MSIS   = 2;
constexpr uint32_t RCC_CFGR1_MCOSEL_HSI16  = 3;
constexpr uint32_t RCC_CFGR1_MCOSEL_HSE    = 4;
constexpr uint32_t RCC_CFGR1_MCOSEL_PLL1_R = 5;
constexpr uint32_t RCC_CFGR1_MCOSEL_LSI    = 6;
constexpr uint32_t RCC_CFGR1_MCOSEL_LSE    = 7;
constexpr uint32_t RCC_CFGR1_MCOSEL_HSI48  = 8;
constexpr uint32_t RCC_CFGR1_MCOSEL_MSIK   = 9;
constexpr uint32_t RCC_CFGR1_MCOPRE_MASK   = 0x7UL << 28;

constexpr uint32_t RCC_CFGR2_HPRE_MASK    = 0xFUL;
constexpr uint32_t RCC_CFGR2_HPRE_DIV1    = 0;
constexpr uint32_t RCC_CFGR2_HPRE_DIV2    = 8;
constexpr uint32_t RCC_CFGR2_HPRE_DIV4    = 9;
constexpr uint32_t RCC_CFGR2_HPRE_DIV8    = 10;
constexpr uint32_t RCC_CFGR2_HPRE_DIV16   = 11;
constexpr uint32_t RCC_CFGR2_HPRE_DIV64   = 12;
constexpr uint32_t RCC_CFGR2_HPRE_DIV128  = 13;
constexpr uint32_t RCC_CFGR2_HPRE_DIV256  = 14;
constexpr uint32_t RCC_CFGR2_HPRE_DIV2512 = 15;
constexpr uint32_t RCC_CFGR2_PPRE1_SHIFT  = 4;
constexpr uint32_t RCC_CFGR2_PPRE1_MASK   = 0x7UL << RCC_CFGR2_PPRE1_SHIFT;
constexpr uint32_t RCC_CFGR2_PPRE2_SHIFT  = 8;
constexpr uint32_t RCC_CFGR2_PPRE2_MASK   = 0x7UL << RCC_CFGR2_PPRE2_SHIFT;
constexpr uint32_t RCC_CFGR2_PPRE_DIV1    = 0;
constexpr uint32_t RCC_CFGR2_PPRE_DIV2    = 4;
constexpr uint32_t RCC_CFGR2_PPRE_DIV4    = 5;
constexpr uint32_t RCC_CFGR2_PPRE_DIV8    = 6;
constexpr uint32_t RCC_CFGR2_PPRE_DIV16   = 7;
constexpr uint32_t RCC_CFGR2_DPRE_DIV1    = 0;
constexpr uint32_t RCC_CFGR2_DPRE_DIV2    = 4;
constexpr uint32_t RCC_CFGR2_DPRE_DIV4    = 5;
constexpr uint32_t RCC_CFGR2_DPRE_DIV8    = 6;
constexpr uint32_t RCC_CFGR2_DPRE_DIV16   = 7;
constexpr uint32_t RCC_CFGR2_DPRE_SHIFT   = 12;
constexpr uint32_t RCC_CFGR2_DPRE_MASK    = 0x7UL << RCC_CFGR2_DPRE_SHIFT;
constexpr uint32_t RCC_CFGR2_AHB1DIS      = 1UL << 16;
constexpr uint32_t RCC_CFGR2_AHB2DIS1     = 1UL << 17;
constexpr uint32_t RCC_CFGR2_AHB2DIS2     = 1UL << 18;
constexpr uint32_t RCC_CFGR2_APB1DIS      = 1UL << 19;
constexpr uint32_t RCC_CFGR2_APB2DIS      = 1UL << 20;

constexpr uint32_t RCC_CFGR3_PPRE3_MASK = 0x7UL << 4;
constexpr uint32_t RCC_CFGR3_AHB3DIS    = 1UL << 16;
constexpr uint32_t RCC_CFGR3_APB3DIS    = 1UL << 17;

constexpr uint32_t RCC_PLLCFGR_PLLSRC_NONE     = 0;
constexpr uint32_t RCC_PLLCFGR_PLLSRC_MSIS     = 1;
constexpr uint32_t RCC_PLLCFGR_PLLSRC_HSI16    = 2;
constexpr uint32_t RCC_PLLCFGR_PLLSRC_HSE      = 3;
constexpr uint32_t RCC_PLLCFGR_PLLSRC_MASK     = 0x3UL;
constexpr uint32_t RCC_PLLCFGR_PLLRGE_LS_RANGE = 0;
constexpr uint32_t RCC_PLLCFGR_PLLRGE_HS_RANGE = 3;
constexpr uint32_t RCC_PLLCFGR_PLLRGE_SHIFT    = 2;
constexpr uint32_t RCC_PLLCFGR_PLLRGE_MASK     = 0x3UL << RCC_PLLCFGR_PLLRGE_SHIFT;
constexpr uint32_t RCC_PLLCFGR_PLLFRACEN       = 1UL << 4;
constexpr uint32_t RCC_PLLCFGR_PLLM_SHIFT      = 8;
constexpr uint32_t RCC_PLLCFGR_PLLM_MASK       = 0xFUL << RCC_PLLCFGR_PLLM_SHIFT;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV1  = 0;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV2  = 1;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV4  = 2;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV6  = 3;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV8  = 4;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV10 = 5;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV12 = 6;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV14 = 7;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_DIV16 = 8;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_SHIFT = 12;
constexpr uint32_t RCC_PLLCFGR_PLLMBOOST_MASK  = 0xFUL << RCC_PLLCFGR_PLLMBOOST_SHIFT;
constexpr uint32_t RCC_PLLCFGR_PLLPEN          = 1UL << 16;
constexpr uint32_t RCC_PLLCFGR_PLLQEN          = 1UL << 17;
constexpr uint32_t RCC_PLLCFGR_PLLREN          = 1UL << 18;

constexpr uint32_t RCC_PLLDIVR_PLLN_MASK  = 0x1FFUL;
constexpr uint32_t RCC_PLLDIVR_PLLP_SHIFT = 9;
constexpr uint32_t RCC_PLLDIVR_PLLQ_SHIFT = 16;
constexpr uint32_t RCC_PLLDIVR_PLLR_SHIFT = 24;
constexpr uint32_t RCC_PLLDIVR_PLLP_MASK  = 0x7FUL << RCC_PLLDIVR_PLLP_SHIFT;
constexpr uint32_t RCC_PLLDIVR_PLLQ_MASK  = 0x7FUL << RCC_PLLDIVR_PLLQ_SHIFT;
constexpr uint32_t RCC_PLLDIVR_PLLR_MASK  = 0x7FUL << RCC_PLLDIVR_PLLR_SHIFT;

constexpr uint32_t RCC_PLLFRACR_PLLFRACN_MASK = 0x1FFFUL << 3;

constexpr uint32_t RCC_CI_LSIRDY   = 1UL;
constexpr uint32_t RCC_CI_LSERDY   = 1UL << 1;
constexpr uint32_t RCC_CI_MSISRDY  = 1UL << 2;
constexpr uint32_t RCC_CI_HSIRDY   = 1UL << 3;
constexpr uint32_t RCC_CI_HSERDY   = 1UL << 4;
constexpr uint32_t RCC_CI_HSI48RDY = 1UL << 5;
constexpr uint32_t RCC_CI_PLL1RDY  = 1UL << 6;
constexpr uint32_t RCC_CI_PLL2RDY  = 1UL << 7;
constexpr uint32_t RCC_CI_PLL3RDY  = 1UL << 8;
constexpr uint32_t RCC_CI_MSIKRDY  = 1UL << 11;
constexpr uint32_t RCC_CI_SHSIRDY  = 1UL << 12;

constexpr uint32_t RCC_AHB1_GPDMA1  = 1UL;
constexpr uint32_t RCC_AHB1_CORDIC  = 1UL << 1;
constexpr uint32_t RCC_AHB1_FMAC    = 1UL << 2;
constexpr uint32_t RCC_AHB1_MDF1    = 1UL << 3;
constexpr uint32_t RCC_AHB1_FLASH   = 1UL << 6;
constexpr uint32_t RCC_AHB1_CRC     = 1UL << 12;
constexpr uint32_t RCC_AHB1_JPEG    = 1UL << 15;
constexpr uint32_t RCC_AHB1_TSC     = 1UL << 16;
constexpr uint32_t RCC_AHB1_RAMCFG  = 1UL << 17;
constexpr uint32_t RCC_AHB1_DMA2D   = 1UL << 18;
constexpr uint32_t RCC_AHB1_GFXMU   = 1UL << 19;
constexpr uint32_t RCC_AHB1_GPU2D   = 1UL << 20;
constexpr uint32_t RCC_AHB1_DMACHE2 = 1UL << 21;
constexpr uint32_t RCC_AHB1_GTZC1   = 1UL << 24;
constexpr uint32_t RCC_AHB1_BKPSRAM = 1UL << 28;
constexpr uint32_t RCC_AHB1_DMACHE1 = 1UL << 30;
constexpr uint32_t RCC_AHB1_SRAM1   = 1UL << 31;

constexpr uint32_t RCC_AHB2_GPIOA      = 1UL;
constexpr uint32_t RCC_AHB2_GPIOB      = 1UL << 1;
constexpr uint32_t RCC_AHB2_GPIOC      = 1UL << 2;
constexpr uint32_t RCC_AHB2_GPIOD      = 1UL << 3;
constexpr uint32_t RCC_AHB2_GPIOE      = 1UL << 4;
constexpr uint32_t RCC_AHB2_GPIOF      = 1UL << 5;
constexpr uint32_t RCC_AHB2_GPIOG      = 1UL << 6;
constexpr uint32_t RCC_AHB2_GPIOH      = 1UL << 7;
constexpr uint32_t RCC_AHB2_GPIOI      = 1UL << 8;
constexpr uint32_t RCC_AHB2_GPIOJ      = 1UL << 9;
constexpr uint32_t RCC_AHB2_ADC12      = 1UL << 10;
constexpr uint32_t RCC_AHB2_DCMI_PSSI  = 1UL << 12;
constexpr uint32_t RCC_AHB2_OTG        = 1UL << 14;
constexpr uint32_t RCC_AHB2_OTGHSPHY   = 1UL << 15;
constexpr uint32_t RCC_AHB2_AES        = 1UL << 16;
constexpr uint32_t RCC_AHB2_HASH       = 1UL << 17;
constexpr uint32_t RCC_AHB2_RNG        = 1UL << 18;
constexpr uint32_t RCC_AHB2_PKA        = 1UL << 19;
constexpr uint32_t RCC_AHB2_SAES       = 1UL << 20;
constexpr uint32_t RCC_AHB2_OCTOSPIM   = 1UL << 21;
constexpr uint32_t RCC_AHB2_OTFDEC1    = 1UL << 23;
constexpr uint32_t RCC_AHB2_OTFDEC2    = 1UL << 24;
constexpr uint32_t RCC_AHB2_SDMC1      = 1UL << 27;
constexpr uint32_t RCC_AHB2_SDMC2      = 1UL << 28;
constexpr uint32_t RCC_AHB2_SRAM2      = 1UL << 30;
constexpr uint32_t RCC_AHB2_SRAM3      = 1UL << 31;

constexpr uint32_t RCC_AHB2_FSMC     = 1UL;
constexpr uint32_t RCC_AHB2_OTCOSPI1 = 1UL << 4;
constexpr uint32_t RCC_AHB2_OTCOSPI2 = 1UL << 8;
constexpr uint32_t RCC_AHB2_HSPI1    = 1UL << 12;
constexpr uint32_t RCC_AHB2_SRAM6    = 1UL << 30;
constexpr uint32_t RCC_AHB2_SRAM5    = 1UL << 31;

constexpr uint32_t RCC_AHB3_LPGPIO1 = 1UL;
constexpr uint32_t RCC_AHB3_PWR     = 1UL << 2;
constexpr uint32_t RCC_AHB3_ADC4    = 1UL << 5;
constexpr uint32_t RCC_AHB3_DAC1    = 1UL << 6;
constexpr uint32_t RCC_AHB3_LPDMA1  = 1UL << 9;
constexpr uint32_t RCC_AHB3_ADF1    = 1UL << 10;
constexpr uint32_t RCC_AHB3_GTZC2   = 1UL << 12;
constexpr uint32_t RCC_AHB3_SRAM4   = 1UL << 31;

constexpr uint32_t RCC_APB1_TIM2   = 1UL;
constexpr uint32_t RCC_APB1_TIM3   = 1UL << 1;
constexpr uint32_t RCC_APB1_TIM4   = 1UL << 2;
constexpr uint32_t RCC_APB1_TIM5   = 1UL << 3;
constexpr uint32_t RCC_APB1_TIM6   = 1UL << 4;
constexpr uint32_t RCC_APB1_TIM7   = 1UL << 5;
constexpr uint32_t RCC_APB1_WWDG   = 1UL << 11;
constexpr uint32_t RCC_APB1_SPI2   = 1UL << 14;
constexpr uint32_t RCC_APB1_USART2 = 1UL << 17;
constexpr uint32_t RCC_APB1_USART3 = 1UL << 18;
constexpr uint32_t RCC_APB1_UART4  = 1UL << 19;
constexpr uint32_t RCC_APB1_UART5  = 1UL << 20;
constexpr uint32_t RCC_APB1_I2C1   = 1UL << 21;
constexpr uint32_t RCC_APB1_I2C2   = 1UL << 22;
constexpr uint32_t RCC_APB1_CRS    = 1UL << 24;
constexpr uint32_t RCC_APB1_USART6 = 1UL << 25;

constexpr uint32_t RCC_APB1_I2C4   = 1UL << 1;
constexpr uint32_t RCC_APB1_LPTIM2 = 1UL << 5;
constexpr uint32_t RCC_APB1_I2C5   = 1UL << 6;
constexpr uint32_t RCC_APB1_I2C6   = 1UL << 7;
constexpr uint32_t RCC_APB1_FDCAN1 = 1UL << 9;
constexpr uint32_t RCC_APB1_UCPD1  = 1UL << 23;

constexpr uint32_t RCC_APB2_TIM1   = 1UL << 11;
constexpr uint32_t RCC_APB2_SPI1   = 1UL << 12;
constexpr uint32_t RCC_APB2_TIM8   = 1UL << 13;
constexpr uint32_t RCC_APB2_USART1 = 1UL << 14;
constexpr uint32_t RCC_APB2_TIM15  = 1UL << 16;
constexpr uint32_t RCC_APB2_TIM16  = 1UL << 17;
constexpr uint32_t RCC_APB2_TIM17  = 1UL << 18;
constexpr uint32_t RCC_APB2_SAI1   = 1UL << 21;
constexpr uint32_t RCC_APB2_SAI2   = 1UL << 22;
constexpr uint32_t RCC_APB2_USB    = 1UL << 24;
constexpr uint32_t RCC_APB2_GFXTIM = 1UL << 25;
constexpr uint32_t RCC_APB2_LTDC   = 1UL << 26;
constexpr uint32_t RCC_APB2_DSI    = 1UL << 27;

constexpr uint32_t RCC_APB3_SYSCFG   = 1UL << 1;
constexpr uint32_t RCC_APB3_SPI3     = 1UL << 5;
constexpr uint32_t RCC_APB3_LPUSART1 = 1UL << 6;
constexpr uint32_t RCC_APB3_I2C3     = 1UL << 7;
constexpr uint32_t RCC_APB3_LPTIM1   = 1UL << 11;
constexpr uint32_t RCC_APB3_LPTIM3   = 1UL << 12;
constexpr uint32_t RCC_APB3_LPTIM4   = 1UL << 13;
constexpr uint32_t RCC_APB3_OPAMP    = 1UL << 14;
constexpr uint32_t RCC_APB3_COMP     = 1UL << 15;
constexpr uint32_t RCC_APB3_VREF     = 1UL << 20;
constexpr uint32_t RCC_APB3_RTCAPB   = 1UL << 21;

constexpr uint32_t RCC_BDCR_LSIPREDIV    = 1UL << 28;
constexpr uint32_t RCC_BDCR_LSIRDY       = 1UL << 27;
constexpr uint32_t RCC_BDCR_LSION        = 1UL << 26;
constexpr uint32_t RCC_BDCR_LSCOSEL      = 1UL << 25;
constexpr uint32_t RCC_BDCR_LSCOEN       = 1UL << 24;
constexpr uint32_t RCC_BDCR_BDRST        = 1UL << 16;
constexpr uint32_t RCC_BDCR_RTCEN        = 1UL << 15;
constexpr uint32_t RCC_BDCR_LSEGFON      = 1UL << 12;
constexpr uint32_t RCC_BDCR_LSESYSRDY    = 1UL << 11;
constexpr uint32_t RCC_BDCR_RTCSEL_MASK  = 3UL << 8;
constexpr uint32_t RCC_BDCR_RTCSEL_NONE  = 0;
constexpr uint32_t RCC_BDCR_RTCSEL_LSE   = 1;
constexpr uint32_t RCC_BDCR_RTCSEL_LSI   = 2;
constexpr uint32_t RCC_BDCR_RTCSEL_HSE   = 3;
constexpr uint32_t RCC_BDCR_LSESYSEN     = 1UL << 7;
constexpr uint32_t RCC_BDCR_LSECSSD      = 1UL << 6;
constexpr uint32_t RCC_BDCR_LSECSSON     = 1UL << 5;
constexpr uint32_t RCC_BDCR_LSEDRV_MASK  = 3UL << 3;
constexpr uint32_t RCC_BDCR_LSEDRV_LOW   = 0;
constexpr uint32_t RCC_BDCR_LSEDRV_MEDL  = 1;
constexpr uint32_t RCC_BDCR_LSEDRV_MEDH  = 2;
constexpr uint32_t RCC_BDCR_LSEDRV_HIGH  = 3;
constexpr uint32_t RCC_BDCR_LSEBYP       = 1UL << 2;
constexpr uint32_t RCC_BDCR_LSERDY       = 1UL << 1;
constexpr uint32_t RCC_BDCR_LSEON        = 1UL;

constexpr uint32_t RCC_CSR_MSIKSRANGE_MASK = 0xFUL << 8;
constexpr uint32_t RCC_CSR_MSISSRANGE_MASK = 0xFUL << 12;
constexpr uint32_t RCC_CSR_RMVF            = 1UL << 23;
constexpr uint32_t RCC_CSR_OBLRSTF         = 1UL << 25;
constexpr uint32_t RCC_CSR_PINRSTF         = 1UL << 26;
constexpr uint32_t RCC_CSR_BORRSTF         = 1UL << 27;
constexpr uint32_t RCC_CSR_SFTRSTF         = 1UL << 28;
constexpr uint32_t RCC_CSR_IWDGRSTF        = 1UL << 29;
constexpr uint32_t RCC_CSR_WWDGRSTF        = 1UL << 30;
constexpr uint32_t RCC_CSR_LPWRRSTF        = 1UL << 31;

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
	volatile uint32_t BRR;
	volatile uint32_t HSLVR;
	volatile uint32_t SECCFGR;
} GPIO_REGS;

typedef struct
{
	volatile uint32_t RTSR1;
	volatile uint32_t FTSR1;
	volatile uint32_t SWIER1;
	volatile uint32_t RPR1;
	volatile uint32_t FPR1;
	volatile uint32_t SECCFGR1;
	volatile uint32_t PRIVCFGR1;
	volatile uint32_t RSVD[15];
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t CR4;
	volatile uint32_t LOCKR;
	volatile uint32_t RSVD2[3];
	volatile uint32_t IMR1;
	volatile uint32_t EMR1;
} EXTI_REGS;

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t BRR;
	volatile uint32_t GTPR;
	volatile uint32_t RTOR;
	volatile uint32_t RQR;
	volatile uint32_t ISR;
	volatile uint32_t ICR;
	volatile uint32_t RDR;
	volatile uint32_t TDR;
	volatile uint32_t PRESC;
	volatile uint32_t AUTOCR;
} USART_REGS;

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CFG1;
	volatile uint32_t CFG2;
	volatile uint32_t IER;
	volatile uint32_t SR;
	volatile uint32_t IFCR;
	volatile uint32_t AUTOCR;
	volatile uint32_t TXDR;
	volatile uint32_t RSVD[3];
	volatile uint32_t RXDR;
	volatile uint32_t RSVD2[3];
	volatile uint32_t CRCPOLY;
	volatile uint32_t TXCRC;
	volatile uint32_t RXCRC;
	volatile uint32_t UDRDR;
} SPI_REGS;

#define FLASH_BASE  0x4002'2000
#define PWR_BASE    0x4602'0800
#define RCC_BASE    0x4602'0C00
#define EXTI_BASE   0x4602'2000
#define GPIOA_BASE  0x4202'0000
#define GPIOB_BASE  0x4202'0400
#define GPIOC_BASE  0x4202'0800
#define GPIOD_BASE  0x4202'0C00
#define GPIOE_BASE  0x4202'1000
#define GPIOF_BASE  0x4202'1400
#define GPIOG_BASE  0x4202'1800
#define GPIOH_BASE  0x4202'1C00
#define GPIOI_BASE  0x4202'2000
#define GPIOJ_BASE  0x4202'2400
#define SPI1_BASE   0x4001'3000
#define SPI2_BASE   0x4000'3800
#define SPI3_BASE   0x4600'2000
#define USART1_BASE 0x4001'3800
#define USART2_BASE 0x4000'4400
#define USART3_BASE 0x4000'4800
#define USART6_BASE 0x4000'6400

#define FLASH  ((FLASH_REGS*)FLASH_BASE)
#define PWR    ((PWR_REGS*)PWR_BASE)
#define RCC    ((RCC_REGS*)RCC_BASE)
#define EXTI   ((EXTI_REGS*)EXTI_BASE)
#define GPIOA  ((GPIO_REGS*)GPIOA_BASE)
#define GPIOB  ((GPIO_REGS*)GPIOB_BASE)
#define GPIOC  ((GPIO_REGS*)GPIOC_BASE)
#define GPIOD  ((GPIO_REGS*)GPIOD_BASE)
#define GPIOE  ((GPIO_REGS*)GPIOE_BASE)
#define GPIOF  ((GPIO_REGS*)GPIOF_BASE)
#define GPIOG  ((GPIO_REGS*)GPIOG_BASE)
#define GPIOH  ((GPIO_REGS*)GPIOH_BASE)
#define GPIOI  ((GPIO_REGS*)GPIOI_BASE)
#define GPIOJ  ((GPIO_REGS*)GPIOJ_BASE)
#define SPI1   ((SPI_REGS*)SPI1_BASE)
#define SPI2   ((SPI_REGS*)SPI2_BASE)
#define SPI3   ((SPI_REGS*)SPI3_BASE)
#define USART1 ((USART_REGS*)USART1_BASE)
#define USART2 ((USART_REGS*)USART2_BASE)
#define USART3 ((USART_REGS*)USART3_BASE)
#define USART6 ((USART_REGS*)USART6_BASE)