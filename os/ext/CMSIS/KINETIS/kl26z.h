/*
 * Copyright (C) 2013-2014 Fabio Utzig, http://fabioutzig.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _KL26Z_H_
#define _KL26Z_H_

/*
 * ==============================================================
 * ---------- Interrupt Number Definition -----------------------
 * ==============================================================
 */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ****************/
  Reset_IRQn                    = -15,
  NonMaskableInt_IRQn           = -14,
  HardFault_IRQn                = -13,
  SVCall_IRQn                   = -5,
  PendSV_IRQn                   = -2,
  SysTick_IRQn                  = -1,

/******  KL2x Specific Interrupt Numbers ***********************/
  DMA0_IRQn                     = 0,
  DMA1_IRQn                     = 1,
  DMA2_IRQn                     = 2,
  DMA3_IRQn                     = 3,
  Reserved0_IRQn                = 4,
  FTFA_IRQn                     = 5,
  PMC_IRQn                      = 6,
  LLWU_IRQn                     = 7,
  I2C0_IRQn                     = 8,
  I2C1_IRQn                     = 9,
  SPI0_IRQn                     = 10,
  SPI1_IRQn                     = 11,
  UART0_IRQn                    = 12,
  UART1_IRQn                    = 13,
  UART2_IRQn                    = 14,
  ADC0_IRQn                     = 15,
  CMP0_IRQn                     = 16,
  TPM0_IRQn                     = 17,
  TPM1_IRQn                     = 18,
  TPM2_IRQn                     = 19,
  RTC0_IRQn                     = 20,
  RTC1_IRQn                     = 21,
  PIT_IRQn                      = 22,
  I2S0_IRQn                     = 23,
  USB_OTG_IRQn                  = 24,
  DAC0_IRQn                     = 25,
  TSI0_IRQn                     = 26,
  MCG_IRQn                      = 27,
  LPTMR0_IRQn                   = 28,
  Reserved2_IRQn                = 29,
  PINA_IRQn                     = 30,
  PINCD_IRQn                    = 31,
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

#include "kl2xz.h"

typedef struct
{
  __IO uint8_t  C1;
  __IO uint8_t  C2;
  __IO uint8_t  C3;
  __IO uint8_t  C4;
  __IO uint8_t  C5;
  __IO uint8_t  C6;
  __IO uint8_t  S;
       uint8_t  RESERVED0[1];
  __IO uint8_t  SC;
       uint8_t  RESERVED1[1];
  __IO uint8_t  ATCVH;
  __IO uint8_t  ATCVL;
  __IO uint8_t  C7;
  __IO uint8_t  C8;
  __IO uint8_t  C9;
  __IO uint8_t  C10;
} MCG_TypeDef;

typedef struct
{
  __IO uint32_t SC;
  __IO uint32_t CNT;
  __IO uint32_t MOD;
  struct {                      // Channels
    __IO uint32_t SC;
    __IO uint32_t V;
  } C[6];
       uint32_t RESERVED0[5];
  __IO uint32_t STATUS;
       uint32_t RESERVED1[12];
  __IO uint32_t CONF;
} TPM_TypeDef;

typedef struct
{
  __IO uint32_t GENCS;
  __IO uint32_t DATA;
  __IO uint32_t TSHD;
} TSI_TypeDef;

typedef struct
{
  __IO uint8_t  S;
  __IO uint8_t  BR;
  __IO uint8_t  C2;
  __IO uint8_t  C1;
  __IO uint8_t  ML;
  __IO uint8_t  MH;
  __IO uint8_t  DL;
  __IO uint8_t  DH;
       uint8_t  RESERVED0[2];
  __IO uint8_t  CI;
  __IO uint8_t  C3;
} SPI_TypeDef;

typedef struct
{
  __IO uint8_t  A1;
  __IO uint8_t  F;
  __IO uint8_t  C1;
  __IO uint8_t  S1;
  __IO uint8_t  D;
  __IO uint8_t  C2;
  __IO uint8_t  FLT;
  __IO uint8_t  RA;
  __IO uint8_t  SMB;
  __IO uint8_t  A2;
  __IO uint8_t  SLTH;
  __IO uint8_t  SLTL;
} I2C_TypeDef;

typedef struct
{
  __IO uint8_t  BDH;
  __IO uint8_t  BDL;
  __IO uint8_t  C1;
  __IO uint8_t  C2;
  __IO uint8_t  S1;
  __IO uint8_t  S2;
  __IO uint8_t  C3;
  __IO uint8_t  D;
  __IO uint8_t  MA1;
  __IO uint8_t  MA2;
  __IO uint8_t  C4;
  __IO uint8_t  C5;
} UART_TypeDef;

typedef struct {
  __I  uint8_t  PERID;               // 0x00
       uint8_t  RESERVED0[3];
  __I  uint8_t  IDCOMP;              // 0x04
       uint8_t  RESERVED1[3];
  __I  uint8_t  REV;                 // 0x08
       uint8_t  RESERVED2[3];
  __I  uint8_t  ADDINFO;             // 0x0C
       uint8_t  RESERVED3[3];
  __IO uint8_t  OTGISTAT;            // 0x10
       uint8_t  RESERVED4[3];
  __IO uint8_t  OTGICR;              // 0x14
       uint8_t  RESERVED5[3];
  __IO uint8_t  OTGSTAT;             // 0x18
       uint8_t  RESERVED6[3];
  __IO uint8_t  OTGCTL;              // 0x1C
       uint8_t  RESERVED7[99];
  __IO uint8_t  ISTAT;               // 0x80
       uint8_t  RESERVED8[3];
  __IO uint8_t  INTEN;               // 0x84
       uint8_t  RESERVED9[3];
  __IO uint8_t  ERRSTAT;             // 0x88
       uint8_t  RESERVED10[3];
  __IO uint8_t  ERREN;               // 0x8C
       uint8_t  RESERVED11[3];
  __I  uint8_t  STAT;                // 0x90
       uint8_t  RESERVED12[3];
  __IO uint8_t  CTL;                 // 0x94
       uint8_t  RESERVED13[3];
  __IO uint8_t  ADDR;                // 0x98
       uint8_t  RESERVED14[3];
  __IO uint8_t  BDTPAGE1;            // 0x9C
       uint8_t  RESERVED15[3];
  __IO uint8_t  FRMNUML;             // 0xA0
       uint8_t  RESERVED16[3];
  __IO uint8_t  FRMNUMH;             // 0xA4
       uint8_t  RESERVED17[3];
  __IO uint8_t  TOKEN;               // 0xA8
       uint8_t  RESERVED18[3];
  __IO uint8_t  SOFTHLD;             // 0xAC
       uint8_t  RESERVED19[3];
  __IO uint8_t  BDTPAGE2;            // 0xB0
       uint8_t  RESERVED20[3];
  __IO uint8_t  BDTPAGE3;            // 0xB4
       uint8_t  RESERVED21[11];
  struct {
    __IO uint8_t  V;                 // 0xC0
         uint8_t  RESERVED[3];
  } ENDPT[16];
  __IO uint8_t  USBCTRL;             // 0x100
       uint8_t  RESERVED22[3];
  __I  uint8_t  OBSERVE;             // 0x104
       uint8_t  RESERVED23[3];
  __IO uint8_t  CONTROL;             // 0x108
       uint8_t  RESERVED24[3];
  __IO uint8_t  USBTRC0;             // 0x10C
       uint8_t  RESERVED25[7];
  __IO uint8_t  USBFRMADJUST;        // 0x114
} USBOTG_TypeDef;

/****************************************************************/
/*                  Peripheral memory map                       */
/****************************************************************/
#define DMA_BASE                ((uint32_t)0x40008100)
#define DMAMUX_BASE             ((uint32_t)0x40021000)
#define I2S0_BASE               ((uint32_t)0x4002F000) // TODO: registers not implemented
#define PIT_BASE                ((uint32_t)0x40037000) // TODO: registers not implemented
#define TPM0_BASE               ((uint32_t)0x40038000)
#define TPM1_BASE               ((uint32_t)0x40039000)
#define TPM2_BASE               ((uint32_t)0x4003A000)
#define ADC0_BASE               ((uint32_t)0x4003B000)
#define RTC_BASE                ((uint32_t)0x4003D000) // TODO: registers not implemented
#define DAC0_BASE               ((uint32_t)0x4003F000) // TODO: registers not implemented
#define LPTMR0_BASE             ((uint32_t)0x40040000)
#define TSI0_BASE               ((uint32_t)0x40045000)
#define SIM_BASE                ((uint32_t)0x40047000)
#define PORTA_BASE              ((uint32_t)0x40049000)
#define PORTB_BASE              ((uint32_t)0x4004A000)
#define PORTC_BASE              ((uint32_t)0x4004B000)
#define PORTD_BASE              ((uint32_t)0x4004C000)
#define PORTE_BASE              ((uint32_t)0x4004D000)
#define MCG_BASE                ((uint32_t)0x40064000)
#define OSC0_BASE               ((uint32_t)0x40065000)
#define I2C0_BASE               ((uint32_t)0x40066000)
#define I2C1_BASE               ((uint32_t)0x40067000)
#define UART0_BASE              ((uint32_t)0x4006A000)
#define UART1_BASE              ((uint32_t)0x4006B000)
#define UART2_BASE              ((uint32_t)0x4006C000)
#define USBOTG_BASE             ((uint32_t)0x40072000)
#define CMP_DAC_BASE            ((uint32_t)0x40073000) // TODO: registers not implemented
#define SPI0_BASE               ((uint32_t)0x40076000)
#define SPI1_BASE               ((uint32_t)0x40077000)
#define LLWU_BASE               ((uint32_t)0x4007C000)
#define PMC_BASE                ((uint32_t)0x4007D000)
#define SMC_BASE                ((uint32_t)0x4007E000) // TODO: registers not implemented
#define RCM_BASE                ((uint32_t)0x4007F000) // TODO: registers not implemented
#define GPIOA_BASE              ((uint32_t)0x400FF000)
#define GPIOB_BASE              ((uint32_t)0x400FF040)
#define GPIOC_BASE              ((uint32_t)0x400FF080)
#define GPIOD_BASE              ((uint32_t)0x400FF0C0)
#define GPIOE_BASE              ((uint32_t)0x400FF100)

/****************************************************************/
/*                 Peripheral declaration                       */
/****************************************************************/
#define DMA                     ((DMA_TypeDef *)     DMA_BASE)
#define DMAMUX                  ((DMAMUX_TypeDef *)  DMAMUX_BASE)
#define TPM0                    ((TPM_TypeDef *)     TPM0_BASE)
#define TPM1                    ((TPM_TypeDef *)     TPM1_BASE)
#define TPM2                    ((TPM_TypeDef *)     TPM2_BASE)
#define ADC0                    ((ADC_TypeDef *)     ADC0_BASE)
#define LPTMR0                  ((LPTMR_TypeDef *)   LPTMR0_BASE)
#define TSI0                    ((TSI_TypeDef *)     TSI0_BASE)
#define SIM                     ((SIM_TypeDef  *)    SIM_BASE)
#define LLWU                    ((LLWU_TypeDef  *)   LLWU_BASE)
#define PMC                     ((PMC_TypeDef  *)    PMC_BASE)
#define PORTA                   ((PORT_TypeDef  *)   PORTA_BASE)
#define PORTB                   ((PORT_TypeDef  *)   PORTB_BASE)
#define PORTC                   ((PORT_TypeDef  *)   PORTC_BASE)
#define PORTD                   ((PORT_TypeDef  *)   PORTD_BASE)
#define PORTE                   ((PORT_TypeDef  *)   PORTE_BASE)
#define USBOTG                  ((USBOTG_TypeDef *)  USBOTG_BASE)
#define MCG                     ((MCG_TypeDef  *)    MCG_BASE)
#define OSC0                    ((OSC_TypeDef  *)    OSC0_BASE)
#define SPI0                    ((SPI_TypeDef *)     SPI0_BASE)
#define SPI1                    ((SPI_TypeDef *)     SPI1_BASE)
#define I2C0                    ((I2C_TypeDef *)     I2C0_BASE)
#define I2C1                    ((I2C_TypeDef *)     I2C1_BASE)
#define UART0                   ((UART_TypeDef *)    UART0_BASE)
#define UART1                   ((UART_TypeDef *)    UART1_BASE)
#define UART2                   ((UART_TypeDef *)    UART2_BASE)
#define GPIOA                   ((GPIO_TypeDef  *)   GPIOA_BASE)
#define GPIOB                   ((GPIO_TypeDef  *)   GPIOB_BASE)
#define GPIOC                   ((GPIO_TypeDef  *)   GPIOC_BASE)
#define GPIOD                   ((GPIO_TypeDef  *)   GPIOD_BASE)
#define GPIOE                   ((GPIO_TypeDef  *)   GPIOE_BASE)

/****************************************************************/
/*           Peripheral Registers Bits Definition               */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*             System Integration Module (SIM)                  */
/*                                                              */
/****************************************************************/
/*********  Bits definition for SIM_SOPT1 register  *************/
#define SIM_SOPT1_USBREGEN           ((uint32_t)0x80000000)    /*!< USB voltage regulator enable */
#define SIM_SOPT1_USBSSTBY           ((uint32_t)0x40000000)    /*!< USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes */
#define SIM_SOPT1_USBVSTBY           ((uint32_t)0x20000000)    /*!< USB voltage regulator in standby mode during VLPR and VLPW modes */
#define SIM_SOPT1_OSC32KSEL_SHIFT    18                                                                            			 /*!< 32K oscillator clock select (shift) */
#define SIM_SOPT1_OSC32KSEL_MASK     ((uint32_t)((uint32_t)0x03 << SIM_SOPT1_OSC32KSEL_SHIFT))                          	 /*!< 32K oscillator clock select (mask) */
#define SIM_SOPT1_OSC32KSEL(x)       ((uint32_t)(((uint32_t)(x) << SIM_SOPT1_OSC32KSEL_SHIFT) & SIM_SOPT1_OSC32KSEL_MASK))  /*!< 32K oscillator clock select */

/*******  Bits definition for SIM_SOPT1CFG register  ************/
#define SIM_SOPT1CFG_USSWE           ((uint32_t)0x04000000)    /*!< USB voltage regulator stop standby write enable */
#define SIM_SOPT1CFG_UVSWE           ((uint32_t)0x02000000)    /*!< USB voltage regulator VLP standby write enable */
#define SIM_SOPT1CFG_URWE            ((uint32_t)0x01000000)    /*!< USB voltage regulator voltage regulator write enable */

/*******  Bits definition for SIM_SOPT2 register  ************/
#define SIM_SOPT2_UART0SRC_SHIFT     26                                                                                   /*!< UART0 clock source select (shift) */
#define SIM_SOPT2_UART0SRC_MASK      ((uint32_t)((uint32_t)0x03 << SIM_SOPT2_UART0SRC_SHIFT))                             /*!< UART0 clock source select (mask) */
#define SIM_SOPT2_UART0SRC(x)        ((uint32_t)(((uint32_t)(x) << SIM_SOPT2_UART0SRC_SHIFT) & SIM_SOPT2_UART0SRC_MASK))  /*!< UART0 clock source select */
#define SIM_SOPT2_TPMSRC_SHIFT       24                                                                               /*!< TPM clock source select (shift) */
#define SIM_SOPT2_TPMSRC_MASK        ((uint32_t)((uint32_t)0x03 << SIM_SOPT2_TPMSRC_SHIFT))                           /*!< TPM clock source select (mask) */
#define SIM_SOPT2_TPMSRC(x)          ((uint32_t)(((uint32_t)(x) << SIM_SOPT2_TPMSRC_SHIFT) & SIM_SOPT2_TPMSRC_MASK))  /*!< TPM clock source select */
#define SIM_SOPT2_USBSRC             ((uint32_t)0x00040000)    /*!< USB clock source select */
#define SIM_SOPT2_PLLFLLSEL          ((uint32_t)0x00010000)    /*!< PLL/FLL clock select */
#define SIM_SOPT2_CLKOUTSEL_SHIFT    5                                                                                      /*!< CLKOUT select (shift) */
#define SIM_SOPT2_CLKOUTSEL_MASK     ((uint32_t)((uint32_t)0x07 << SIM_SOPT2_CLKOUTSEL_SHIFT))                              /*!< CLKOUT select (mask) */
#define SIM_SOPT2_CLKOUTSEL(x)       ((uint32_t)(((uint32_t)(x) << SIM_SOPT2_CLKOUTSEL_SHIFT) & SIM_SOPT2_CLKOUTSEL_MASK))  /*!< CLKOUT select */
#define SIM_SOPT2_RTCCLKOUTSEL       ((uint32_t)0x00000010)    /*!< RTC clock out select */

/*******  Bits definition for SIM_SOPT4 register  ************/
// TODO: missing: SOPT4, SOPT5, SOPT7, SDID

/*******  Bits definition for SIM_SCGC4 register  ************/
#define SIM_SCGC4_SPI1               ((uint32_t)0x00800000)    /*!< SPI1 Clock Gate Control */
#define SIM_SCGC4_SPI0               ((uint32_t)0x00400000)    /*!< SPI0 Clock Gate Control */
#define SIM_SCGC4_CMP                ((uint32_t)0x00080000)    /*!< Comparator Clock Gate Control */
#define SIM_SCGC4_USBOTG             ((uint32_t)0x00040000)    /*!< USB Clock Gate Control */
#define SIM_SCGC4_UART2              ((uint32_t)0x00001000)    /*!< UART2 Clock Gate Control */
#define SIM_SCGC4_UART1              ((uint32_t)0x00000800)    /*!< UART1 Clock Gate Control */
#define SIM_SCGC4_UART0              ((uint32_t)0x00000400)    /*!< UART0 Clock Gate Control */
#define SIM_SCGC4_I2C1               ((uint32_t)0x00000080)    /*!< I2C1 Clock Gate Control */
#define SIM_SCGC4_I2C0               ((uint32_t)0x00000040)    /*!< I2C0 Clock Gate Control */

/*******  Bits definition for SIM_SCGC5 register  ************/
#define SIM_SCGC5_PORTE              ((uint32_t)0x00002000)    /*!< Port E Clock Gate Control */
#define SIM_SCGC5_PORTD              ((uint32_t)0x00001000)    /*!< Port D Clock Gate Control */
#define SIM_SCGC5_PORTC              ((uint32_t)0x00000800)    /*!< Port C Clock Gate Control */
#define SIM_SCGC5_PORTB              ((uint32_t)0x00000400)    /*!< Port B Clock Gate Control */
#define SIM_SCGC5_PORTA              ((uint32_t)0x00000200)    /*!< Port A Clock Gate Control */
#define SIM_SCGC5_TSI                ((uint32_t)0x00000020)    /*!< TSI Access Control */
#define SIM_SCGC5_LPTMR              ((uint32_t)0x00000001)    /*!< Low Power Timer Access Control */

/*******  Bits definition for SIM_SCGC6 register  ************/
#define SIM_SCGC6_DAC0               ((uint32_t)0x80000000)    /*!< DAC0 Clock Gate Control */
#define SIM_SCGC6_RTC                ((uint32_t)0x20000000)    /*!< RTC Access Control */
#define SIM_SCGC6_ADC0               ((uint32_t)0x08000000)    /*!< ADC0 Clock Gate Control */
#define SIM_SCGC6_TPM2               ((uint32_t)0x04000000)    /*!< TPM2 Clock Gate Control */
#define SIM_SCGC6_TPM1               ((uint32_t)0x02000000)    /*!< TPM1 Clock Gate Control */
#define SIM_SCGC6_TPM0               ((uint32_t)0x01000000)    /*!< TPM0 Clock Gate Control */
#define SIM_SCGC6_PIT                ((uint32_t)0x00800000)    /*!< PIT Clock Gate Control */
#define SIM_SCGC6_I2S                ((uint32_t)0x00008000)    /*!< I2S0 Clock Gate Control */
#define SIM_SCGC6_DMAMUX             ((uint32_t)0x00000002)    /*!< DMA Mux Clock Gate Control */
#define SIM_SCGC6_FTF                ((uint32_t)0x00000001)    /*!< Flash Memory Clock Gate Control */

/*******  Bits definition for SIM_SCGC6 register  ************/
#define SIM_SCGC7_DMA                ((uint32_t)0x00000100)    /*!< DMA Clock Gate Control */

/******  Bits definition for SIM_CLKDIV1 register  ***********/
#define SIM_CLKDIV1_OUTDIV1_SHIFT    28                                                                            			 /*!< Clock 1 output divider value (shift) */
#define SIM_CLKDIV1_OUTDIV1_MASK     ((uint32_t)((uint32_t)0x0F << SIM_CLKDIV1_OUTDIV1_SHIFT))                          	 /*!< Clock 1 output divider value (mask) */
#define SIM_CLKDIV1_OUTDIV1(x)       ((uint32_t)(((uint32_t)(x) << SIM_CLKDIV1_OUTDIV1_SHIFT) & SIM_CLKDIV1_OUTDIV1_MASK))  /*!< Clock 1 output divider value */
#define SIM_CLKDIV1_OUTDIV4_SHIFT    16                                                                            			 /*!< Clock 4 output divider value (shift) */
#define SIM_CLKDIV1_OUTDIV4_MASK     ((uint32_t)((uint32_t)0x07 << SIM_CLKDIV1_OUTDIV4_SHIFT))                          	 /*!< Clock 4 output divider value (mask) */
#define SIM_CLKDIV1_OUTDIV4(x)       ((uint32_t)(((uint32_t)(x) << SIM_CLKDIV1_OUTDIV4_SHIFT) & SIM_CLKDIV1_OUTDIV4_MASK))  /*!< Clock 4 output divider value */

// TODO: Missing: FCFG1, FCFG2, UIDMH, UIDML, UIDL, COPC, SRVCOP

/****************************************************************/
/*                                                              */
/*              Low-Leakage Wakeup Unit (LLWU)                  */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*           Port Control and interrupts (PORT)                 */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*                   Oscillator (OSC)                           */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*                 Direct Memory Access (DMA)                   */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*         Direct Memory Access Multiplexer (DMAMUX)            */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*              Analog-to-Digital Converter (ADC)               */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*                   Low-Power Timer (LPTMR)                    */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*                  Touch Sensing Input (TSI)                   */
/*                                                              */
/****************************************************************/
/**********  Bits definition for TSIx_GENCS register  ***********/
#define TSIx_GENCS_OUTRGF           ((uint32_t)((uint32_t)1 << 31))  /*!< Out of Range Flag */
#define TSIx_GENCS_ESOR             ((uint32_t)((uint32_t)1 << 28))  /*!< End-of-scan/Out-of-Range Interrupt Selection */
#define TSIx_GENCS_MODE_SHIFT       24                                                                                 /*!< TSI analog modes setup and status bits (shift) */
#define TSIx_GENCS_MODE_MASK        ((uint32_t)((uint32_t)0x0F << TSIx_GENCS_MODE_SHIFT))                            /*!< TSI analog modes setup and status bits (mask) */
#define TSIx_GENCS_MODE(x)          ((uint32_t)(((uint32_t)(x) << TSIx_GENCS_MODE_SHIFT) & TSIx_GENCS_MODE_MASK))  /*!< TSI analog modes setup and status bits */
#define TSIx_GENCS_REFCHRG_SHIFT    21                                                                                       /*!< Reference oscillator charge/discharge current (shift) */
#define TSIx_GENCS_REFCHRG_MASK     ((uint32_t)((uint32_t)0x07 << TSIx_GENCS_REFCHRG_SHIFT))                               /*!< Reference oscillator charge/discharge current (mask) */
#define TSIx_GENCS_REFCHRG(x)       ((uint32_t)(((uint32_t)(x) << TSIx_GENCS_REFCHRG_SHIFT) & TSIx_GENCS_REFCHRG_MASK))  /*!< Reference oscillator charge/discharge current */
#define TSIx_GENCS_DVOLT_SHIFT      19                                                                                   /*!< Oscillator voltage rails (shift) */
#define TSIx_GENCS_DVOLT_MASK       ((uint32_t)((uint32_t)0x03 << TSIx_GENCS_DVOLT_SHIFT))                             /*!< Oscillator voltage rails (mask) */
#define TSIx_GENCS_DVOLT(x)         ((uint32_t)(((uint32_t)(x) << TSIx_GENCS_DVOLT_SHIFT) & TSIx_GENCS_DVOLT_MASK))  /*!< Oscillator voltage rails */
#define TSIx_GENCS_EXTCHRG_SHIFT    16                                                                                       /*!< Electrode oscillator charge/discharge current (shift) */
#define TSIx_GENCS_EXTCHRG_MASK     ((uint32_t)((uint32_t)0x07 << TSIx_GENCS_EXTCHRG_SHIFT))                               /*!< Electrode oscillator charge/discharge current (mask) */
#define TSIx_GENCS_EXTCHRG(x)       ((uint32_t)(((uint32_t)(x) << TSIx_GENCS_EXTCHRG_SHIFT) & TSIx_GENCS_EXTCHRG_MASK))  /*!< Electrode oscillator charge/discharge current */
#define TSIx_GENCS_PS_SHIFT         13                                                                             /*!< Electrode oscillator prescaler (shift) */
#define TSIx_GENCS_PS_MASK          ((uint32_t)((uint32_t)0x07 << TSIx_GENCS_PS_SHIFT))                          /*!< Electrode oscillator prescaler (mask) */
#define TSIx_GENCS_PS(x)            ((uint32_t)(((uint32_t)(x) << TSIx_GENCS_PS_SHIFT) & TSIx_GENCS_PS_MASK))  /*!< Electrode oscillator prescaler */
#define TSIx_GENCS_NSCN_SHIFT       8                                                                                  /*!< Number of scans per electrode minus 1 (shift) */
#define TSIx_GENCS_NSCN_MASK        ((uint32_t)((uint32_t)0x1F << TSIx_GENCS_NSCN_SHIFT))                            /*!< Number of scans per electrode minus 1 (mask) */
#define TSIx_GENCS_NSCN(x)          ((uint32_t)(((uint32_t)(x) << TSIx_GENCS_NSCN_SHIFT) & TSIx_GENCS_NSCN_MASK))  /*!< Number of scans per electrode minus 1 */
#define TSIx_GENCS_TSIEN            ((uint32_t)((uint32_t)1 << 7))  /*!< TSI Module Enable */
#define TSIx_GENCS_TSIIEN           ((uint32_t)((uint32_t)1 << 6))  /*!< TSI Interrupt Enable */
#define TSIx_GENCS_STPE             ((uint32_t)((uint32_t)1 << 5))  /*!< TSI STOP Enable */
#define TSIx_GENCS_STM              ((uint32_t)((uint32_t)1 << 4))  /*!< Scan Trigger Mode (0=software; 1=hardware) */
#define TSIx_GENCS_SCNIP            ((uint32_t)((uint32_t)1 << 3))  /*!< Scan in Progress Status */
#define TSIx_GENCS_EOSF             ((uint32_t)((uint32_t)1 << 2))  /*!< End of Scan Flag */
#define TSIx_GENCS_CURSW            ((uint32_t)((uint32_t)1 << 1))  /*!< Swap electrode and reference current sources */

/**********  Bits definition for TSIx_DATA register  ************/
#define TSIx_DATA_TSICH_SHIFT       28                                                                             /*!< Specify channel to be measured (shift) */
#define TSIx_DATA_TSICH_MASK        ((uint32_t)((uint32_t)0x0F << TSIx_DATA_TSICH_SHIFT))                          /*!< Specify channel to be measured (mask) */
#define TSIx_DATA_TSICH(x)          ((uint32_t)(((uint32_t)(x) << TSIx_DATA_TSICH_SHIFT) & TSIx_DATA_TSICH_MASK))  /*!< Specify channel to be measured */
#define TSIx_DATA_DMAEN             ((uint32_t)((uint32_t)1 << 23))  /*!< DMA Transfer Enabled */
#define TSIx_DATA_SWTS              ((uint32_t)((uint32_t)1 << 22))  /*!< Software Trigger Start */
#define TSIx_DATA_TSICNT_SHIFT      0                                                                                /*!< TSI Conversion Counter Value (shift) */
#define TSIx_DATA_TSICNT_MASK       ((uint32_t)((uint32_t)0xFFFF << TSIx_DATA_TSICNT_SHIFT))                         /*!< TSI Conversion Counter Value (mask) */
#define TSIx_DATA_TSICNT(x)         ((uint32_t)(((uint32_t)(x) << TSIx_DATA_TSICNT_SHIFT) & TSIx_DATA_TSICNT_MASK))  /*!< TSI Conversion Counter Value */

/**********  Bits definition for TSIx_TSHD register  ************/
#define TSIx_TSHD_THRESH_SHIFT      16                                                                               /*!< TSI Wakeup Channel High-Threshold (shift) */
#define TSIx_TSHD_THRESH_MASK       ((uint32_t)((uint32_t)0xFFFF << TSIx_TSHD_THRESH_SHIFT))                         /*!< TSI Wakeup Channel High-Threshold (mask) */
#define TSIx_TSHD_THRESH(x)         ((uint32_t)(((uint32_t)(x) << TSIx_TSHD_THRESH_SHIFT) & TSIx_TSHD_THRESH_MASK))  /*!< TSI Wakeup Channel High-Threshold */
#define TSIx_TSHD_THRESL_SHIFT      0                                                                                /*!< TSI Wakeup Channel Low-Threshold (shift) */
#define TSIx_TSHD_THRESL_MASK       ((uint32_t)((uint32_t)0xFFFF << TSIx_TSHD_THRESL_SHIFT))                         /*!< TSI Wakeup Channel Low-Threshold (mask) */
#define TSIx_TSHD_THRESL(x)         ((uint32_t)(((uint32_t)(x) << TSIx_TSHD_THRESL_SHIFT) & TSIx_TSHD_THRESL_MASK))  /*!< TSI Wakeup Channel Low-Threshold */

/****************************************************************/
/*                                                              */
/*             Multipurpose Clock Generator (MCG)               */
/*                                                              */
/****************************************************************/
/***********  Bits definition for MCG_C1 register  **************/
#define MCG_C1_CLKS_SHIFT           6                                                           /*!< Clock source select (shift) */
#define MCG_C1_CLKS_MASK            ((uint8_t)((uint8_t)0x03 << MCG_C1_CLKS_SHIFT))             /*!< Clock source select (mask) */
#define MCG_C1_CLKS(x)              ((uint8_t)(((uint8_t)(x) << MCG_C1_CLKS_SHIFT) & MCG_C1_CLKS_MASK))  /*!< Clock source select */
#define MCG_C1_CLKS_FLLPLL          MCG_C1_CLKS(0)  /*!< Select output of FLL or PLL, depending on PLLS control bit */
#define MCG_C1_CLKS_IRCLK           MCG_C1_CLKS(1)  /*!< Select internal reference clock */
#define MCG_C1_CLKS_ERCLK           MCG_C1_CLKS(2)  /*!< Select external reference clock */
#define MCG_C1_FRDIV_SHIFT          3                                                           /*!< FLL External Reference Divider (shift) */
#define MCG_C1_FRDIV_MASK           ((uint8_t)((uint8_t)0x07 << MCG_C1_FRDIV_SHIFT))            /*!< FLL External Reference Divider (mask) */
#define MCG_C1_FRDIV(x)             ((uint8_t)(((uint8_t)(x) << MCG_C1_FRDIV_SHIFT) & MCG_C1_FRDIV_MASK))  /*!< FLL External Reference Divider */
#define MCG_C1_IREFS                ((uint8_t)((uint8_t)1 << 2))                                /*!< Internal Reference Select (0=ERCLK; 1=slow IRCLK) */
#define MCG_C1_IRCLKEN              ((uint8_t)((uint8_t)1 << 1))                                /*!< Internal Reference Clock Enable */
#define MCG_C1_IREFSTEN             ((uint8_t)((uint8_t)1 << 0))                                /*!< Internal Reference Stop Enable */

/***********  Bits definition for MCG_C2 register  **************/
#define MCG_C2_LOCRE0               ((uint8_t)((uint8_t)1 << 7))                                /*!< Loss of Clock Reset Enable */
#define MCG_C2_FCFTRIM              ((uint8_t)((uint8_t)1 << 6))                                /*!< Loss of Clock Reset Enable */
#define MCG_C2_RANGE0_SHIFT         4                                                           /*!< Frequency Range Select (shift) */
#define MCG_C2_RANGE0_MASK          ((uint8_t)((uint8_t)0x03 << MCG_C2_RANGE0_SHIFT))           /*!< Frequency Range Select (mask) */
#define MCG_C2_RANGE0(x)            ((uint8_t)(((uint8_t)(x) << MCG_C2_RANGE0_SHIFT) & MCG_C2_RANGE0_MASK))  /*!< Frequency Range Select */
#define MCG_C2_HGO0                 ((uint8_t)((uint8_t)1 << 3))                                /*!< High Gain Oscillator Select (0=low power; 1=high gain) */
#define MCG_C2_EREFS0               ((uint8_t)((uint8_t)1 << 2))                                /*!< External Reference Select (0=clock; 1=oscillator) */
#define MCG_C2_LP                   ((uint8_t)((uint8_t)1 << 1))                                /*!< Low Power Select (1=FLL/PLL disabled in bypass modes) */
#define MCG_C2_IRCS                 ((uint8_t)((uint8_t)1 << 0))                                /*!< Internal Reference Clock Select (0=slow; 1=fast) */

/***********  Bits definition for MCG_C3 register  **************/
#define MCG_C3_SCTRIM_SHIFT         0                                                           /*!< Slow Internal Reference Clock Trim Setting (shift) */
#define MCG_C3_SCTRIM_MASK          ((uint8_t)((uint8_t)0xFF << MCG_C3_SCTRIM_SHIFT))           /*!< Slow Internal Reference Clock Trim Setting (mask) */
#define MCG_C3_SCTRIM(x)            ((uint8_t)(((uint8_t)(x) << MCG_C3_SCTRIM_SHIFT) & MCG_C3_SCTRIM_MASK))  /*!< Slow Internal Reference Clock Trim Setting */

/***********  Bits definition for MCG_C4 register  **************/
#define MCG_C4_DMX32                ((uint8_t)((uint8_t)1 << 7))                                /*!< DCO Maximum Frequency with 32.768 kHz Reference */
#define MCG_C4_DRST_DRS_SHIFT       5                                                           /*!< DCO Range Select (shift) */
#define MCG_C4_DRST_DRS_MASK        ((uint8_t)((uint8_t)0x03 << MCG_C4_DRST_DRS_SHIFT))         /*!< DCO Range Select (mask) */
#define MCG_C4_DRST_DRS(x)          ((uint8_t)(((uint8_t)(x) << MCG_C4_DRST_DRS_SHIFT) & MCG_C4_DRST_DRS_MASK))  /*!< DCO Range Select */
#define MCG_C4_FCTRIM_SHIFT         1                                                           /*!< Fast Internal Reference Clock Trim Setting (shift) */
#define MCG_C4_FCTRIM_MASK          ((uint8_t)((uint8_t)0x0F << MCG_C4_FCTRIM_SHIFT))           /*!< Fast Internal Reference Clock Trim Setting (mask) */
#define MCG_C4_FCTRIM(x)            ((uint8_t)(((uint8_t)(x) << MCG_C4_FCTRIM_SHIFT) & MCG_C4_FCTRIM_MASK))  /*!< Fast Internal Reference Clock Trim Setting */
#define MCG_C4_SCFTRIM              ((uint8_t)((uint8_t)1 << 0))                                /*!< Slow Internal Reference Clock Fine Trim */

/***********  Bits definition for MCG_C5 register  **************/
#define MCG_C5_PLLCLKEN0            ((uint8_t)((uint8_t)1 << 6))                                /*!< PLL Clock Enable */
#define MCG_C5_PLLSTEN0             ((uint8_t)((uint8_t)1 << 5))                                /*!< PLL Stop Enable */
#define MCG_C5_PRDIV0_SHIFT         0                                                           /*!< PLL External Reference Divider (shift) */
#define MCG_C5_PRDIV0_MASK          ((uint8_t)((uint8_t)0x1F << MCG_C5_PRDIV0_SHIFT))           /*!< PLL External Reference Divider (mask) */
#define MCG_C5_PRDIV0(x)            ((uint8_t)(((uint8_t)(x) << MCG_C5_PRDIV0_SHIFT) & MCG_C5_PRDIV0_MASK))  /*!< PLL External Reference Divider */

/***********  Bits definition for MCG_C6 register  **************/
#define MCG_C6_LOLIE0               ((uint8_t)((uint8_t)1 << 7))                                /*!< Loss of Lock Interrupt Enable */
#define MCG_C6_PLLS                 ((uint8_t)((uint8_t)1 << 6))                                /*!< PLL Select */
#define MCG_C6_CME0                 ((uint8_t)((uint8_t)1 << 5))                                /*!< Clock Monitor Enable */
#define MCG_C6_VDIV0_SHIFT          0                                                           /*!< VCO 0 Divider (shift) */
#define MCG_C6_VDIV0_MASK           ((uint8_t)((uint8_t)0x1F << MCG_C6_VDIV0_SHIFT))            /*!< VCO 0 Divider (mask) */
#define MCG_C6_VDIV0(x)             ((uint8_t)(((uint8_t)(x) << MCG_C6_VDIV0_SHIFT) & MCG_C6_VDIV0_MASK))  /*!< VCO 0 Divider */

/************  Bits definition for MCG_S register  **************/
#define MCG_S_LOLS                  ((uint8_t)((uint8_t)1 << 7))                                /*!< Loss of Lock Status */
#define MCG_S_LOCK0                 ((uint8_t)((uint8_t)1 << 6))                                /*!< Lock Status */
#define MCG_S_PLLST                 ((uint8_t)((uint8_t)1 << 5))                                /*!< PLL Select Status */
#define MCG_S_IREFST                ((uint8_t)((uint8_t)1 << 4))                                /*!< Internal Reference Status */
#define MCG_S_CLKST_SHIFT           2                                                           /*!< Clock Mode Status (shift) */
#define MCG_S_CLKST_MASK            ((uint8_t)((uint8_t)0x03 << MCG_S_CLKST_SHIFT))             /*!< Clock Mode Status (mask) */
#define MCG_S_CLKST(x)              ((uint8_t)(((uint8_t)(x) << MCG_S_CLKST_SHIFT) & MCG_S_CLKST_MASK))  /*!< Clock Mode Status */
#define MCG_S_CLKST_FLL             MCG_S_CLKST(0)   /*!< Output of the FLL is selected */
#define MCG_S_CLKST_IRCLK           MCG_S_CLKST(1)   /*!< Internal reference clock is selected */
#define MCG_S_CLKST_ERCLK           MCG_S_CLKST(2)   /*!< External reference clock is selected */
#define MCG_S_CLKST_PLL             MCG_S_CLKST(3)   /*!< Output of the PLL is selected */
#define MCG_S_OSCINIT0              ((uint8_t)((uint8_t)1 << 1))                                /*!< OSC Initialization */
#define MCG_S_IRCST                 ((uint8_t)((uint8_t)1 << 0))                                /*!< Internal Reference Clock Status */

/************  Bits definition for MCG_SC register  **************/
#define MCG_SC_ATME                 ((uint8_t)((uint8_t)1 << 7))                                /*!< Automatic Trim Machine Enable */
#define MCG_SC_ATMS                 ((uint8_t)((uint8_t)1 << 6))                                /*!< Automatic Trim Machine Select */
#define MCG_SC_ATMF                 ((uint8_t)((uint8_t)1 << 5))                                /*!< Automatic Trim Machine Fail Flag */
#define MCG_SC_FLTPRSRV             ((uint8_t)((uint8_t)1 << 4)                                 /*!< FLL Filter Preserve Enable */
#define MCG_SC_FCRDIV_SHIFT         1                                                           /*!< Fast Clock Internal Reference Divider (shift) */
#define MCG_SC_FCRDIV_MASK          ((uint8_t)((uint8_t)0x07 << MCG_SC_FCRDIV_SHIFT))           /*!< Fast Clock Internal Reference Divider (mask) */
#define MCG_SC_FCRDIV(x)            ((uint8_t)(((uint8_t)(x) << MCG_SC_FCRDIV_SHIFT) & MCG_SC_FCRDIV_MASK))  /*!< Fast Clock Internal Reference Divider */
#define MCG_SC_FCRDIV_DIV1          MCG_SC_FCRDIV(0)  /*!< Divide Factor is 1 */
#define MCG_SC_FCRDIV_DIV2          MCG_SC_FCRDIV(1)  /*!< Divide Factor is 2 */
#define MCG_SC_FCRDIV_DIV4          MCG_SC_FCRDIV(2)  /*!< Divide Factor is 4 */
#define MCG_SC_FCRDIV_DIV8          MCG_SC_FCRDIV(3)  /*!< Divide Factor is 8 */
#define MCG_SC_FCRDIV_DIV16         MCG_SC_FCRDIV(4)  /*!< Divide Factor is 16 */
#define MCG_SC_FCRDIV_DIV32         MCG_SC_FCRDIV(5)  /*!< Divide Factor is 32 */
#define MCG_SC_FCRDIV_DIV64         MCG_SC_FCRDIV(6)  /*!< Divide Factor is 64 */
#define MCG_SC_FCRDIV_DIV128        MCG_SC_FCRDIV(7)  /*!< Divide Factor is 128 */
#define MCG_SC_LOCS0                ((uint8_t)((uint8_t)1 << 0)                                 /*!< OSC0 Loss of Clock Status */

/***********  Bits definition for MCG_ATCVH register  ************/
#define MCG_ATCVH_ATCVH_SHIFT       0                                                           /*!< MCG Auto Trim Compare Value High Register (shift) */
#define MCG_ATCVH_ATCVH_MASK        ((uint8_t)((uint8_t)0xFF << MCG_ATCVH_ATCVH_SHIFT))         /*!< MCG Auto Trim Compare Value High Register (mask) */
#define MCG_ATCVH_ATCVH(x)          ((uint8_t)(((uint8_t)(x) << MCG_ATCVH_ATCVH_SHIFT) & MCG_ATCVH_ATCVH_MASK))  /*!< MCG Auto Trim Compare Value High Register */

/***********  Bits definition for MCG_ATCVL register  ************/
#define MCG_ATCVL_ATCVL_SHIFT       0                                                           /*!< MCG Auto Trim Compare Value Low Register (shift) */
#define MCG_ATCVL_ATCVL_MASK        ((uint8_t)((uint8_t)0xFF << MCG_ATCVL_ATCVL_SHIFT))         /*!< MCG Auto Trim Compare Value Low Register (mask) */
#define MCG_ATCVL_ATCVL(x)          ((uint8_t)(((uint8_t)(x) << MCG_ATCVL_ATCVL_SHIFT) & MCG_ATCVL_ATCVL_MASK))  /*!< MCG Auto Trim Compare Value Low Register */

/************  Bits definition for MCG_C7 register  **************/
#define MCG_C7_OSCSEL               ((uint8_t)((uint8_t)1 << 0)

/************  Bits definition for MCG_C8 register  **************/
#define MCG_C8_LOLRE                ((uint8_t)((uint8_t)1 << 6))                                /*!< PLL Loss of Lock Reset Enable */

/************  Bits definition for MCG_C9 register  **************/
/* All MCG_C9 bits are reserved on the KL26Z. */

/************  Bits definition for MCG_C10 register  *************/
/* All MCG_C10 bits are reserved on the KL26Z. */


/****************************************************************/
/*                                                              */
/*             Serial Peripheral Interface (SPI)                */
/*                                                              */
/****************************************************************/

/***********  Bits definition for SPIx_S register  **************/
#define SPIx_S_SPRF                  ((uint8_t)0x80)    /*!< SPI Read Buffer Full Flag */
#define SPIx_S_SPMF                  ((uint8_t)0x40)    /*!< SPI Match Flag */
#define SPIx_S_SPTEF                 ((uint8_t)0x20)    /*!< SPI Transmit Buffer Empty Flag */
#define SPIx_S_MODF                  ((uint8_t)0x10)    /*!< Master Mode Fault Flag */
#define SPIx_S_RNFULLF               ((uint8_t)0x08)    /*!< Receive FIFO nearly full flag */
#define SPIx_S_TNEAREF               ((uint8_t)0x04)    /*!< Transmit FIFO nearly empty flag */
#define SPIx_S_TXFULLF               ((uint8_t)0x02)    /*!< Transmit FIFO full flag */
#define SPIx_S_RFIFOEF               ((uint8_t)0x01)    /*!< SPI read FIFO empty flag */

/***********  Bits definition for SPIx_BR register  *************/
#define SPIx_BR_SPPR_SHIFT           4                  !< SPI Baud rate Prescaler Divisor 
#define SPIx_BR_SPPR_MASK            ((uint8_t)((uint8_t)0x7 << SPIx_BR_SPPR_SHIFT))
#define SPIx_BR_SPPR(x)              ((uint8_t)(((uint8_t)(x) << SPIx_BR_SPPR_SHIFT) & SPIx_BR_SPPR_MASK))
#define SPIx_BR_SPR_SHIFT            0                  /*!< SPI Baud rate Divisor */
#define SPIx_BR_SPR_MASK             ((uint8_t)((uint8_t)0x0F << SPIx_BR_SPR_SHIFT))
#define SPIx_BR_SPR(x)               ((uint8_t)(((uint8_t)(x) << SPIx_BR_SPR_SHIFT) & SPIx_BR_SPR_MASK))

/***********  Bits definition for SPIx_C2 register  *************/
#define SPIx_C2_SPMIE                ((uint8_t)0x80)    /*!< SPI Match Interrupt Enable */
#define SPIx_C2_SPIMODE              ((uint8_t)0x40)    /*!< SPI 8-bit or 16-bit mode */
#define SPIx_C2_TXDMAE               ((uint8_t)0x20)    /*!< Transmit DMA Enable */
#define SPIx_C2_MODFEN               ((uint8_t)0x10)    /*!< Master Mode-Fault Function Enable */
#define SPIx_C2_BIDIROE              ((uint8_t)0x08)    /*!< Bidirectional Mode Output Enable */
#define SPIx_C2_RXDMAE               ((uint8_t)0x04)    /*!< Receive DMA Enable */
#define SPIx_C2_SPISWAI              ((uint8_t)0x02)    /*!< SPI Stop in Wait Mode */
#define SPIx_C2_SPC0                 ((uint8_t)0x01)    /*!< SPI Pin Control 0 */

/***********  Bits definition for SPIx_C1 register  *************/
#define SPIx_C1_SPIE                 ((uint8_t)0x80)    /*!< SPI Interrupt Enable */
#define SPIx_C1_SPE                  ((uint8_t)0x40)    /*!< SPI System Enable */
#define SPIx_C1_SPTIE                ((uint8_t)0x20)    /*!< SPI Transmit Interrupt Enable */
#define SPIx_C1_MSTR                 ((uint8_t)0x10)    /*!< Master/Slave Mode Select */
#define SPIx_C1_CPOL                 ((uint8_t)0x08)    /*!< Clock Polarity */
#define SPIx_C1_CPHA                 ((uint8_t)0x04)    /*!< Clock Phase */
#define SPIx_C1_SSOE                 ((uint8_t)0x02)    /*!< Slave Select Output Enable */
#define SPIx_C1_LSBFE                ((uint8_t)0x01)    /*!< LSB First */

/***********  Bits definition for SPIx_ML register  *************/
#define SPIx_ML_DATA_SHIFT           0                  /*!< SPI HW Compare value for Match - low byte */
#define SPIx_ML_DATA_MASK            ((uint8_t)((uint8_t)0xFF << SPIx_ML_DATA_SHIFT))
#define SPIx_ML_DATA(x)              ((uint8_t)(((uint8_t)(x) << SPIx_ML_DATA_SHIFT) & SPIx_ML_DATA_MASK))

/***********  Bits definition for SPIx_MH register  *************/
#define SPIx_MH_DATA_SHIFT           0                  /*!< SPI HW Compare value for Match - high byte */
#define SPIx_MH_DATA_MASK            ((uint8_t)((uint8_t)0xFF << SPIx_MH_DATA_SHIFT))
#define SPIx_MH_DATA(x)              ((uint8_t)(((uint8_t)(x) << SPIx_MH_DATA_SHIFT) & SPIx_MH_DATA_MASK))

/***********  Bits definition for SPIx_DL register  *************/
#define SPIx_DL_DATA_SHIFT            0                  /*!< Data - low byte */
#define SPIx_DL_DATA_MASK             ((uint8_t)((uint8_t)0xFF << SPIx_DL_DATA_SHIFT))
#define SPIx_DL_DATA(x)               ((uint8_t)(((uint8_t)(x) << SPIx_DL_DATA_SHIFT) & SPIx_DL_DATA_MASK))

/***********  Bits definition for SPIx_DH register  *************/
#define SPIx_DH_DATA_SHIFT            0                  /*!< Data - high byte */
#define SPIx_DH_DATA_MASK             ((uint8_t)((uint8_t)0xFF << SPIx_DH_DATA_SHIFT))
#define SPIx_DH_DATA(x)               ((uint8_t)(((uint8_t)(x) << SPIx_DH_DATA_SHIFT) & SPIx_DH_DATA_MASK))

/***********  Bits definition for SPIx_CI register  *************/
#define SPIx_CI_TXFERR                ((uint8_t)0x80)    /*!< Transmit FIFO error flag */
#define SPIx_CI_RXFERR                ((uint8_t)0x40)    /*!< Receive FIFO error flag */
#define SPIx_CI_TXFOF                 ((uint8_t)0x20)    /*!< Transmit FIFO overflow flag */
#define SPIx_CI_RXFOF                 ((uint8_t)0x10)    /*!< Receive FIFO overflow flag */
#define SPIx_CI_TNEAREFCI             ((uint8_t)0x08)    /*!< Transmit FIFO nearly empty flag clear interrupt */
#define SPIx_CI_RNFULLFCI             ((uint8_t)0x04)    /*!< Receive FIFO nearly full flag clear interrupt */
#define SPIx_CI_SPTEFCI               ((uint8_t)0x02)    /*!< Transmit FIFO empty flag clear interrupt */
#define SPIx_CI_SPRFCI                ((uint8_t)0x01)    /*!< Receive FIFO full flag clear interrupt */

/***********  Bits definition for SPIx_C3 register  *************/
#define SPIx_C3_TNEAREF_MARK          ((uint8_t)0x20)    /*!< Transmit FIFO nearly empty watermark */
#define SPIx_C3_RNFULLF_MARK          ((uint8_t)0x10)    /*!< Receive FIFO nearly full watermark */
#define SPIx_C3_INTCLR                ((uint8_t)0x08)    /*!< Interrupt clearing mechanism select */
#define SPIx_C3_TNEARIEN              ((uint8_t)0x04)    /*!< Transmit FIFO nearly empty interrupt enable */
#define SPIx_C3_RNFULLIEN             ((uint8_t)0x02)    /*!< Receive FIFO nearly full interrupt enable */
#define SPIx_C3_FIFOMODE              ((uint8_t)0x01)    /*!< FIFO mode enable */

/****************************************************************/
/*                                                              */
/*             Inter-Integrated Circuit (I2C)                   */
/*                                                              */
/****************************************************************/
/***********  Bits definition for I2Cx_A1 register  *************/
#define I2Cx_A1_AD_MASK              ((uint8_t)0xFE)    /*!< Address [7:1] */
#define I2Cx_A1_AD_SHIFT             1
#define I2Cx_A1_AD(x)                ((uint8_t)(((uint8_t)(x) << I2Cx_A1_AD_SHIFT) & I2Cx_A1_AD_MASK)

/***********  Bits definition for I2Cx_F register  **************/
#define I2Cx_F_MULT_MASK             ((uint8_t)0xC0)    /*!< Multiplier factor */
#define I2Cx_F_MULT_SHIFT            6
#define I2Cx_F_MULT(x)               ((uint8_t)(((uint8_t)(x) << I2Cx_F_MULT_SHIFT) & I2Cx_F_MULT_MASK)
#define I2Cx_F_ICR                   ((uint8_t)0x3F)    /*!< Clock rate */

/***********  Bits definition for I2Cx_C1 register  *************/
#define I2Cx_C1_IICEN                ((uint8_t)0x80)    /*!< I2C Enable */
#define I2Cx_C1_IICIE                ((uint8_t)0x40)    /*!< I2C Interrupt Enable */
#define I2Cx_C1_MST                  ((uint8_t)0x20)    /*!< Master Mode Select */
#define I2Cx_C1_TX                   ((uint8_t)0x10)    /*!< Transmit Mode Select */
#define I2Cx_C1_TXAK                 ((uint8_t)0x08)    /*!< Transmit Acknowledge Enable */
#define I2Cx_C1_RSTA                 ((uint8_t)0x04)    /*!< Repeat START */
#define I2Cx_C1_WUEN                 ((uint8_t)0x02)    /*!< Wakeup Enable */
#define I2Cx_C1_DMAEN                ((uint8_t)0x01)    /*!< DMA Enable */

/***********  Bits definition for I2Cx_S1 register  *************/
#define I2Cx_S1_TCF                  ((uint8_t)0x80)    /*!< Transfer Complete Flag */
#define I2Cx_S1_IAAS                 ((uint8_t)0x40)    /*!< Addressed As A Slave */
#define I2Cx_S1_BUSY                 ((uint8_t)0x20)    /*!< Bus Busy */
#define I2Cx_S1_ARBL                 ((uint8_t)0x10)    /*!< Arbitration Lost */
#define I2Cx_S1_RAM                  ((uint8_t)0x08)    /*!< Range Address Match */
#define I2Cx_S1_SRW                  ((uint8_t)0x04)    /*!< Slave Read/Write */
#define I2Cx_S1_IICIF                ((uint8_t)0x02)    /*!< Interrupt Flag */
#define I2Cx_S1_RXAK                 ((uint8_t)0x01)    /*!< Receive Acknowledge */

/***********  Bits definition for I2Cx_D register  **************/
#define I2Cx_D_DATA_SHIFT            0                  /*!< Data */
#define I2Cx_D_DATA_MASK             ((uint8_t)((uint8_t)0xFF << I2Cx_D_DATA_SHIFT))
#define I2Cx_D_DATA(x)               ((uint8_t)(((uint8_t)(x) << I2Cx_D_DATA_SHIFT) & I2Cx_D_DATA_MASK))

/***********  Bits definition for I2Cx_C2 register  *************/
#define I2Cx_C2_GCAEN                ((uint8_t)0x80)    /*!< General Call Address Enable */
#define I2Cx_C2_ADEXT                ((uint8_t)0x40)    /*!< Address Extension */
#define I2Cx_C2_HDRS                 ((uint8_t)0x20)    /*!< High Drive Select */
#define I2Cx_C2_SBRC                 ((uint8_t)0x10)    /*!< Slave Baud Rate Control */
#define I2Cx_C2_RMEN                 ((uint8_t)0x08)    /*!< Range Address Matching Enable */
#define I2Cx_C2_AD_SHIFT             0                  /*!< Slave Address [10:8] */
#define I2Cx_C2_AD_MASK              ((uint8_t)((uint8_t)0x7 << I2Cx_C2_AD_SHIFT))
#define I2Cx_C2_AD(x)                ((uint8_t)(((uint8_t)(x) << I2Cx_C2_AD_SHIFT) & I2Cx_C2_AD_MASK))

/***********  Bits definition for I2Cx_FLT register  ************/
#define I2Cx_FLT_SHEN                ((uint8_t)0x80)    /*!< Stop Hold Enable */
#define I2Cx_FLT_STOPF               ((uint8_t)0x40)    /*!< I2C Bus Stop Detect Flag */
#define I2Cx_FLT_STOPIE              ((uint8_t)0x20)    /*!< I2C Bus Stop Interrupt Enable */
#define I2Cx_FLT_FLT_SHIFT           0                  /*!< I2C Programmable Filter Factor */
#define I2Cx_FLT_FLT_MASK            ((uint8_t)((uint8_t)0x1F << I2Cx_FLT_FLT_SHIFT))
#define I2Cx_FLT_FLT(x)              ((uint8_t)(((uint8_t)(x) << I2Cx_FLT_FLT_SHIFT) & I2Cx_FLT_FLT_MASK))

/***********  Bits definition for I2Cx_RA register  *************/
#define I2Cx_RA_RAD_SHIFT            1                  /*!< Range Slave Address */
#define I2Cx_RA_RAD_MASK             ((uint8_t)((uint8_t)0x7F << I2Cx_RA_RAD_SHIFT))
#define I2Cx_RA_RAD(x)               ((uint8_t)(((uint8_t)(x) << I2Cx_RA_RAD_SHIFT) & I2Cx_RA_RAD_MASK))

/***********  Bits definition for I2Cx_SMB register  ************/
#define I2Cx_SMB_FACK                ((uint8_t)0x80)    /*!< Fast NACK/ACK Enable */
#define I2Cx_SMB_ALERTEN             ((uint8_t)0x40)    /*!< SMBus Alert Response Address Enable */
#define I2Cx_SMB_SIICAEN             ((uint8_t)0x20)    /*!< Second I2C Address Enable */
#define I2Cx_SMB_TCKSEL              ((uint8_t)0x10)    /*!< Timeout Counter Clock Select */
#define I2Cx_SMB_SLTF                ((uint8_t)0x08)    /*!< SCL Low Timeout Flag */
#define I2Cx_SMB_SHTF1               ((uint8_t)0x04)    /*!< SCL High Timeout Flag 1 */
#define I2Cx_SMB_SHTF2               ((uint8_t)0x02)    /*!< SCL High Timeout Flag 2 */
#define I2Cx_SMB_SHTF2IE             ((uint8_t)0x01)    /*!< SHTF2 Interrupt Enable */

/***********  Bits definition for I2Cx_A2 register  *************/
#define I2Cx_A2_SAD_SHIFT            1                  /*!< SMBus Address */
#define I2Cx_A2_SAD_MASK             ((uint8_t)((uint8_t)0x7F << I2Cx_A2_SAD_SHIFT))
#define I2Cx_A2_SAD(x)               ((uint8_t)(((uint8_t)(x) << I2Cx_A2_SAD_SHIFT) & I2Cx_A2_SAD_MASK))

/***********  Bits definition for I2Cx_SLTH register  ***********/
#define I2Cx_SLTH_SSLT_SHIFT         0                  /*!< MSB of SCL low timeout value */
#define I2Cx_SLTH_SSLT_MASK          ((uint8_t)((uint8_t)0xFF << I2Cx_SLTH_SSLT_SHIFT))
#define I2Cx_SLTH_SSLT(x)            ((uint8_t)(((uint8_t)(x) << I2Cx_SLTH_SSLT_SHIFT) & I2Cx_SLTH_SSLT_MASK))

/***********  Bits definition for I2Cx_SLTL register  ***********/
#define I2Cx_SLTL_SSLT_SHIFT         0                  /*!< LSB of SCL low timeout value */
#define I2Cx_SLTL_SSLT_MASK          ((uint8_t)((uint8_t)0xFF << I2Cx_SLTL_SSLT_SHIFT))
#define I2Cx_SLTL_SSLT(x)            ((uint8_t)(((uint8_t)(x) << I2Cx_SLTL_SSLT_SHIFT) & I2Cx_SLTL_SSLT_MASK))

/****************************************************************/
/*                                                              */
/*     Universal Asynchronous Receiver/Transmitter (UART)       */
/*                                                              */
/****************************************************************/
/*********  Bits definition for UARTx_BDH register  *************/
#define UARTx_BDH_LBKDIE             ((uint8_t)0x80)    /*!< LIN Break Detect Interrupt Enable */
#define UARTx_BDH_RXEDGIE            ((uint8_t)0x40)    /*!< RX Input Active Edge Interrupt Enable */
#define UARTx_BDH_SBNS               ((uint8_t)0x20)    /*!< Stop Bit Number Select */
#define UARTx_BDH_SBR_SHIFT          0                  /*!< Baud Rate Modulo Divisor */
#define UARTx_BDH_SBR_MASK           ((uint8_t)((uint8_t)0x1F << UARTx_BDH_SBR_SHIFT))
#define UARTx_BDH_SBR(x)             ((uint8_t)(((uint8_t)(x) << UARTx_BDH_SBR_SHIFT) & UARTx_BDH_SBR_MASK))

/*********  Bits definition for UARTx_BDL register  *************/
#define UARTx_BDL_SBR_SHIFT          0                  /*!< Baud Rate Modulo Divisor */
#define UARTx_BDL_SBR_MASK           ((uint8_t)((uint8_t)0xFF << UARTx_BDL_SBR_SHIFT))
#define UARTx_BDL_SBR(x)             ((uint8_t)(((uint8_t)(x) << UARTx_BDL_SBR_SHIFT) & UARTx_BDL_SBR_MASK))

/*********  Bits definition for UARTx_C1 register  **************/
#define UARTx_C1_LOOPS               ((uint8_t)0x80)    /*!< Loop Mode Select */
#define UARTx_C1_DOZEEN              ((uint8_t)0x40)    /*!< Doze Enable */
#define UARTx_C1_UARTSWAI            ((uint8_t)0x40)    /*!< UART Stops in Wait Mode */
#define UARTx_C1_RSRC                ((uint8_t)0x20)    /*!< Receiver Source Select */
#define UARTx_C1_M                   ((uint8_t)0x10)    /*!< 9-Bit or 8-Bit Mode Select */
#define UARTx_C1_WAKE                ((uint8_t)0x08)    /*!< Receiver Wakeup Method Select */
#define UARTx_C1_ILT                 ((uint8_t)0x04)    /*!< Idle Line Type Select */
#define UARTx_C1_PE                  ((uint8_t)0x02)    /*!< Parity Enable */
#define UARTx_C1_PT                  ((uint8_t)0x01)    /*!< Parity Type */

/*********  Bits definition for UARTx_C2 register  **************/
#define UARTx_C2_TIE                 ((uint8_t)0x80)    /*!< Transmit Interrupt Enable for TDRE */
#define UARTx_C2_TCIE                ((uint8_t)0x40)    /*!< Transmission Complete Interrupt Enable for TC */
#define UARTx_C2_RIE                 ((uint8_t)0x20)    /*!< Receiver Interrupt Enable for RDRF */
#define UARTx_C2_ILIE                ((uint8_t)0x10)    /*!< Idle Line Interrupt Enable for IDLE */
#define UARTx_C2_TE                  ((uint8_t)0x08)    /*!< Transmitter Enable */
#define UARTx_C2_RE                  ((uint8_t)0x04)    /*!< Receiver Enable */
#define UARTx_C2_RWU                 ((uint8_t)0x02)    /*!< Receiver Wakeup Control */
#define UARTx_C2_SBK                 ((uint8_t)0x01)    /*!< Send Break */

/*********  Bits definition for UARTx_S1 register  **************/
#define UARTx_S1_TDRE                ((uint8_t)0x80)    /*!< Transmit Data Register Empty Flag */
#define UARTx_S1_TC                  ((uint8_t)0x40)    /*!< Transmission Complete Flag */
#define UARTx_S1_RDRF                ((uint8_t)0x20)    /*!< Receiver Data Register Full Flag */
#define UARTx_S1_IDLE                ((uint8_t)0x10)    /*!< Idle Line Flag */
#define UARTx_S1_OR                  ((uint8_t)0x08)    /*!< Receiver Overrun Flag */
#define UARTx_S1_NF                  ((uint8_t)0x04)    /*!< Noise Flag */
#define UARTx_S1_FE                  ((uint8_t)0x02)    /*!< Framing Error Flag */
#define UARTx_S1_PF                  ((uint8_t)0x01)    /*!< Parity Error Flag */

/*********  Bits definition for UARTx_S2 register  **************/
#define UARTx_S2_LBKDIF              ((uint8_t)0x80)    /*!< LIN Break Detect Interrupt Flag */
#define UARTx_S2_RXEDGIF             ((uint8_t)0x40)    /*!< UART_RX Pin Active Edge Interrupt Flag */
#define UARTx_S2_MSBF                ((uint8_t)0x20)    /*!< MSB First */
#define UARTx_S2_RXINV               ((uint8_t)0x10)    /*!< Receive Data Inversion */
#define UARTx_S2_RWUID               ((uint8_t)0x08)    /*!< Receive Wake Up Idle Detect */
#define UARTx_S2_BRK13               ((uint8_t)0x04)    /*!< Break Character Generation Length */
#define UARTx_S2_LBKDE               ((uint8_t)0x02)    /*!< LIN Break Detect Enable */
#define UARTx_S2_RAF                 ((uint8_t)0x01)    /*!< Receiver Active Flag */

/*********  Bits definition for UARTx_C3 register  **************/
#define UARTx_C3_R8T9                ((uint8_t)0x80)    /*!< Receive Bit 8 / Transmit Bit 9 */
#define UARTx_C3_R8                  ((uint8_t)0x80)    /*!< Ninth Data Bit for Receiver */
#define UARTx_C3_R9T8                ((uint8_t)0x40)    /*!< Receive Bit 9 / Transmit Bit 8 */
#define UARTx_C3_T8                  ((uint8_t)0x40)    /*!< Ninth Data Bit for Transmitter */
#define UARTx_C3_TXDIR               ((uint8_t)0x20)    /*!< UART_TX Pin Direction in Single-Wire Mode */
#define UARTx_C3_TXINV               ((uint8_t)0x10)    /*!< Transmit Data Inversion */
#define UARTx_C3_ORIE                ((uint8_t)0x08)    /*!< Overrun Interrupt Enable */
#define UARTx_C3_NEIE                ((uint8_t)0x04)    /*!< Noise Error Interrupt Enable */
#define UARTx_C3_FEIE                ((uint8_t)0x02)    /*!< Framing Error Interrupt Enable */
#define UARTx_C3_PEIE                ((uint8_t)0x01)    /*!< Parity Error Interrupt Enable */

/*********  Bits definition for UARTx_D register  ***************/
#define UARTx_D_R7T7                 ((uint8_t)0x80)    /*!< Read receive data buffer 7 or write transmit data buffer 7 */
#define UARTx_D_R6T6                 ((uint8_t)0x40)    /*!< Read receive data buffer 6 or write transmit data buffer 6 */
#define UARTx_D_R5T5                 ((uint8_t)0x20)    /*!< Read receive data buffer 5 or write transmit data buffer 5 */
#define UARTx_D_R4T4                 ((uint8_t)0x10)    /*!< Read receive data buffer 4 or write transmit data buffer 4 */
#define UARTx_D_R3T3                 ((uint8_t)0x08)    /*!< Read receive data buffer 3 or write transmit data buffer 3 */
#define UARTx_D_R2T2                 ((uint8_t)0x04)    /*!< Read receive data buffer 2 or write transmit data buffer 2 */
#define UARTx_D_R1T1                 ((uint8_t)0x02)    /*!< Read receive data buffer 1 or write transmit data buffer 1 */
#define UARTx_D_R0T0                 ((uint8_t)0x01)    /*!< Read receive data buffer 0 or write transmit data buffer 0 */

/*********  Bits definition for UARTx_MA1 register  *************/
#define UARTx_MA1_MA_SHIFT           0                  /*!< Match Address */
#define UARTx_MA1_MA_MASK            ((uint8_t)((uint8_t)0xFF << UARTx_MA1_MA_SHIFT))
#define UARTx_MA1_MA(x)              ((uint8_t)(((uint8_t)(x) << UARTx_MA1_MA_SHIFT) & UARTx_MA1_MA_MASK))

/*********  Bits definition for UARTx_MA2 register  *************/
#define UARTx_MA2_MA_SHIFT           0                  /*!< Match Address */
#define UARTx_MA2_MA_MASK            ((uint8_t)((uint8_t)0xFF << UARTx_MA2_MA_SHIFT))
#define UARTx_MA2_MA(x)              ((uint8_t)(((uint8_t)(x) << UARTx_MA2_MA_SHIFT) & UARTx_MA2_MA_MASK))

/*********  Bits definition for UARTx_C4 register  **************/
#define UARTx_C4_MAEN1               ((uint8_t)0x80)    /*!< Match Address Mode Enable 1 */
#define UARTx_C4_TDMAS               ((uint8_t)0x80)    /*!< Transmitter DMA Select */
#define UARTx_C4_MAEN2               ((uint8_t)0x40)    /*!< Match Address Mode Enable 2 */
#define UARTx_C4_M10                 ((uint8_t)0x20)    /*!< 10-bit Mode Select */
#define UARTx_C4_RDMAS               ((uint8_t)0x80)    /*!< Receiver Full DMA Select */
#define UARTx_C4_OSR_SHIFT           0                  /*!< Over Sampling Ratio */
#define UARTx_C4_OSR_MASK            ((uint8_t)((uint8_t)0x1F << UARTx_C4_OSR_SHIFT))
#define UARTx_C4_OSR(x)              ((uint8_t)(((uint8_t)(x) << UARTx_C4_OSR_SHIFT) & UARTx_C4_OSR_MASK))

/*********  Bits definition for UARTx_C5 register  **************/
#define UARTx_C5_TDMAE               ((uint8_t)0x80)    /*!< Transmitter DMA Enable */
#define UARTx_C5_RDMAE               ((uint8_t)0x20)    /*!< Receiver Full DMA Enable */
#define UARTx_C5_BOTHEDGE            ((uint8_t)0x02)    /*!< Both Edge Sampling */
#define UARTx_C5_RESYNCDIS           ((uint8_t)0x01)    /*!< Resynchronization Disable */

/****************************************************************/
/*                                                              */
/*             Power Management Controller (PMC)                */
/*                                                              */
/****************************************************************/

/* Device independent */

/****************************************************************/
/*                                                              */
/*                  Timer/PWM Module (TPM)                      */
/*                                                              */
/****************************************************************/

/**********  Bits definition for TPM_SC register  ***************/
#define TPM_SC_DMA                   ((uint32_t)0x100)  /*!< DMA Enable */
#define TPM_SC_TOF                   ((uint32_t)0x80)   /*!< Timer Overflow Flag */
#define TPM_SC_TOIE                  ((uint32_t)0x40)   /*!< Timer Overflow Interrupt Enable */
#define TPM_SC_CPWMS                 ((uint32_t)0x20)   /*!< Center-aligned PWM Select */
#define TPM_SC_CMOD_SHIFT            3                  /*!< Clock Mode Selection */
#define TPM_SC_CMOD_MASK             ((uint32_t)((uint32_t)0x3 << TPM_SC_CMOD_SHIFT))
#define TPM_SC_CMOD(x)               ((uint32_t)(((uint32_t)(x) << TPM_SC_CMOD_SHIFT) & TPM_SC_CMOD_MASK))
#define TPM_SC_PS_SHIFT              0                  /*!< Prescale Factor Selection */
#define TPM_SC_PS_MASK               ((uint32_t)((uint32_t)0x7 << TPM_SC_PS_SHIFT))
#define TPM_SC_PS(x)                 ((uint32_t)(((uint32_t)(x) << TPM_SC_PS_SHIFT) & TPM_SC_PS_MASK))

/**********  Bits definition for TPM_CNT register  **************/
#define TPM_CNT_COUNT_SHIFT          0                  /*!< Counter Value */
#define TPM_CNT_COUNT_MASK           ((uint32_t)((uint32_t)0xFFFF << TPM_CNT_COUNT_SHIFT))
#define TPM_CNT_COUNT(x)             ((uint32_t)(((uint32_t)(x) << TPM_CNT_COUNT_SHIFT) & TPM_CNT_COUNT_MASK))

/**********  Bits definition for TPM_MOD register  **************/
#define TPM_MOD_MOD_SHIFT            0                  /*!< Modulo Value */
#define TPM_MOD_MOD_MASK             ((uint32_t)((uint32_t)0xFFFF << TPM_MOD_MOD_SHIFT))
#define TPM_MOD_MOD(x)               ((uint32_t)(((uint32_t)(x) << TPM_MOD_MOD_SHIFT) & TPM_MOD_MOD_MASK))

/**********  Bits definition for TPM_CnSC register  *************/
#define TPM_CnSC_CHF                 ((uint32_t)0x80)   /*!< Channel Flag */
#define TPM_CnSC_CHIE                ((uint32_t)0x40)   /*!< Channel Interrupt Enable */
#define TPM_CnSC_MSB                 ((uint32_t)0x20)   /*!< Channel Mode Select */
#define TPM_CnSC_MSA                 ((uint32_t)0x10)   /*!< Channel Mode Select */
#define TPM_CnSC_ELSB                ((uint32_t)0x8)    /*!< Edge or Level Select */
#define TPM_CnSC_ELSA                ((uint32_t)0x4)    /*!< Edge or Level Select */
#define TPM_CnSC_DMA                 ((uint32_t)0x1)    /*!< DMA Enable */

/**********  Bits definition for TPM_CnV register  **************/
#define TPM_CnV_VAL_SHIFT            0                  /*!< Channel Value */
#define TPM_CnV_VAL_MASK             ((uint32_t)((uint32_t)0xFFFF << TPM_CnV_VAL_SHIFT))
#define TPM_CnV_VAL(x)               ((uint32_t)(((uint32_t)(x) << TPM_CnV_VAL_SHIFT) & TPM_CnV_VAL_MASK))

/*********  Bits definition for TPM_STATUS register  ************/
#define TPM_STATUS_TOF               ((uint32_t)0x100)  /*!< Timer Overflow Flag */
#define TPM_STATUS_CH5F              ((uint32_t)0x20)   /*!< Channel 5 Flag */
#define TPM_STATUS_CH4F              ((uint32_t)0x10)   /*!< Channel 4 Flag */
#define TPM_STATUS_CH3F              ((uint32_t)0x8)    /*!< Channel 3 Flag */
#define TPM_STATUS_CH2F              ((uint32_t)0x4)    /*!< Channel 2 Flag */
#define TPM_STATUS_CH1F              ((uint32_t)0x2)    /*!< Channel 1 Flag */
#define TPM_STATUS_CH0F              ((uint32_t)0x1)    /*!< Channel 0 Flag */

/**********  Bits definition for TPM_CONF register  *************/
#define TPM_CONF_TRGSEL_SHIFT        24                 /*!< Trigger Select */
#define TPM_CONF_TRGSEL_MASK         ((uint32_t)((uint32_t)0xF << TPM_CONF_TRGSEL_SHIFT))
#define TPM_CONF_TRGSEL(x)           ((uint32_t)(((uint32_t)(x) << TPM_CONF_TRGSEL_SHIFT) & TPM_CONF_TRGSEL_MASK))
#define TPM_CONF_CROT                ((uint32_t)0x40000) /*!< Counter Reload On Trigger */
#define TPM_CONF_CSOO                ((uint32_t)0x20000) /*!< Counter Stop On Overflow */
#define TPM_CONF_CSOT                ((uint32_t)0x10000) /*!< Counter Start on Trigger */
#define TPM_CONF_GTBEEN              ((uint32_t)0x200)  /*!< Global time base enable */
#define TPM_CONF_DBGMODE_SHIFT       6                  /*!< Debug Mode */
#define TPM_CONF_DBGMODE_MASK        ((uint32_t)((uint32_t)0x3 << TPM_CONF_DBGMODE_SHIFT))
#define TPM_CONF_DBGMODE(x)          ((uint32_t)(((uint32_t)(x) << TPM_CONF_DBGMODE_SHIFT) & TPM_CONF_DBGMODE_MASK))
#define TPM_CONF_DOZEEN              ((uint32_t)0x20)   /*!< Doze Enable */

/****************************************************************/
/*                                                              */
/*                         USB OTG                              */
/*                                                              */
/****************************************************************/

/********  Bits definition for USBx_STAT register  *************/
#define USBx_STAT_ENDP_MASK         ((uint8_t)0xF0) /*!< Endpoint address mask*/
#define USBx_STAT_ENDP_SHIFT        ((uint8_t)0x04) /*!< Endpoint address shift*/
#define USBx_STAT_TX_MASK           ((uint8_t)0x08) /*!< Transmit indicator mask*/
#define USBx_STAT_TX_SHIFT          ((uint8_t)0x03) /*!< Transmit indicator shift*/
#define USBx_STAT_ODD_MASK          ((uint8_t)0x04) /*!< EVEN/ODD bank indicator mask*/
#define USBx_STAT_ODD_SHIFT         ((uint8_t)0x02) /*!< EVEN/ODD bank indicator shift */

/********  Bits definition for USBx_ISTAT register  *************/
#define USBx_ISTAT_STALL             ((uint8_t)0x80) /*!< Stall interrupt */
#define USBx_ISTAT_ATTACH            ((uint8_t)0x40) /*!< Attach interrupt */
#define USBx_ISTAT_RESUME            ((uint8_t)0x20) /*!< Signal remote wakeup on the bus */
#define USBx_ISTAT_SLEEP             ((uint8_t)0x10) /*!< Detected bus idle for 3ms */
#define USBx_ISTAT_TOKDNE            ((uint8_t)0x08) /*!< Completed processing of current token */
#define USBx_ISTAT_SOFTOK            ((uint8_t)0x04) /*!< Received start of frame */
#define USBx_ISTAT_ERROR             ((uint8_t)0x02) /*!< Error (must check ERRSTAT!) */
#define USBx_ISTAT_USBRST            ((uint8_t)0x01) /*!< USB reset detected */

/********  Bits definition for USBx_ERRSTAT register  ***********/
#define USBx_ERRSTAT_BTSERR          ((uint8_t)0x80) /*!< Bit stuff error detected */
#define USBx_ERRSTAT_DMAERR          ((uint8_t)0x20) /*!< DMA request was not given */
#define USBx_ERRSTAT_BTOERR          ((uint8_t)0x10) /*!< BUS turnaround timeout error */
#define USBx_ERRSTAT_DFN8            ((uint8_t)0x08) /*!< Received data not 8-bit sized */
#define USBx_ERRSTAT_CRC16           ((uint8_t)0x04) /*!< Packet with CRC16 error */
#define USBx_ERRSTAT_CRC5EOF         ((uint8_t)0x02) /*!< CRC5 (device) or EOF (host) error */
#define USBx_ERRSTAT_PIDERR          ((uint8_t)0x01) /*!< PID check field fail */

/******** Bits definition for USBx_CTL register *****************/
#define USBx_CTL_JSTATE              ((uint8_t)0x80) /*!< Live USB differential receiver JSTATE signal */
#define USBx_CTL_SE0                 ((uint8_t)0x40) /*!< Live USB single ended zero signal */
#define USBx_CTL_TXSUSPENDTOKENBUS   ((uint8_t)0x20) /*!<  */
#define USBx_CTL_RESET               ((uint8_t)0x10) /*!< Generates an USB reset signal (host mode) */
#define USBx_CTL_HOSTMODEEN          ((uint8_t)0x08) /*!< Operate in Host mode */
#define USBx_CTL_RESUME              ((uint8_t)0x04) /*!< Executes resume signaling */
#define USBx_CTL_ODDRST              ((uint8_t)0x02) /*!< Reset all BDT ODD ping/pong bits */
#define USBx_CTL_USBENSOFEN          ((uint8_t)0x01) /*!< USB Enable! */

/******** Bits definition for USBx_INTEN register ***************/
#define USBx_INTEN_STALLEN           ((uint8_t)0x80) /*!< STALL interrupt enable */
#define USBx_INTEN_ATTACHEN          ((uint8_t)0x40) /*!< ATTACH interrupt enable */
#define USBx_INTEN_RESUMEEN          ((uint8_t)0x20) /*!< RESUME interrupt enable */
#define USBx_INTEN_SLEEPEN           ((uint8_t)0x10) /*!< SLEEP interrupt enable */
#define USBx_INTEN_TOKDNEEN          ((uint8_t)0x08) /*!< TOKDNE interrupt enable */
#define USBx_INTEN_SOFTOKEN          ((uint8_t)0x04) /*!< SOFTOK interrupt enable */
#define USBx_INTEN_ERROREN           ((uint8_t)0x02) /*!< ERROR interrupt enable */
#define USBx_INTEN_USBRSTEN          ((uint8_t)0x01) /*!< USBRST interrupt enable */

/******** Bits definition for USBx_ENDPTn register **************/
#define USBx_ENDPTn_HOSTWOHUB        ((uint8_t)0x80)
#define USBx_ENDPTn_RETRYDIS         ((uint8_t)0x40)
#define USBx_ENDPTn_EPCTLDIS         ((uint8_t)0x10) /*!< Disables control transfers */
#define USBx_ENDPTn_EPRXEN           ((uint8_t)0x08) /*!< Enable RX transfers */
#define USBx_ENDPTn_EPTXEN           ((uint8_t)0x04) /*!< Enable TX transfers */
#define USBx_ENDPTn_EPSTALL          ((uint8_t)0x02) /*!< Endpoint is called and in STALL */
#define USBx_ENDPTn_EPHSHK           ((uint8_t)0x01) /*!< Enable handshaking during transaction */

/******** Bits definition for USBx_CTRL register ****************/
#define USBx_CTRL_SUSP               ((uint8_t)0x80) /*!< USB transceiver in suspend state */
#define USBx_CTRL_PDE                ((uint8_t)0x40) /*!< Enable weak pull-downs */

/******** Bits definition for USBx_USBTRC0 register *************/
#define USBx_USBTRC0_USBRESET        ((uint8_t)0x80) /*!< USB reset */
#define USBx_USBTRC0_USBRESMEN       ((uint8_t)0x20) /*!< Asynchronous resume interrupt enable */
#define USBx_USBTRC0_SYNC_DET        ((uint8_t)0x02) /*!< Synchronous USB interrupt detect */
#define USBx_USBTRC0_USB_RESUME_INT  ((uint8_t)0x01) /*!< USB asynchronous interrupt */

/******** Bits definition for USBx_CONTROL register *************/
#define USBx_CONTROL_DPPULLUPNONOTG  ((uint8_t)0x10) /*!< Control pull-ups in device mode */

#endif /* _KL26Z_H_ */