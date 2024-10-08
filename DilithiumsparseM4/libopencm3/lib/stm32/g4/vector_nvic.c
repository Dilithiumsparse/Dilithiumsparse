/* This file is part of the libopencm3 project.
 *
 * It was generated by the irq2nvic_h script.
 *
 * This part needs to get included in the compilation unit where
 * blocking_handler gets defined due to the way #pragma works.
 */


/** @defgroup CM3_nvic_isrdecls_STM32G4 User interrupt service routines (ISR) defaults for STM32 G4 series
    @ingroup CM3_nvic_isrdecls

    @{*/

void wwdg_isr(void) __attribute__((weak, alias("blocking_handler")));
void pvd_isr(void) __attribute__((weak, alias("blocking_handler")));
void rtc_tamp_css_isr(void) __attribute__((weak, alias("blocking_handler")));
void rtc_wkup_isr(void) __attribute__((weak, alias("blocking_handler")));
void flash_isr(void) __attribute__((weak, alias("blocking_handler")));
void rcc_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti0_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti1_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti2_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti3_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti4_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel1_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel2_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel3_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel4_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel5_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel6_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel7_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc12_isr(void) __attribute__((weak, alias("blocking_handler")));
void usb_hp_isr(void) __attribute__((weak, alias("blocking_handler")));
void usb_lp_isr(void) __attribute__((weak, alias("blocking_handler")));
void fdcan1_it0_isr(void) __attribute__((weak, alias("blocking_handler")));
void fdcan1_it1_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti9_5_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim1_brk_tim15_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim1_up_tim16_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim1_trg_tim17_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim1_cc_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim2_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim3_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim4_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c1_ev_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c1_er_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c2_ev_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c2_er_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi1_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi2_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart1_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart2_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart3_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti15_10_isr(void) __attribute__((weak, alias("blocking_handler")));
void rtc_alarm_isr(void) __attribute__((weak, alias("blocking_handler")));
void usb_wakeup_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim8_brk_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim8_up_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim8_trg_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim8_cc_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc3_isr(void) __attribute__((weak, alias("blocking_handler")));
void fsmc_isr(void) __attribute__((weak, alias("blocking_handler")));
void lptim1_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim5_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi3_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart4_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart5_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim6_dac13under_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim7_dac24under_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel1_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel2_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel3_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel4_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel5_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc4_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc5_isr(void) __attribute__((weak, alias("blocking_handler")));
void ucpd1_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp123_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp456_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp7_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_master_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_tima_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_timb_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_timc_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_timd_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_time_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_fault_isr(void) __attribute__((weak, alias("blocking_handler")));
void hrtim_timf_isr(void) __attribute__((weak, alias("blocking_handler")));
void crs_isr(void) __attribute__((weak, alias("blocking_handler")));
void sai_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim20_brk_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim20_up_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim20_trg_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim20_cc_isr(void) __attribute__((weak, alias("blocking_handler")));
void fpu_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c4_ev_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c4_er_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi4_isr(void) __attribute__((weak, alias("blocking_handler")));
void aes_isr(void) __attribute__((weak, alias("blocking_handler")));
void fdcan2_it0_isr(void) __attribute__((weak, alias("blocking_handler")));
void fdcan2_it1_isr(void) __attribute__((weak, alias("blocking_handler")));
void fdcan3_it0_isr(void) __attribute__((weak, alias("blocking_handler")));
void fdcan3_it1_isr(void) __attribute__((weak, alias("blocking_handler")));
void rng_isr(void) __attribute__((weak, alias("blocking_handler")));
void lpuart_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c3_ev_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c3_er_isr(void) __attribute__((weak, alias("blocking_handler")));
void dmamux_ovr_isr(void) __attribute__((weak, alias("blocking_handler")));
void quadspi_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_channel8_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel6_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel7_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_channel8_isr(void) __attribute__((weak, alias("blocking_handler")));
void cordic_isr(void) __attribute__((weak, alias("blocking_handler")));
void fmac_isr(void) __attribute__((weak, alias("blocking_handler")));

/**@}*/

/* Initialization template for the interrupt vector table. This definition is
 * used by the startup code generator (vector.c) to set the initial values for
 * the interrupt handling routines to the chip family specific _isr weak
 * symbols. */

#define IRQ_HANDLERS \
    [NVIC_WWDG_IRQ] = wwdg_isr, \
    [NVIC_PVD_IRQ] = pvd_isr, \
    [NVIC_RTC_TAMP_CSS_IRQ] = rtc_tamp_css_isr, \
    [NVIC_RTC_WKUP_IRQ] = rtc_wkup_isr, \
    [NVIC_FLASH_IRQ] = flash_isr, \
    [NVIC_RCC_IRQ] = rcc_isr, \
    [NVIC_EXTI0_IRQ] = exti0_isr, \
    [NVIC_EXTI1_IRQ] = exti1_isr, \
    [NVIC_EXTI2_IRQ] = exti2_isr, \
    [NVIC_EXTI3_IRQ] = exti3_isr, \
    [NVIC_EXTI4_IRQ] = exti4_isr, \
    [NVIC_DMA1_CHANNEL1_IRQ] = dma1_channel1_isr, \
    [NVIC_DMA1_CHANNEL2_IRQ] = dma1_channel2_isr, \
    [NVIC_DMA1_CHANNEL3_IRQ] = dma1_channel3_isr, \
    [NVIC_DMA1_CHANNEL4_IRQ] = dma1_channel4_isr, \
    [NVIC_DMA1_CHANNEL5_IRQ] = dma1_channel5_isr, \
    [NVIC_DMA1_CHANNEL6_IRQ] = dma1_channel6_isr, \
    [NVIC_DMA1_CHANNEL7_IRQ] = dma1_channel7_isr, \
    [NVIC_ADC12_IRQ] = adc12_isr, \
    [NVIC_USB_HP_IRQ] = usb_hp_isr, \
    [NVIC_USB_LP_IRQ] = usb_lp_isr, \
    [NVIC_FDCAN1_IT0_IRQ] = fdcan1_it0_isr, \
    [NVIC_FDCAN1_IT1_IRQ] = fdcan1_it1_isr, \
    [NVIC_EXTI9_5_IRQ] = exti9_5_isr, \
    [NVIC_TIM1_BRK_TIM15_IRQ] = tim1_brk_tim15_isr, \
    [NVIC_TIM1_UP_TIM16_IRQ] = tim1_up_tim16_isr, \
    [NVIC_TIM1_TRG_TIM17_IRQ] = tim1_trg_tim17_isr, \
    [NVIC_TIM1_CC_IRQ] = tim1_cc_isr, \
    [NVIC_TIM2_IRQ] = tim2_isr, \
    [NVIC_TIM3_IRQ] = tim3_isr, \
    [NVIC_TIM4_IRQ] = tim4_isr, \
    [NVIC_I2C1_EV_IRQ] = i2c1_ev_isr, \
    [NVIC_I2C1_ER_IRQ] = i2c1_er_isr, \
    [NVIC_I2C2_EV_IRQ] = i2c2_ev_isr, \
    [NVIC_I2C2_ER_IRQ] = i2c2_er_isr, \
    [NVIC_SPI1_IRQ] = spi1_isr, \
    [NVIC_SPI2_IRQ] = spi2_isr, \
    [NVIC_USART1_IRQ] = usart1_isr, \
    [NVIC_USART2_IRQ] = usart2_isr, \
    [NVIC_USART3_IRQ] = usart3_isr, \
    [NVIC_EXTI15_10_IRQ] = exti15_10_isr, \
    [NVIC_RTC_ALARM_IRQ] = rtc_alarm_isr, \
    [NVIC_USB_WAKEUP_IRQ] = usb_wakeup_isr, \
    [NVIC_TIM8_BRK_IRQ] = tim8_brk_isr, \
    [NVIC_TIM8_UP_IRQ] = tim8_up_isr, \
    [NVIC_TIM8_TRG_IRQ] = tim8_trg_isr, \
    [NVIC_TIM8_CC_IRQ] = tim8_cc_isr, \
    [NVIC_ADC3_IRQ] = adc3_isr, \
    [NVIC_FSMC_IRQ] = fsmc_isr, \
    [NVIC_LPTIM1_IRQ] = lptim1_isr, \
    [NVIC_TIM5_IRQ] = tim5_isr, \
    [NVIC_SPI3_IRQ] = spi3_isr, \
    [NVIC_UART4_IRQ] = uart4_isr, \
    [NVIC_UART5_IRQ] = uart5_isr, \
    [NVIC_TIM6_DAC13UNDER_IRQ] = tim6_dac13under_isr, \
    [NVIC_TIM7_DAC24UNDER_IRQ] = tim7_dac24under_isr, \
    [NVIC_DMA2_CHANNEL1_IRQ] = dma2_channel1_isr, \
    [NVIC_DMA2_CHANNEL2_IRQ] = dma2_channel2_isr, \
    [NVIC_DMA2_CHANNEL3_IRQ] = dma2_channel3_isr, \
    [NVIC_DMA2_CHANNEL4_IRQ] = dma2_channel4_isr, \
    [NVIC_DMA2_CHANNEL5_IRQ] = dma2_channel5_isr, \
    [NVIC_ADC4_IRQ] = adc4_isr, \
    [NVIC_ADC5_IRQ] = adc5_isr, \
    [NVIC_UCPD1_IRQ] = ucpd1_isr, \
    [NVIC_COMP123_IRQ] = comp123_isr, \
    [NVIC_COMP456_IRQ] = comp456_isr, \
    [NVIC_COMP7_IRQ] = comp7_isr, \
    [NVIC_HRTIM_MASTER_IRQ] = hrtim_master_isr, \
    [NVIC_HRTIM_TIMA_IRQ] = hrtim_tima_isr, \
    [NVIC_HRTIM_TIMB_IRQ] = hrtim_timb_isr, \
    [NVIC_HRTIM_TIMC_IRQ] = hrtim_timc_isr, \
    [NVIC_HRTIM_TIMD_IRQ] = hrtim_timd_isr, \
    [NVIC_HRTIM_TIME_IRQ] = hrtim_time_isr, \
    [NVIC_HRTIM_FAULT_IRQ] = hrtim_fault_isr, \
    [NVIC_HRTIM_TIMF_IRQ] = hrtim_timf_isr, \
    [NVIC_CRS_IRQ] = crs_isr, \
    [NVIC_SAI_IRQ] = sai_isr, \
    [NVIC_TIM20_BRK_IRQ] = tim20_brk_isr, \
    [NVIC_TIM20_UP_IRQ] = tim20_up_isr, \
    [NVIC_TIM20_TRG_IRQ] = tim20_trg_isr, \
    [NVIC_TIM20_CC_IRQ] = tim20_cc_isr, \
    [NVIC_FPU_IRQ] = fpu_isr, \
    [NVIC_I2C4_EV_IRQ] = i2c4_ev_isr, \
    [NVIC_I2C4_ER_IRQ] = i2c4_er_isr, \
    [NVIC_SPI4_IRQ] = spi4_isr, \
    [NVIC_AES_IRQ] = aes_isr, \
    [NVIC_FDCAN2_IT0_IRQ] = fdcan2_it0_isr, \
    [NVIC_FDCAN2_IT1_IRQ] = fdcan2_it1_isr, \
    [NVIC_FDCAN3_IT0_IRQ] = fdcan3_it0_isr, \
    [NVIC_FDCAN3_IT1_IRQ] = fdcan3_it1_isr, \
    [NVIC_RNG_IRQ] = rng_isr, \
    [NVIC_LPUART_IRQ] = lpuart_isr, \
    [NVIC_I2C3_EV_IRQ] = i2c3_ev_isr, \
    [NVIC_I2C3_ER_IRQ] = i2c3_er_isr, \
    [NVIC_DMAMUX_OVR_IRQ] = dmamux_ovr_isr, \
    [NVIC_QUADSPI_IRQ] = quadspi_isr, \
    [NVIC_DMA1_CHANNEL8_IRQ] = dma1_channel8_isr, \
    [NVIC_DMA2_CHANNEL6_IRQ] = dma2_channel6_isr, \
    [NVIC_DMA2_CHANNEL7_IRQ] = dma2_channel7_isr, \
    [NVIC_DMA2_CHANNEL8_IRQ] = dma2_channel8_isr, \
    [NVIC_CORDIC_IRQ] = cordic_isr, \
    [NVIC_FMAC_IRQ] = fmac_isr
