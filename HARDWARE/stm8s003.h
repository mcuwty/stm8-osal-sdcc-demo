#ifndef __STM8S003_H
#define __STM8S003_H

/* -------------------- GPIO -------------------- */
#define GPIO_OFST_ODR			0x0000
#define GPIO_OFST_IDR			0x0001
#define GPIO_OFST_DDR			0x0002
#define GPIO_OFST_CR1			0x0003
#define GPIO_OFST_CR2			0x0004

#define GPIO_PORT_A				0x5000
#define GPIO_PORT_B				0x5005
#define GPIO_PORT_C				0x500A
#define GPIO_PORT_D				0x500F
#define GPIO_PORT_E 			0x5014
#define GPIO_PORT_F 			0x5019

#define PA_ODR					*(volatile unsigned char*)(GPIO_PORT_A+GPIO_OFST_ODR)
#define PA_IDR					*(volatile unsigned char*)(GPIO_PORT_A+GPIO_OFST_IDR)
#define PA_DDR					*(volatile unsigned char*)(GPIO_PORT_A+GPIO_OFST_DDR)
#define PA_CR1					*(volatile unsigned char*)(GPIO_PORT_A+GPIO_OFST_CR1)
#define PA_CR2					*(volatile unsigned char*)(GPIO_PORT_A+GPIO_OFST_CR2)

#define PB_ODR					*(volatile unsigned char*)(GPIO_PORT_B+GPIO_OFST_ODR)
#define PB_IDR					*(volatile unsigned char*)(GPIO_PORT_B+GPIO_OFST_IDR)
#define PB_DDR					*(volatile unsigned char*)(GPIO_PORT_B+GPIO_OFST_DDR)
#define PB_CR1					*(volatile unsigned char*)(GPIO_PORT_B+GPIO_OFST_CR1)
#define PB_CR2					*(volatile unsigned char*)(GPIO_PORT_B+GPIO_OFST_CR2)

#define PC_ODR					*(volatile unsigned char*)(GPIO_PORT_C+GPIO_OFST_ODR)
#define PC_IDR					*(volatile unsigned char*)(GPIO_PORT_C+GPIO_OFST_IDR)
#define PC_DDR					*(volatile unsigned char*)(GPIO_PORT_C+GPIO_OFST_DDR)
#define PC_CR1					*(volatile unsigned char*)(GPIO_PORT_C+GPIO_OFST_CR1)
#define PC_CR2					*(volatile unsigned char*)(GPIO_PORT_C+GPIO_OFST_CR2)

#define PD_ODR					*(volatile unsigned char*)(GPIO_PORT_D+GPIO_OFST_ODR)
#define PD_IDR					*(volatile unsigned char*)(GPIO_PORT_D+GPIO_OFST_IDR)
#define PD_DDR					*(volatile unsigned char*)(GPIO_PORT_D+GPIO_OFST_DDR)
#define PD_CR1					*(volatile unsigned char*)(GPIO_PORT_D+GPIO_OFST_CR1)
#define PD_CR2					*(volatile unsigned char*)(GPIO_PORT_D+GPIO_OFST_CR2)

#define PE_ODR					*(volatile unsigned char*)(GPIO_PORT_E+GPIO_OFST_ODR)
#define PE_IDR					*(volatile unsigned char*)(GPIO_PORT_E+GPIO_OFST_IDR)
#define PE_DDR					*(volatile unsigned char*)(GPIO_PORT_E+GPIO_OFST_DDR)
#define PE_CR1					*(volatile unsigned char*)(GPIO_PORT_E+GPIO_OFST_CR1)
#define PE_CR2					*(volatile unsigned char*)(GPIO_PORT_E+GPIO_OFST_CR2)

#define PF_ODR					*(volatile unsigned char*)(GPIO_PORT_F+GPIO_OFST_ODR)
#define PF_IDR					*(volatile unsigned char*)(GPIO_PORT_F+GPIO_OFST_IDR)
#define PF_DDR					*(volatile unsigned char*)(GPIO_PORT_F+GPIO_OFST_DDR)
#define PF_CR1					*(volatile unsigned char*)(GPIO_PORT_F+GPIO_OFST_CR1)
#define PF_CR2					*(volatile unsigned char*)(GPIO_PORT_F+GPIO_OFST_CR2)

/* -------------------- CLOCK -------------------- */
/** Internal Clock Control Register (RS=0x01) */
#define CLK_ICKR				*(volatile unsigned char*)0x50C0
/** External Clock Control Register (RS=0x00) */
#define CLK_ECKRR				*(volatile unsigned char*)0x50C1
/** Clock Master Status Register (RS=0xE1) */
#define CLK_CMSR				*(volatile unsigned char*)0x50C3
/** Clock Master Switch Register (RS=0xE1) */
#define CLK_SWR					*(volatile unsigned char*)0x50C4
/** Clock Switch Control Register (RS=0xXX) */
#define CLK_SWCR				*(volatile unsigned char*)0x50C5
/** Clock Divider Register (RS=0x18) */
#define CLK_CKDIVR				*(volatile unsigned char*)0x50C6
/** Peripheral Clock Gating Register 1 (RS=0xFF) */
#define	CLK_PCKENR1				*(volatile unsigned char*)0x50C7
/** Clock Security System Register (RS=0x00) */
#define CLK_CSSR				*(volatile unsigned char*)0x50C8
/** Configurable Clock Control Register (RS=0x00) */
#define CLK_CCOR				*(volatile unsigned char*)0x50C9
/** Peripheral Clock Gating Register 2 (RS=0xFF) */
#define CLK_PCKENR2				*(volatile unsigned char*)0x50CA
/** HSI Clock Calibration Trimming Register (RS=0x00) */
#define CLK_HSITRIMR			*(volatile unsigned char*)0x50CC
/** SWIM Clock Control Register (RS=0bXXXXXXX0) */
#define CLK_SWIMCCR				*(volatile unsigned char*)0x50CD

/* -------------------- WD -------------------- */


/* -------------------- UART -------------------- */
#define UART1_SR 				*(volatile unsigned char*)0x5230
#define UART1_DR 				*(volatile unsigned char*)0x5231
#define UART1_BRR1 				*(volatile unsigned char*)0x5232
#define UART1_BRR2 				*(volatile unsigned char*)0x5233
#define UART1_CR1 				*(volatile unsigned char*)0x5234
#define UART1_CR2 				*(volatile unsigned char*)0x5235
#define UART1_CR3				*(volatile unsigned char*)0x5236
#define UART1_CR4				*(volatile unsigned char*)0x5237
#define UART1_CR5				*(volatile unsigned char*)0x5238
#define UART1_GTR				*(volatile unsigned char*)0x5239
#define UART1_PSCR				*(volatile unsigned char*)0x523A

/* UART_CR1 bits */
#define UART_CR1_R8 			(1 << 7)
#define UART_CR1_T8 			(1 << 6)
#define UART_CR1_UARTD 			(1 << 5)
#define UART_CR1_M 				(1 << 4)
#define UART_CR1_WAKE 			(1 << 3)
#define UART_CR1_PCEN 			(1 << 2)
#define UART_CR1_PS 			(1 << 1)
#define UART_CR1_PIEN 			(1 << 0)

/* UART_CR2 bits */
#define UART_CR2_TIEN 			(1 << 7)
#define UART_CR2_TCIEN 			(1 << 6)
#define UART_CR2_RIEN 			(1 << 5)
#define UART_CR2_ILIEN 			(1 << 4)
#define UART_CR2_TEN 			(1 << 3)
#define UART_CR2_REN 			(1 << 2)
#define UART_CR2_RWU 			(1 << 1)
#define UART_CR2_SBK 			(1 << 0)

/* UART_CR3 bits */
#define UART_CR3_LINEN 			(1 << 6)
#define UART_CR3_STOP2 			(1 << 5)
#define UART_CR3_STOP1 			(1 << 4)
#define UART_CR3_CLKEN 			(1 << 3)
#define UART_CR3_CPOL 			(1 << 2)
#define UART_CR3_CPHA 			(1 << 1)
#define UART_CR3_LBCL 			(1 << 0)

/* UART_SR bits */
#define UART_SR_TXE 			(1 << 7)
#define UART_SR_TC 				(1 << 6)
#define UART_SR_RXNE 			(1 << 5)
#define UART_SR_IDLE 			(1 << 4)
#define UART_SR_OR 				(1 << 3)
#define UART_SR_NF 				(1 << 2)
#define UART_SR_FE 				(1 << 1)
#define UART_SR_PE 				(1 << 0)

/* ------------------- TIMERS ------------------- */
#define TIM1_CR1 				*(volatile unsigned char*)0x52B0
#define TIM1_CR2 				*(volatile unsigned char*)0x52B1
#define TIM1_SMCR 				*(volatile unsigned char*)0x52B2
#define TIM1_ETR 				*(volatile unsigned char*)0x52B3
#define TIM1_DER 				*(volatile unsigned char*)0x52B4
#define TIM1_IER 				*(volatile unsigned char*)0x52B5
#define TIM1_SR1 				*(volatile unsigned char*)0x52B6
#define TIM1_SR2 				*(volatile unsigned char*)0x52B7
#define TIM1_EGR 				*(volatile unsigned char*)0x52B8
#define TIM1_CCMR1 				*(volatile unsigned char*)0x52B9
#define TIM1_CCMR2 				*(volatile unsigned char*)0x52BA
#define TIM1_CCMR3 				*(volatile unsigned char*)0x52BB
#define TIM1_CCMR4 				*(volatile unsigned char*)0x52BC
#define TIM1_CCER1 				*(volatile unsigned char*)0x52BD
#define TIM1_CCER2 				*(volatile unsigned char*)0x52BE
#define TIM1_CNTRH 				*(volatile unsigned char*)0x52BF
#define TIM1_CNTRL 				*(volatile unsigned char*)0x52C0
#define TIM1_PSCRH 				*(volatile unsigned char*)0x52C1
#define TIM1_PSCRL 				*(volatile unsigned char*)0x52C2
#define TIM1_ARRH 				*(volatile unsigned char*)0x52C3
#define TIM1_ARRL 				*(volatile unsigned char*)0x52C4
#define TIM1_RCR 				*(volatile unsigned char*)0x52C5
#define TIM1_CCR1H 				*(volatile unsigned char*)0x52C6
#define TIM1_CCR1L 				*(volatile unsigned char*)0x52C7
#define TIM1_CCR2H 				*(volatile unsigned char*)0x52C8
#define TIM1_CCR2L 				*(volatile unsigned char*)0x52C9
#define TIM1_CCR3H 				*(volatile unsigned char*)0x52CA
#define TIM1_CCR3L 				*(volatile unsigned char*)0x52CB
#define TIM1_CCR4H 				*(volatile unsigned char*)0x52CC
#define TIM1_CCR4L 				*(volatile unsigned char*)0x52CD
#define TIM1_BKR 				*(volatile unsigned char*)0x52CE
#define TIM1_DTR 				*(volatile unsigned char*)0x52CF
#define TIM1_OISR 				*(volatile unsigned char*)0x52D0
#define TIM1_DCR1 				*(volatile unsigned char*)0x52D1
#define TIM1_DCR2 				*(volatile unsigned char*)0x52D2
#define TIM1_DMA1R 				*(volatile unsigned char*)0x52D3

#define TIM2_CR1 				*(volatile unsigned char*)0x5300
#define TIM2_IER 				*(volatile unsigned char*)0x5303
#define TIM2_SR1 				*(volatile unsigned char*)0x5304
#define TIM2_SR2 				*(volatile unsigned char*)0x5305
#define TIM2_EGR 				*(volatile unsigned char*)0x5306
#define TIM2_CCMR1 				*(volatile unsigned char*)0x5307
#define TIM2_CCMR2 				*(volatile unsigned char*)0x5308
#define TIM2_CCMR3 				*(volatile unsigned char*)0x5309
#define TIM2_CCER1 				*(volatile unsigned char*)0x530A
#define TIM2_CCER2 				*(volatile unsigned char*)0x530B
#define TIM2_CNTRH 				*(volatile unsigned char*)0x530C
#define TIM2_CNTRL 				*(volatile unsigned char*)0x530D
#define TIM2_PSCR 				*(volatile unsigned char*)0x530E
#define TIM2_ARRH 				*(volatile unsigned char*)0x530F
#define TIM2_ARRL 				*(volatile unsigned char*)0x5310
#define TIM2_CCR1H 				*(volatile unsigned char*)0x5311
#define TIM2_CCR1L 				*(volatile unsigned char*)0x5312
#define TIM2_CCR2H 				*(volatile unsigned char*)0x5313
#define TIM2_CCR2L 				*(volatile unsigned char*)0x5314
#define TIM2_CCR3H 				*(volatile unsigned char*)0x5315
#define TIM2_CCR3L 				*(volatile unsigned char*)0x5316

/* TIM_IER bits */
#define TIM_IER_BIE 			(1 << 7)
#define TIM_IER_TIE 			(1 << 6)
#define TIM_IER_COMIE 			(1 << 5)
#define TIM_IER_CC4IE 			(1 << 4)
#define TIM_IER_CC3IE 			(1 << 3)
#define TIM_IER_CC2IE 			(1 << 2)
#define TIM_IER_CC1IE 			(1 << 1)
#define TIM_IER_UIE 			(1 << 0)

/* TIM_CR1 bits */
#define TIM_CR1_APRE 			(1 << 7)
#define TIM_CR1_CMSH 			(1 << 6)
#define TIM_CR1_CMSL 			(1 << 5)
#define TIM_CR1_DIR 			(1 << 4)
#define TIM_CR1_OPM 			(1 << 3)
#define TIM_CR1_URS 			(1 << 2)
#define TIM_CR1_UDIS 			(1 << 1)
#define TIM_CR1_CEN 			(1 << 0)

/* TIM_SR1 bits */
#define TIM_SR1_BIF 			(1 << 7)
#define TIM_SR1_TIF 			(1 << 6)
#define TIM_SR1_COMIF 			(1 << 5)
#define TIM_SR1_CC4IF 			(1 << 4)
#define TIM_SR1_CC3IF 			(1 << 3)
#define TIM_SR1_CC2IF 			(1 << 2)
#define TIM_SR1_CC1IF 			(1 << 1)
#define TIM_SR1_UIF 			(1 << 0)

#endif
