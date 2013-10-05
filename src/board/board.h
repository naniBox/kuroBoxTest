/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for naniBox.com / kuroBox_v11 board.
 */

/*
 * Board identifier.
 */
#define BOARD_NANIBOX_COM__KUROBOX_V11
#define BOARD_NAME                  "naniBox.com / kuroBox_v11"


/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                32768
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                26000000
#endif


/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   330

/*
 * MCU type as defined in the ST header file stm32f4xx.h.
 */
#define STM32F4XX

/*
 * IO pins assignments.
 */
#define GPIOA_BTN0                  0
#define GPIOA_BTN1                  1
#define GPIOA_USART2_TX             2
#define GPIOA_USART2_RX             3
#define GPIOA__A04                  4
#define GPIOA__A05                  5
#define GPIOA__A06                  6
#define GPIOA__A07                  7
#define GPIOA__A08                  8
#define GPIOA_LTC_TTL               9
#define GPIOA_USB_ID                10
#define GPIOA_USB_DM                11
#define GPIOA_USB_DP                12
#define GPIOA_SWDIO                 13
#define GPIOA_SWCLK                 14
#define GPIOA_LED3                  15

#define GPIOB_LED1                  0
#define GPIOB_LED2                  1
#define GPIOB_BOOT1                 2
#define GPIOB_SPI1_SCK              3
#define GPIOB_SPI1_MISO             4
#define GPIOB_SPI1_MOSI             5
#define GPIOB_USART1_TX             6
#define GPIOB_USART1_RX             7
#define GPIOB__B08                  8
#define GPIOB_L1_PWR                9
#define GPIOB_L1_I2C2_SCL           10
#define GPIOB_L1_I2C2_SDA           11
#define GPIOB__B12                  12
#define GPIOB_L1_SPI2_SCK           13
#define GPIOB_L1_SPI2_MISO          14
#define GPIOB_L1_SPI2_MOSI          15

#define GPIOC_VIN_TAP               0
#define GPIOC_L1_GPS_RESET          1
#define GPIOC_L1_GPS_EXTINT0        2
#define GPIOC_L1_TIMEPULSE          3
#define GPIOC__C04                  4
#define GPIOC__C05                  5
#define GPIOC_L1_USART6_TX          6
#define GPIOC_L1_USART6_RX          7
#define GPIOC_SDIO_D0               8
#define GPIOC_SDIO_D1               9
#define GPIOC_SDIO_D2               10
#define GPIOC_SDIO_D3               11
#define GPIOC_SDIO_CK               12
#define GPIOC__C13                  13
#define GPIOC_OSC32_IN              14
#define GPIOC_OSC32_OUT             15

#define GPIOD_L1_VN_SYNC_IN         0
#define GPIOD_L1_VN_NSS             1
#define GPIOD_SDIO_CMD              2
#define GPIOD_L1_VN_NRST            3
#define GPIOD_SD_DET                4
#define GPIOD_SD_WP                 5
#define GPIOD_SERIAL1_PWR           6
#define GPIOD_SERIAL1_VALID         7
#define GPIOD_SERIAL1_OC            8
#define GPIOD_SERIAL2_PWR           9
#define GPIOD_SERIAL2_VALID         10
#define GPIOD_SERIAL2_OC            11
#define GPIOD_LCD_LED_DRIVE         12
#define GPIOD__D13                  13
#define GPIOD__D14                  14
#define GPIOD__D15                  15

#define GPIOE__E00                  0
#define GPIOE_EEPROM_NSS            1
#define GPIOE_LCD_A0                2
#define GPIOE_LCD_RST               3
#define GPIOE_LCD_NSS               4
#define GPIOE__E05                  5
#define GPIOE__E06                  6
#define GPIOE__E07                  7
#define GPIOE__E08                  8
#define GPIOE_L1_VN_SYNC_OUT        9
#define GPIOE__E10                  10
#define GPIOE__E11                  11
#define GPIOE__E12                  12
#define GPIOE__E13                  13
#define GPIOE__E14                  14
#define GPIOE__E15                  15

#define GPIOF_NC_0                  0
#define GPIOF_NC_1                  1
#define GPIOF_NC_2                  2
#define GPIOF_NC_3                  3
#define GPIOF_NC_4                  4
#define GPIOF_NC_5                  5
#define GPIOF_NC_6                  6
#define GPIOF_NC_7                  7
#define GPIOF_NC_8                  8
#define GPIOF_NC_9                  9
#define GPIOF_NC_10                 10
#define GPIOF_NC_11                 11
#define GPIOF_NC_12                 12
#define GPIOF_NC_13                 13
#define GPIOF_NC_14                 14
#define GPIOF_NC_15                 15

#define GPIOG_NC_0                  0
#define GPIOG_NC_1                  1
#define GPIOG_NC_2                  2
#define GPIOG_NC_3                  3
#define GPIOG_NC_4                  4
#define GPIOG_NC_5                  5
#define GPIOG_NC_6                  6
#define GPIOG_NC_7                  7
#define GPIOG_NC_8                  8
#define GPIOG_NC_9                  9
#define GPIOG_NC_10                 10
#define GPIOG_NC_11                 11
#define GPIOG_NC_12                 12
#define GPIOG_NC_13                 13
#define GPIOG_NC_14                 14
#define GPIOG_NC_15                 15

#define GPIOH_OSC_IN                0
#define GPIOH_OSC_OUT               1
#define GPIOH_NC_2                  2
#define GPIOH_NC_3                  3
#define GPIOH_NC_4                  4
#define GPIOH_NC_5                  5
#define GPIOH_NC_6                  6
#define GPIOH_NC_7                  7
#define GPIOH_NC_8                  8
#define GPIOH_NC_9                  9
#define GPIOH_NC_10                 10
#define GPIOH_NC_11                 11
#define GPIOH_NC_12                 12
#define GPIOH_NC_13                 13
#define GPIOH_NC_14                 14
#define GPIOH_NC_15                 15

#define GPIOI_NC_0                  0
#define GPIOI_NC_1                  1
#define GPIOI_NC_2                  2
#define GPIOI_NC_3                  3
#define GPIOI_NC_4                  4
#define GPIOI_NC_5                  5
#define GPIOI_NC_6                  6
#define GPIOI_NC_7                  7
#define GPIOI_NC_8                  8
#define GPIOI_NC_9                  9
#define GPIOI_NC_10                 10
#define GPIOI_NC_11                 11
#define GPIOI_NC_12                 12
#define GPIOI_NC_13                 13
#define GPIOI_NC_14                 14
#define GPIOI_NC_15                 15

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2))
#define PIN_OSPEED_25M(n)           (1U << ((n) * 2))
#define PIN_OSPEED_50M(n)           (2U << ((n) * 2))
#define PIN_OSPEED_100M(n)          (3U << ((n) * 2))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2))
#define PIN_AFIO_AF(n, v)           ((v##U) << ((n % 8) * 4))

/*
 * GPIOA setup:
 *
 * PA0  - BTN0                      (input pullup).
 * PA1  - BTN1                      (input pullup).
 * PA2  - USART2_TX                 (alternate 7).
 * PA3  - USART2_RX                 (alternate 7).
 * PA4  - _A04                      (input pullup).
 * PA5  - _A05                      (input pullup).
 * PA6  - _A06                      (input pullup).
 * PA7  - _A07                      (input pullup).
 * PA8  - _A08                      (input pullup).
 * PA9  - LTC_TTL                   (alternate 1).
 * PA10 - USB_ID                    (alternate 10).
 * PA11 - USB_DM                    (alternate 10).
 * PA12 - USB_DP                    (alternate 10).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 * PA15 - LED3                      (output pushpull low).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_BTN0) |           \
                                     PIN_MODE_INPUT(GPIOA_BTN1) |           \
                                     PIN_MODE_ALTERNATE(GPIOA_USART2_TX) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_USART2_RX) |  \
                                     PIN_MODE_INPUT(GPIOA__A04) |           \
                                     PIN_MODE_INPUT(GPIOA__A05) |           \
                                     PIN_MODE_INPUT(GPIOA__A06) |           \
                                     PIN_MODE_INPUT(GPIOA__A07) |           \
                                     PIN_MODE_INPUT(GPIOA__A08) |           \
                                     PIN_MODE_ALTERNATE(GPIOA_LTC_TTL) |    \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_ID) |     \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_DM) |     \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_DP) |     \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_OUTPUT(GPIOA_LED3))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_BTN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_BTN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USART2_TX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USART2_RX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA__A04) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA__A05) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA__A06) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA__A07) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA__A08) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_LTC_TTL) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_ID) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DM) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DP) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_LED3))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_2M(GPIOA_BTN0) |            \
                                     PIN_OSPEED_2M(GPIOA_BTN1) |            \
                                     PIN_OSPEED_100M(GPIOA_USART2_TX) |     \
                                     PIN_OSPEED_100M(GPIOA_USART2_RX) |     \
                                     PIN_OSPEED_2M(GPIOA__A04) |            \
                                     PIN_OSPEED_2M(GPIOA__A05) |            \
                                     PIN_OSPEED_2M(GPIOA__A06) |            \
                                     PIN_OSPEED_2M(GPIOA__A07) |            \
                                     PIN_OSPEED_2M(GPIOA__A08) |            \
                                     PIN_OSPEED_100M(GPIOA_LTC_TTL) |       \
                                     PIN_OSPEED_100M(GPIOA_USB_ID) |        \
                                     PIN_OSPEED_100M(GPIOA_USB_DM) |        \
                                     PIN_OSPEED_100M(GPIOA_USB_DP) |        \
                                     PIN_OSPEED_100M(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_100M(GPIOA_SWCLK) |         \
                                     PIN_OSPEED_25M(GPIOA_LED3))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLUP(GPIOA_BTN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_BTN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_USART2_TX) |    \
                                     PIN_PUPDR_PULLUP(GPIOA_USART2_RX) |    \
                                     PIN_PUPDR_PULLUP(GPIOA__A04) |         \
                                     PIN_PUPDR_PULLUP(GPIOA__A05) |         \
                                     PIN_PUPDR_PULLUP(GPIOA__A06) |         \
                                     PIN_PUPDR_PULLUP(GPIOA__A07) |         \
                                     PIN_PUPDR_PULLUP(GPIOA__A08) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_LTC_TTL) |      \
                                     PIN_PUPDR_PULLUP(GPIOA_USB_ID) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_USB_DM) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_USB_DP) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) |        \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOA_LED3))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_BTN0) |             \
                                     PIN_ODR_HIGH(GPIOA_BTN1) |             \
                                     PIN_ODR_HIGH(GPIOA_USART2_TX) |        \
                                     PIN_ODR_HIGH(GPIOA_USART2_RX) |        \
                                     PIN_ODR_HIGH(GPIOA__A04) |             \
                                     PIN_ODR_HIGH(GPIOA__A05) |             \
                                     PIN_ODR_HIGH(GPIOA__A06) |             \
                                     PIN_ODR_HIGH(GPIOA__A07) |             \
                                     PIN_ODR_HIGH(GPIOA__A08) |             \
                                     PIN_ODR_HIGH(GPIOA_LTC_TTL) |          \
                                     PIN_ODR_HIGH(GPIOA_USB_ID) |           \
                                     PIN_ODR_HIGH(GPIOA_USB_DM) |           \
                                     PIN_ODR_HIGH(GPIOA_USB_DP) |           \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |            \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |            \
                                     PIN_ODR_LOW(GPIOA_LED3))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_BTN0, 0) |           \
                                     PIN_AFIO_AF(GPIOA_BTN1, 0) |           \
                                     PIN_AFIO_AF(GPIOA_USART2_TX, 7) |      \
                                     PIN_AFIO_AF(GPIOA_USART2_RX, 7) |      \
                                     PIN_AFIO_AF(GPIOA__A04, 0) |           \
                                     PIN_AFIO_AF(GPIOA__A05, 0) |           \
                                     PIN_AFIO_AF(GPIOA__A06, 0) |           \
                                     PIN_AFIO_AF(GPIOA__A07, 0))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA__A08, 0) |           \
                                     PIN_AFIO_AF(GPIOA_LTC_TTL, 1) |        \
                                     PIN_AFIO_AF(GPIOA_USB_ID, 10) |        \
                                     PIN_AFIO_AF(GPIOA_USB_DM, 10) |        \
                                     PIN_AFIO_AF(GPIOA_USB_DP, 10) |        \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0) |          \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0) |          \
                                     PIN_AFIO_AF(GPIOA_LED3, 0))

/*
 * GPIOB setup:
 *
 * PB0  - LED1                      (output pushpull low).
 * PB1  - LED2                      (output pushpull low).
 * PB2  - BOOT1                     (input pullup).
 * PB3  - SPI1_SCK                  (alternate 5).
 * PB4  - SPI1_MISO                 (alternate 5).
 * PB5  - SPI1_MOSI                 (alternate 5).
 * PB6  - USART1_TX                 (alternate 7).
 * PB7  - USART1_RX                 (alternate 7).
 * PB8  - _B08                      (input pullup).
 * PB9  - _B09                      (input pullup).
 * PB10 - L1_I2C2_SCL               (alternate 4).
 * PB11 - L1_I2C2_SDA               (alternate 4).
 * PB12 - _B12                      (input pullup).
 * PB13 - L1_SPI2_SCK               (alternate 5).
 * PB14 - L1_SPI2_MISO              (alternate 5).
 * PB15 - L1_SPI2_MOSI              (alternate 5).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_OUTPUT(GPIOB_LED1) |          \
                                     PIN_MODE_OUTPUT(GPIOB_LED2) |          \
                                     PIN_MODE_INPUT(GPIOB_BOOT1) |          \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI1_SCK) |   \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI1_MISO) |  \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI1_MOSI) |  \
                                     PIN_MODE_ALTERNATE(GPIOB_USART1_TX) |  \
                                     PIN_MODE_ALTERNATE(GPIOB_USART1_RX) |  \
                                     PIN_MODE_INPUT(GPIOB__B08) |           \
                                     PIN_MODE_OUTPUT(GPIOB_L1_PWR) |           \
                                     PIN_MODE_ALTERNATE(GPIOB_L1_I2C2_SCL) |\
                                     PIN_MODE_ALTERNATE(GPIOB_L1_I2C2_SDA) |\
                                     PIN_MODE_INPUT(GPIOB__B12) |           \
                                     PIN_MODE_ALTERNATE(GPIOB_L1_SPI2_SCK) |\
                                     PIN_MODE_ALTERNATE(GPIOB_L1_SPI2_MISO) |\
                                     PIN_MODE_ALTERNATE(GPIOB_L1_SPI2_MOSI))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_LED1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LED2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_BOOT1) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI1_SCK) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI1_MISO) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI1_MOSI) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_USART1_TX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_USART1_RX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB__B08) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_L1_PWR) |       \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_L1_I2C2_SCL) |\
                                     PIN_OTYPE_OPENDRAIN(GPIOB_L1_I2C2_SDA) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB__B12) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_L1_SPI2_SCK) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_L1_SPI2_MISO) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_L1_SPI2_MOSI))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_25M(GPIOB_LED1) |           \
                                     PIN_OSPEED_25M(GPIOB_LED2) |           \
                                     PIN_OSPEED_100M(GPIOB_BOOT1) |         \
                                     PIN_OSPEED_100M(GPIOB_SPI1_SCK) |      \
                                     PIN_OSPEED_100M(GPIOB_SPI1_MISO) |     \
                                     PIN_OSPEED_100M(GPIOB_SPI1_MOSI) |     \
                                     PIN_OSPEED_100M(GPIOB_USART1_TX) |     \
                                     PIN_OSPEED_100M(GPIOB_USART1_RX) |     \
                                     PIN_OSPEED_2M(GPIOB__B08) |            \
                                     PIN_OSPEED_2M(GPIOB_L1_PWR) |            \
                                     PIN_OSPEED_100M(GPIOB_L1_I2C2_SCL) |   \
                                     PIN_OSPEED_100M(GPIOB_L1_I2C2_SDA) |   \
                                     PIN_OSPEED_2M(GPIOB__B12) |            \
                                     PIN_OSPEED_100M(GPIOB_L1_SPI2_SCK) |   \
                                     PIN_OSPEED_100M(GPIOB_L1_SPI2_MISO) |  \
                                     PIN_OSPEED_100M(GPIOB_L1_SPI2_MOSI))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOB_LED1) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOB_LED2) |       \
                                     PIN_PUPDR_PULLUP(GPIOB_BOOT1) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_SPI1_SCK) |     \
                                     PIN_PUPDR_PULLUP(GPIOB_SPI1_MISO) |    \
                                     PIN_PUPDR_PULLUP(GPIOB_SPI1_MOSI) |    \
                                     PIN_PUPDR_PULLUP(GPIOB_USART1_TX) |    \
                                     PIN_PUPDR_PULLUP(GPIOB_USART1_RX) |    \
                                     PIN_PUPDR_PULLUP(GPIOB__B08) |         \
                                     PIN_PUPDR_PULLUP(GPIOB_L1_PWR) |         \
                                     PIN_PUPDR_PULLUP(GPIOB_L1_I2C2_SCL) |  \
                                     PIN_PUPDR_PULLUP(GPIOB_L1_I2C2_SDA) |  \
                                     PIN_PUPDR_PULLUP(GPIOB__B12) |         \
                                     PIN_PUPDR_PULLUP(GPIOB_L1_SPI2_SCK) |  \
                                     PIN_PUPDR_PULLUP(GPIOB_L1_SPI2_MISO) | \
                                     PIN_PUPDR_PULLUP(GPIOB_L1_SPI2_MOSI))
#define VAL_GPIOB_ODR               (PIN_ODR_LOW(GPIOB_LED1) |              \
                                     PIN_ODR_LOW(GPIOB_LED2) |              \
                                     PIN_ODR_HIGH(GPIOB_BOOT1) |            \
                                     PIN_ODR_HIGH(GPIOB_SPI1_SCK) |         \
                                     PIN_ODR_HIGH(GPIOB_SPI1_MISO) |        \
                                     PIN_ODR_HIGH(GPIOB_SPI1_MOSI) |        \
                                     PIN_ODR_HIGH(GPIOB_USART1_TX) |        \
                                     PIN_ODR_HIGH(GPIOB_USART1_RX) |        \
                                     PIN_ODR_HIGH(GPIOB__B08) |             \
                                     PIN_ODR_HIGH(GPIOB_L1_PWR) |             \
                                     PIN_ODR_HIGH(GPIOB_L1_I2C2_SCL) |      \
                                     PIN_ODR_HIGH(GPIOB_L1_I2C2_SDA) |      \
                                     PIN_ODR_HIGH(GPIOB__B12) |             \
                                     PIN_ODR_HIGH(GPIOB_L1_SPI2_SCK) |      \
                                     PIN_ODR_HIGH(GPIOB_L1_SPI2_MISO) |     \
                                     PIN_ODR_HIGH(GPIOB_L1_SPI2_MOSI))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_LED1, 0) |           \
                                     PIN_AFIO_AF(GPIOB_LED2, 0) |           \
                                     PIN_AFIO_AF(GPIOB_BOOT1, 0) |          \
                                     PIN_AFIO_AF(GPIOB_SPI1_SCK, 5) |       \
                                     PIN_AFIO_AF(GPIOB_SPI1_MISO, 5) |      \
                                     PIN_AFIO_AF(GPIOB_SPI1_MOSI, 5) |      \
                                     PIN_AFIO_AF(GPIOB_USART1_TX, 7) |      \
                                     PIN_AFIO_AF(GPIOB_USART1_RX, 7))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB__B08, 0) |           \
                                     PIN_AFIO_AF(GPIOB_L1_PWR, 0) |           \
                                     PIN_AFIO_AF(GPIOB_L1_I2C2_SCL, 4) |    \
                                     PIN_AFIO_AF(GPIOB_L1_I2C2_SDA, 4) |    \
                                     PIN_AFIO_AF(GPIOB__B12, 0) |           \
                                     PIN_AFIO_AF(GPIOB_L1_SPI2_SCK, 5) |    \
                                     PIN_AFIO_AF(GPIOB_L1_SPI2_MISO, 5) |   \
                                     PIN_AFIO_AF(GPIOB_L1_SPI2_MOSI, 5))

/*
 * GPIOC setup:
 *
 * PC0  - VIN_TAP                   (analog).
 * PC1  - L1_TIMEPULSE              (input pullup).
 * PC2  - L1_GPS_EXTINT0            (input pullup).
 * PC3  - L1_GPS_RESET              (input pullup).
 * PC4  - _C04                      (input pullup).
 * PC5  - _C05                      (input pullup).
 * PC6  - L1_USART6_TX              (alternate 8).
 * PC7  - L1_USART6_RX              (alternate 8).
 * PC8  - SDIO_D0                   (alternate 12).
 * PC9  - SDIO_D1                   (alternate 12).
 * PC10 - SDIO_D2                   (alternate 12).
 * PC11 - SDIO_D3                   (alternate 12).
 * PC12 - SDIO_CK                   (alternate 12).
 * PC13 - _C13                      (input pullup).
 * PC14 - OSC32_IN                  (input floating).
 * PC15 - OSC32_OUT                 (input floating).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ANALOG(GPIOC_VIN_TAP) |       \
                                     PIN_MODE_INPUT(GPIOC_L1_GPS_RESET) |   \
                                     PIN_MODE_INPUT(GPIOC_L1_GPS_EXTINT0) | \
                                     PIN_MODE_INPUT(GPIOC_L1_TIMEPULSE) |   \
                                     PIN_MODE_INPUT(GPIOC__C04) |           \
                                     PIN_MODE_INPUT(GPIOC__C05) |           \
                                     PIN_MODE_ALTERNATE(GPIOC_L1_USART6_TX) |\
                                     PIN_MODE_ALTERNATE(GPIOC_L1_USART6_RX) |\
                                     PIN_MODE_ALTERNATE(GPIOC_SDIO_D0) |    \
                                     PIN_MODE_ALTERNATE(GPIOC_SDIO_D1) |    \
                                     PIN_MODE_ALTERNATE(GPIOC_SDIO_D2) |    \
                                     PIN_MODE_ALTERNATE(GPIOC_SDIO_D3) |    \
                                     PIN_MODE_ALTERNATE(GPIOC_SDIO_CK) |    \
                                     PIN_MODE_INPUT(GPIOC__C13) |           \
                                     PIN_MODE_INPUT(GPIOC_OSC32_IN) |       \
                                     PIN_MODE_INPUT(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_VIN_TAP) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC_L1_GPS_RESET) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_L1_GPS_EXTINT0) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_L1_TIMEPULSE) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC__C04) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__C05) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_L1_USART6_TX) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_L1_USART6_RX) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D0) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D1) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D2) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D3) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_CK) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC__C13) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_IN) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_100M(GPIOC_VIN_TAP) |       \
                                     PIN_OSPEED_2M(GPIOC_L1_GPS_RESET) |    \
                                     PIN_OSPEED_2M(GPIOC_L1_GPS_EXTINT0) |  \
                                     PIN_OSPEED_2M(GPIOC_L1_TIMEPULSE) |    \
                                     PIN_OSPEED_2M(GPIOC__C04) |            \
                                     PIN_OSPEED_2M(GPIOC__C05) |            \
                                     PIN_OSPEED_100M(GPIOC_L1_USART6_TX) |  \
                                     PIN_OSPEED_100M(GPIOC_L1_USART6_RX) |  \
                                     PIN_OSPEED_100M(GPIOC_SDIO_D0) |       \
                                     PIN_OSPEED_100M(GPIOC_SDIO_D1) |       \
                                     PIN_OSPEED_100M(GPIOC_SDIO_D2) |       \
                                     PIN_OSPEED_100M(GPIOC_SDIO_D3) |       \
                                     PIN_OSPEED_100M(GPIOC_SDIO_CK) |       \
                                     PIN_OSPEED_2M(GPIOC__C13) |            \
                                     PIN_OSPEED_100M(GPIOC_OSC32_IN) |      \
                                     PIN_OSPEED_100M(GPIOC_OSC32_OUT))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLUP(GPIOC_VIN_TAP) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_L1_GPS_RESET) | \
                                     PIN_PUPDR_PULLUP(GPIOC_L1_GPS_EXTINT0) |\
                                     PIN_PUPDR_PULLUP(GPIOC_L1_TIMEPULSE) | \
                                     PIN_PUPDR_PULLUP(GPIOC__C04) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__C05) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_L1_USART6_TX) | \
                                     PIN_PUPDR_PULLUP(GPIOC_L1_USART6_RX) | \
                                     PIN_PUPDR_PULLUP(GPIOC_SDIO_D0) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_SDIO_D1) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_SDIO_D2) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_SDIO_D3) |      \
                                     PIN_PUPDR_PULLUP(GPIOC_SDIO_CK) |      \
                                     PIN_PUPDR_PULLUP(GPIOC__C13) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_IN) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_OUT))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC_VIN_TAP) |          \
                                     PIN_ODR_HIGH(GPIOC_L1_GPS_RESET) |     \
                                     PIN_ODR_HIGH(GPIOC_L1_GPS_EXTINT0) |   \
                                     PIN_ODR_HIGH(GPIOC_L1_TIMEPULSE) |     \
                                     PIN_ODR_HIGH(GPIOC__C04) |             \
                                     PIN_ODR_HIGH(GPIOC__C05) |             \
                                     PIN_ODR_HIGH(GPIOC_L1_USART6_TX) |     \
                                     PIN_ODR_HIGH(GPIOC_L1_USART6_RX) |     \
                                     PIN_ODR_HIGH(GPIOC_SDIO_D0) |          \
                                     PIN_ODR_HIGH(GPIOC_SDIO_D1) |          \
                                     PIN_ODR_HIGH(GPIOC_SDIO_D2) |          \
                                     PIN_ODR_HIGH(GPIOC_SDIO_D3) |          \
                                     PIN_ODR_HIGH(GPIOC_SDIO_CK) |          \
                                     PIN_ODR_HIGH(GPIOC__C13) |             \
                                     PIN_ODR_HIGH(GPIOC_OSC32_IN) |         \
                                     PIN_ODR_HIGH(GPIOC_OSC32_OUT))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_VIN_TAP, 0) |        \
                                     PIN_AFIO_AF(GPIOC_L1_GPS_RESET, 0) |   \
                                     PIN_AFIO_AF(GPIOC_L1_GPS_EXTINT0, 0) | \
                                     PIN_AFIO_AF(GPIOC_L1_TIMEPULSE, 0) |   \
                                     PIN_AFIO_AF(GPIOC__C04, 0) |           \
                                     PIN_AFIO_AF(GPIOC__C05, 0) |           \
                                     PIN_AFIO_AF(GPIOC_L1_USART6_TX, 8) |   \
                                     PIN_AFIO_AF(GPIOC_L1_USART6_RX, 8))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_SDIO_D0, 12) |       \
                                     PIN_AFIO_AF(GPIOC_SDIO_D1, 12) |       \
                                     PIN_AFIO_AF(GPIOC_SDIO_D2, 12) |       \
                                     PIN_AFIO_AF(GPIOC_SDIO_D3, 12) |       \
                                     PIN_AFIO_AF(GPIOC_SDIO_CK, 12) |       \
                                     PIN_AFIO_AF(GPIOC__C13, 0) |           \
                                     PIN_AFIO_AF(GPIOC_OSC32_IN, 0) |       \
                                     PIN_AFIO_AF(GPIOC_OSC32_OUT, 0))

/*
 * GPIOD setup:
 *
 * PD0  - L1_VN_SYNC_IN             (input pullup).
 * PD1  - L1_VN_NSS                 (input pullup).
 * PD2  - SDIO_CMD                  (alternate 12).
 * PD3  - L1_VN_NRST                (input pullup).
 * PD4  - SD_DET                    (input pullup).
 * PD5  - SD_WP                     (input pullup).
 * PD6  - SERIAL2_PWR               (output pushpull minimum).
 * PD7  - SERIAL2_VALID             (input pullup).
 * PD8  - SERIAL2_OC                (input pullup).
 * PD9  - SERIAL1_PWR               (output pushpull minimum).
 * PD10 - SERIAL1_VALID             (input pullup).
 * PD11 - SERIAL1_OC                (input pullup).
 * PD12 - LCD_LED_DRIVE             (output pushpull low).
 * PD13 - _D13                      (input pullup).
 * PD14 - _D14                      (input pullup).
 * PD15 - _D15                      (input pullup).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(GPIOD_L1_VN_SYNC_IN) |  \
                                     PIN_MODE_OUTPUT(GPIOD_L1_VN_NSS) |     \
                                     PIN_MODE_ALTERNATE(GPIOD_SDIO_CMD) |   \
                                     PIN_MODE_INPUT(GPIOD_L1_VN_NRST) |     \
                                     PIN_MODE_INPUT(GPIOD_SD_DET) |         \
                                     PIN_MODE_INPUT(GPIOD_SD_WP) |          \
                                     PIN_MODE_OUTPUT(GPIOD_SERIAL2_PWR) |   \
                                     PIN_MODE_INPUT(GPIOD_SERIAL2_VALID) |  \
                                     PIN_MODE_INPUT(GPIOD_SERIAL2_OC) |     \
                                     PIN_MODE_OUTPUT(GPIOD_SERIAL1_PWR) |   \
                                     PIN_MODE_INPUT(GPIOD_SERIAL1_VALID) |  \
                                     PIN_MODE_INPUT(GPIOD_SERIAL1_OC) |     \
                                     PIN_MODE_OUTPUT(GPIOD_LCD_LED_DRIVE) | \
                                     PIN_MODE_INPUT(GPIOD__D13) |           \
                                     PIN_MODE_INPUT(GPIOD__D14) |           \
                                     PIN_MODE_INPUT(GPIOD__D15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_L1_VN_SYNC_IN) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_L1_VN_NSS) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SDIO_CMD) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOD_L1_VN_NRST) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SD_DET) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SD_WP) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SERIAL2_PWR) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_SERIAL2_VALID) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_SERIAL2_OC) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SERIAL1_PWR) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_SERIAL1_VALID) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_SERIAL1_OC) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_LCD_LED_DRIVE) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD__D13) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD__D14) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD__D15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_2M(GPIOD_L1_VN_SYNC_IN) |   \
                                     PIN_OSPEED_100M(GPIOD_L1_VN_NSS) |       \
                                     PIN_OSPEED_100M(GPIOD_SDIO_CMD) |      \
                                     PIN_OSPEED_2M(GPIOD_L1_VN_NRST) |      \
                                     PIN_OSPEED_2M(GPIOD_SD_DET) |          \
                                     PIN_OSPEED_2M(GPIOD_SD_WP) |           \
                                     PIN_OSPEED_2M(GPIOD_SERIAL2_PWR) |     \
                                     PIN_OSPEED_2M(GPIOD_SERIAL2_VALID) |   \
                                     PIN_OSPEED_2M(GPIOD_SERIAL2_OC) |      \
                                     PIN_OSPEED_2M(GPIOD_SERIAL1_PWR) |     \
                                     PIN_OSPEED_2M(GPIOD_SERIAL1_VALID) |   \
                                     PIN_OSPEED_2M(GPIOD_SERIAL1_OC) |      \
                                     PIN_OSPEED_25M(GPIOD_LCD_LED_DRIVE) |  \
                                     PIN_OSPEED_2M(GPIOD__D13) |            \
                                     PIN_OSPEED_2M(GPIOD__D14) |            \
                                     PIN_OSPEED_2M(GPIOD__D15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLUP(GPIOD_L1_VN_SYNC_IN) |\
                                     PIN_PUPDR_PULLUP(GPIOD_L1_VN_NSS) |    \
                                     PIN_PUPDR_PULLUP(GPIOD_SDIO_CMD) |     \
                                     PIN_PUPDR_PULLUP(GPIOD_L1_VN_NRST) |   \
                                     PIN_PUPDR_PULLUP(GPIOD_SD_DET) |       \
                                     PIN_PUPDR_PULLUP(GPIOD_SD_WP) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_SERIAL2_PWR) |  \
                                     PIN_PUPDR_PULLUP(GPIOD_SERIAL2_VALID) |\
                                     PIN_PUPDR_PULLUP(GPIOD_SERIAL2_OC) |   \
                                     PIN_PUPDR_PULLUP(GPIOD_SERIAL1_PWR) |  \
                                     PIN_PUPDR_PULLUP(GPIOD_SERIAL1_VALID) |\
                                     PIN_PUPDR_PULLUP(GPIOD_SERIAL1_OC) |   \
                                     PIN_PUPDR_PULLDOWN(GPIOD_LCD_LED_DRIVE) |\
                                     PIN_PUPDR_PULLUP(GPIOD__D13) |         \
                                     PIN_PUPDR_PULLUP(GPIOD__D14) |         \
                                     PIN_PUPDR_PULLUP(GPIOD__D15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_L1_VN_SYNC_IN) |    \
                                     PIN_ODR_HIGH(GPIOD_L1_VN_NSS) |        \
                                     PIN_ODR_HIGH(GPIOD_SDIO_CMD) |         \
                                     PIN_ODR_HIGH(GPIOD_L1_VN_NRST) |       \
                                     PIN_ODR_HIGH(GPIOD_SD_DET) |           \
                                     PIN_ODR_HIGH(GPIOD_SD_WP) |            \
                                     PIN_ODR_HIGH(GPIOD_SERIAL2_PWR) |      \
                                     PIN_ODR_HIGH(GPIOD_SERIAL2_VALID) |    \
                                     PIN_ODR_HIGH(GPIOD_SERIAL2_OC) |       \
                                     PIN_ODR_HIGH(GPIOD_SERIAL1_PWR) |      \
                                     PIN_ODR_HIGH(GPIOD_SERIAL1_VALID) |    \
                                     PIN_ODR_HIGH(GPIOD_SERIAL1_OC) |       \
                                     PIN_ODR_HIGH(GPIOD_LCD_LED_DRIVE) |     \
                                     PIN_ODR_HIGH(GPIOD__D13) |             \
                                     PIN_ODR_HIGH(GPIOD__D14) |             \
                                     PIN_ODR_HIGH(GPIOD__D15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_L1_VN_SYNC_IN, 0) |  \
                                     PIN_AFIO_AF(GPIOD_L1_VN_NSS, 0) |      \
                                     PIN_AFIO_AF(GPIOD_SDIO_CMD, 12) |      \
                                     PIN_AFIO_AF(GPIOD_L1_VN_NRST, 0) |     \
                                     PIN_AFIO_AF(GPIOD_SD_DET, 0) |         \
                                     PIN_AFIO_AF(GPIOD_SD_WP, 0) |          \
                                     PIN_AFIO_AF(GPIOD_SERIAL2_PWR, 0) |    \
                                     PIN_AFIO_AF(GPIOD_SERIAL2_VALID, 0))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_SERIAL2_OC, 0) |     \
                                     PIN_AFIO_AF(GPIOD_SERIAL1_PWR, 0) |    \
                                     PIN_AFIO_AF(GPIOD_SERIAL1_VALID, 0) |  \
                                     PIN_AFIO_AF(GPIOD_SERIAL1_OC, 0) |     \
                                     PIN_AFIO_AF(GPIOD_LCD_LED_DRIVE, 0) |  \
                                     PIN_AFIO_AF(GPIOD__D13, 0) |           \
                                     PIN_AFIO_AF(GPIOD__D14, 0) |           \
                                     PIN_AFIO_AF(GPIOD__D15, 0))

/*
 * GPIOE setup:
 *
 * PE0  - _E00                      (input pullup).
 * PE1  - EEPROM_NSS                (output pushpull maximum).
 * PE2  - LCD_A0                    (output pushpull maximum).
 * PE3  - LCD_RST                   (output pushpull maximum).
 * PE4  - LCD_NSS                   (output pushpull maximum).
 * PE5  - _E05                      (input pullup).
 * PE6  - _E06                      (input pullup).
 * PE7  - _E07                      (input pullup).
 * PE8  - _E08                      (input pullup).
 * PE9  - L1_VN_SYNC_OUT            (input pullup).
 * PE10 - _E10                      (input pullup).
 * PE11 - _E11                      (input pullup).
 * PE12 - _E12                      (input pullup).
 * PE13 - _E13                      (input pullup).
 * PE14 - _E14                      (input pullup).
 * PE15 - _E15                      (input pullup).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIOE__E00) |           \
                                     PIN_MODE_OUTPUT(GPIOE_EEPROM_NSS) |    \
                                     PIN_MODE_OUTPUT(GPIOE_LCD_A0) |        \
                                     PIN_MODE_OUTPUT(GPIOE_LCD_RST) |       \
                                     PIN_MODE_OUTPUT(GPIOE_LCD_NSS) |       \
                                     PIN_MODE_INPUT(GPIOE__E05) |           \
                                     PIN_MODE_INPUT(GPIOE__E06) |           \
                                     PIN_MODE_INPUT(GPIOE__E07) |           \
                                     PIN_MODE_INPUT(GPIOE__E08) |           \
                                     PIN_MODE_INPUT(GPIOE_L1_VN_SYNC_OUT) | \
                                     PIN_MODE_INPUT(GPIOE__E10) |           \
                                     PIN_MODE_INPUT(GPIOE__E11) |           \
                                     PIN_MODE_INPUT(GPIOE__E12) |           \
                                     PIN_MODE_INPUT(GPIOE__E13) |           \
                                     PIN_MODE_INPUT(GPIOE__E14) |           \
                                     PIN_MODE_INPUT(GPIOE__E15))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE__E00) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_EEPROM_NSS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LCD_A0) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LCD_RST) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LCD_NSS) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E05) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E06) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E07) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E08) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_L1_VN_SYNC_OUT) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE__E10) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E11) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E12) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E13) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E14) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE__E15))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_2M(GPIOE__E00) |            \
                                     PIN_OSPEED_100M(GPIOE_EEPROM_NSS) |    \
                                     PIN_OSPEED_100M(GPIOE_LCD_A0) |        \
                                     PIN_OSPEED_100M(GPIOE_LCD_RST) |       \
                                     PIN_OSPEED_100M(GPIOE_LCD_NSS) |       \
                                     PIN_OSPEED_2M(GPIOE__E05) |            \
                                     PIN_OSPEED_2M(GPIOE__E06) |            \
                                     PIN_OSPEED_2M(GPIOE__E07) |            \
                                     PIN_OSPEED_2M(GPIOE__E08) |            \
                                     PIN_OSPEED_100M(GPIOE_L1_VN_SYNC_OUT) |\
                                     PIN_OSPEED_2M(GPIOE__E10) |            \
                                     PIN_OSPEED_2M(GPIOE__E11) |            \
                                     PIN_OSPEED_2M(GPIOE__E12) |            \
                                     PIN_OSPEED_2M(GPIOE__E13) |            \
                                     PIN_OSPEED_2M(GPIOE__E14) |            \
                                     PIN_OSPEED_2M(GPIOE__E15))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_PULLUP(GPIOE__E00) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_EEPROM_NSS) |   \
                                     PIN_PUPDR_PULLUP(GPIOE_LCD_A0) |       \
                                     PIN_PUPDR_PULLUP(GPIOE_LCD_RST) |      \
                                     PIN_PUPDR_PULLUP(GPIOE_LCD_NSS) |      \
                                     PIN_PUPDR_PULLUP(GPIOE__E05) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E06) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E07) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E08) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_L1_VN_SYNC_OUT) |\
                                     PIN_PUPDR_PULLUP(GPIOE__E10) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E11) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E12) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E13) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E14) |         \
                                     PIN_PUPDR_PULLUP(GPIOE__E15))
#define VAL_GPIOE_ODR               (PIN_ODR_HIGH(GPIOE__E00) |             \
                                     PIN_ODR_HIGH(GPIOE_EEPROM_NSS) |       \
                                     PIN_ODR_HIGH(GPIOE_LCD_A0) |           \
                                     PIN_ODR_HIGH(GPIOE_LCD_RST) |          \
                                     PIN_ODR_HIGH(GPIOE_LCD_NSS) |          \
                                     PIN_ODR_HIGH(GPIOE__E05) |             \
                                     PIN_ODR_HIGH(GPIOE__E06) |             \
                                     PIN_ODR_HIGH(GPIOE__E07) |             \
                                     PIN_ODR_HIGH(GPIOE__E08) |             \
                                     PIN_ODR_HIGH(GPIOE_L1_VN_SYNC_OUT) |   \
                                     PIN_ODR_HIGH(GPIOE__E10) |             \
                                     PIN_ODR_HIGH(GPIOE__E11) |             \
                                     PIN_ODR_HIGH(GPIOE__E12) |             \
                                     PIN_ODR_HIGH(GPIOE__E13) |             \
                                     PIN_ODR_HIGH(GPIOE__E14) |             \
                                     PIN_ODR_HIGH(GPIOE__E15))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE__E00, 0) |           \
                                     PIN_AFIO_AF(GPIOE_EEPROM_NSS, 0) |     \
                                     PIN_AFIO_AF(GPIOE_LCD_A0, 0) |         \
                                     PIN_AFIO_AF(GPIOE_LCD_RST, 0) |        \
                                     PIN_AFIO_AF(GPIOE_LCD_NSS, 0) |        \
                                     PIN_AFIO_AF(GPIOE__E05, 0) |           \
                                     PIN_AFIO_AF(GPIOE__E06, 0) |           \
                                     PIN_AFIO_AF(GPIOE__E07, 0))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE__E08, 0) |           \
                                     PIN_AFIO_AF(GPIOE_L1_VN_SYNC_OUT, 0) | \
                                     PIN_AFIO_AF(GPIOE__E10, 0) |           \
                                     PIN_AFIO_AF(GPIOE__E11, 0) |           \
                                     PIN_AFIO_AF(GPIOE__E12, 0) |           \
                                     PIN_AFIO_AF(GPIOE__E13, 0) |           \
                                     PIN_AFIO_AF(GPIOE__E14, 0) |           \
                                     PIN_AFIO_AF(GPIOE__E15, 0))

/*
 * GPIOF setup:
 *
 * PF0  - NC_0                      (input pullup).
 * PF1  - NC_1                      (input pullup).
 * PF2  - NC_2                      (input pullup).
 * PF3  - NC_3                      (input pullup).
 * PF4  - NC_4                      (input pullup).
 * PF5  - NC_5                      (input pullup).
 * PF6  - NC_6                      (input pullup).
 * PF7  - NC_7                      (input pullup).
 * PF8  - NC_8                      (input pullup).
 * PF9  - NC_9                      (input pullup).
 * PF10 - NC_10                     (input pullup).
 * PF11 - NC_11                     (input pullup).
 * PF12 - NC_12                     (input pullup).
 * PF13 - NC_13                     (input pullup).
 * PF14 - NC_14                     (input pullup).
 * PF15 - NC_15                     (input pullup).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_NC_0) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_1) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_2) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_3) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_4) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_5) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_6) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_7) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_8) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_9) |           \
                                     PIN_MODE_INPUT(GPIOF_NC_10) |          \
                                     PIN_MODE_INPUT(GPIOF_NC_11) |          \
                                     PIN_MODE_INPUT(GPIOF_NC_12) |          \
                                     PIN_MODE_INPUT(GPIOF_NC_13) |          \
                                     PIN_MODE_INPUT(GPIOF_NC_14) |          \
                                     PIN_MODE_INPUT(GPIOF_NC_15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_NC_0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_NC_15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_2M(GPIOF_NC_0) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_1) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_2) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_3) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_4) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_5) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_6) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_7) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_8) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_9) |            \
                                     PIN_OSPEED_2M(GPIOF_NC_10) |           \
                                     PIN_OSPEED_2M(GPIOF_NC_11) |           \
                                     PIN_OSPEED_2M(GPIOF_NC_12) |           \
                                     PIN_OSPEED_2M(GPIOF_NC_13) |           \
                                     PIN_OSPEED_2M(GPIOF_NC_14) |           \
                                     PIN_OSPEED_2M(GPIOF_NC_15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_PULLUP(GPIOF_NC_0) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_1) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_2) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_3) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_4) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_5) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_6) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_7) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_8) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_9) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_10) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_11) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_12) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_13) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_14) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_NC_15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_NC_0) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_1) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_2) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_3) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_4) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_5) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_6) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_7) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_8) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_9) |             \
                                     PIN_ODR_HIGH(GPIOF_NC_10) |            \
                                     PIN_ODR_HIGH(GPIOF_NC_11) |            \
                                     PIN_ODR_HIGH(GPIOF_NC_12) |            \
                                     PIN_ODR_HIGH(GPIOF_NC_13) |            \
                                     PIN_ODR_HIGH(GPIOF_NC_14) |            \
                                     PIN_ODR_HIGH(GPIOF_NC_15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_NC_0, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_1, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_2, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_3, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_4, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_5, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_6, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_7, 0))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_NC_8, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_9, 0) |           \
                                     PIN_AFIO_AF(GPIOF_NC_10, 0) |          \
                                     PIN_AFIO_AF(GPIOF_NC_11, 0) |          \
                                     PIN_AFIO_AF(GPIOF_NC_12, 0) |          \
                                     PIN_AFIO_AF(GPIOF_NC_13, 0) |          \
                                     PIN_AFIO_AF(GPIOF_NC_14, 0) |          \
                                     PIN_AFIO_AF(GPIOF_NC_15, 0))

/*
 * GPIOG setup:
 *
 * PG0  - NC_0                      (input pullup).
 * PG1  - NC_1                      (input pullup).
 * PG2  - NC_2                      (input pullup).
 * PG3  - NC_3                      (input pullup).
 * PG4  - NC_4                      (input pullup).
 * PG5  - NC_5                      (input pullup).
 * PG6  - NC_6                      (input pullup).
 * PG7  - NC_7                      (input pullup).
 * PG8  - NC_8                      (input pullup).
 * PG9  - NC_9                      (input pullup).
 * PG10 - NC_10                     (input pullup).
 * PG11 - NC_11                     (input pullup).
 * PG12 - NC_12                     (input pullup).
 * PG13 - NC_13                     (input pullup).
 * PG14 - NC_14                     (input pullup).
 * PG15 - NC_15                     (input pullup).
 */
#define VAL_GPIOG_MODER             (PIN_MODE_INPUT(GPIOG_NC_0) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_1) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_2) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_3) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_4) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_5) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_6) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_7) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_8) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_9) |           \
                                     PIN_MODE_INPUT(GPIOG_NC_10) |          \
                                     PIN_MODE_INPUT(GPIOG_NC_11) |          \
                                     PIN_MODE_INPUT(GPIOG_NC_12) |          \
                                     PIN_MODE_INPUT(GPIOG_NC_13) |          \
                                     PIN_MODE_INPUT(GPIOG_NC_14) |          \
                                     PIN_MODE_INPUT(GPIOG_NC_15))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOG_NC_0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_NC_15))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_2M(GPIOG_NC_0) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_1) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_2) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_3) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_4) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_5) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_6) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_7) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_8) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_9) |            \
                                     PIN_OSPEED_2M(GPIOG_NC_10) |           \
                                     PIN_OSPEED_2M(GPIOG_NC_11) |           \
                                     PIN_OSPEED_2M(GPIOG_NC_12) |           \
                                     PIN_OSPEED_2M(GPIOG_NC_13) |           \
                                     PIN_OSPEED_2M(GPIOG_NC_14) |           \
                                     PIN_OSPEED_2M(GPIOG_NC_15))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_PULLUP(GPIOG_NC_0) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_1) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_2) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_3) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_4) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_5) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_6) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_7) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_8) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_9) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_10) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_11) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_12) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_13) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_14) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_NC_15))
#define VAL_GPIOG_ODR               (PIN_ODR_HIGH(GPIOG_NC_0) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_1) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_2) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_3) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_4) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_5) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_6) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_7) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_8) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_9) |             \
                                     PIN_ODR_HIGH(GPIOG_NC_10) |            \
                                     PIN_ODR_HIGH(GPIOG_NC_11) |            \
                                     PIN_ODR_HIGH(GPIOG_NC_12) |            \
                                     PIN_ODR_HIGH(GPIOG_NC_13) |            \
                                     PIN_ODR_HIGH(GPIOG_NC_14) |            \
                                     PIN_ODR_HIGH(GPIOG_NC_15))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIOG_NC_0, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_1, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_2, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_3, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_4, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_5, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_6, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_7, 0))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIOG_NC_8, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_9, 0) |           \
                                     PIN_AFIO_AF(GPIOG_NC_10, 0) |          \
                                     PIN_AFIO_AF(GPIOG_NC_11, 0) |          \
                                     PIN_AFIO_AF(GPIOG_NC_12, 0) |          \
                                     PIN_AFIO_AF(GPIOG_NC_13, 0) |          \
                                     PIN_AFIO_AF(GPIOG_NC_14, 0) |          \
                                     PIN_AFIO_AF(GPIOG_NC_15, 0))

/*
 * GPIOH setup:
 *
 * PH0  - OSC_IN                    (input floating).
 * PH1  - OSC_OUT                   (input floating).
 * PH2  - NC_2                      (input pullup).
 * PH3  - NC_3                      (input pullup).
 * PH4  - NC_4                      (input pullup).
 * PH5  - NC_5                      (input pullup).
 * PH6  - NC_6                      (input pullup).
 * PH7  - NC_7                      (input pullup).
 * PH8  - NC_8                      (input pullup).
 * PH9  - NC_9                      (input pullup).
 * PH10 - NC_10                     (input pullup).
 * PH11 - NC_11                     (input pullup).
 * PH12 - NC_12                     (input pullup).
 * PH13 - NC_13                     (input pullup).
 * PH14 - NC_14                     (input pullup).
 * PH15 - NC_15                     (input pullup).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOH_NC_2) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_3) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_4) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_5) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_6) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_7) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_8) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_9) |           \
                                     PIN_MODE_INPUT(GPIOH_NC_10) |          \
                                     PIN_MODE_INPUT(GPIOH_NC_11) |          \
                                     PIN_MODE_INPUT(GPIOH_NC_12) |          \
                                     PIN_MODE_INPUT(GPIOH_NC_13) |          \
                                     PIN_MODE_INPUT(GPIOH_NC_14) |          \
                                     PIN_MODE_INPUT(GPIOH_NC_15))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_NC_15))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_100M(GPIOH_OSC_IN) |        \
                                     PIN_OSPEED_100M(GPIOH_OSC_OUT) |       \
                                     PIN_OSPEED_2M(GPIOH_NC_2) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_3) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_4) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_5) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_6) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_7) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_8) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_9) |            \
                                     PIN_OSPEED_2M(GPIOH_NC_10) |           \
                                     PIN_OSPEED_2M(GPIOH_NC_11) |           \
                                     PIN_OSPEED_2M(GPIOH_NC_12) |           \
                                     PIN_OSPEED_2M(GPIOH_NC_13) |           \
                                     PIN_OSPEED_2M(GPIOH_NC_14) |           \
                                     PIN_OSPEED_2M(GPIOH_NC_15))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT) |    \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_2) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_3) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_4) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_5) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_6) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_7) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_8) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_9) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_10) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_11) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_12) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_13) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_14) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_NC_15))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(GPIOH_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOH_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOH_NC_2) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_3) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_4) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_5) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_6) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_7) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_8) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_9) |             \
                                     PIN_ODR_HIGH(GPIOH_NC_10) |            \
                                     PIN_ODR_HIGH(GPIOH_NC_11) |            \
                                     PIN_ODR_HIGH(GPIOH_NC_12) |            \
                                     PIN_ODR_HIGH(GPIOH_NC_13) |            \
                                     PIN_ODR_HIGH(GPIOH_NC_14) |            \
                                     PIN_ODR_HIGH(GPIOH_NC_15))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0) |         \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0) |        \
                                     PIN_AFIO_AF(GPIOH_NC_2, 0) |           \
                                     PIN_AFIO_AF(GPIOH_NC_3, 0) |           \
                                     PIN_AFIO_AF(GPIOH_NC_4, 0) |           \
                                     PIN_AFIO_AF(GPIOH_NC_5, 0) |           \
                                     PIN_AFIO_AF(GPIOH_NC_6, 0) |           \
                                     PIN_AFIO_AF(GPIOH_NC_7, 0))
#define VAL_GPIOH_AFRH              (PIN_AFIO_AF(GPIOH_NC_8, 0) |           \
                                     PIN_AFIO_AF(GPIOH_NC_9, 0) |           \
                                     PIN_AFIO_AF(GPIOH_NC_10, 0) |          \
                                     PIN_AFIO_AF(GPIOH_NC_11, 0) |          \
                                     PIN_AFIO_AF(GPIOH_NC_12, 0) |          \
                                     PIN_AFIO_AF(GPIOH_NC_13, 0) |          \
                                     PIN_AFIO_AF(GPIOH_NC_14, 0) |          \
                                     PIN_AFIO_AF(GPIOH_NC_15, 0))

/*
 * GPIOI setup:
 *
 * PI0  - NC_0                      (input pullup).
 * PI1  - NC_1                      (input pullup).
 * PI2  - NC_2                      (input pullup).
 * PI3  - NC_3                      (input pullup).
 * PI4  - NC_4                      (input pullup).
 * PI5  - NC_5                      (input pullup).
 * PI6  - NC_6                      (input pullup).
 * PI7  - NC_7                      (input pullup).
 * PI8  - NC_8                      (input pullup).
 * PI9  - NC_9                      (input pullup).
 * PI10 - NC_10                     (input pullup).
 * PI11 - NC_11                     (input pullup).
 * PI12 - NC_12                     (input pullup).
 * PI13 - NC_13                     (input pullup).
 * PI14 - NC_14                     (input pullup).
 * PI15 - NC_15                     (input pullup).
 */
#define VAL_GPIOI_MODER             (PIN_MODE_INPUT(GPIOI_NC_0) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_1) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_2) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_3) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_4) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_5) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_6) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_7) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_8) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_9) |           \
                                     PIN_MODE_INPUT(GPIOI_NC_10) |          \
                                     PIN_MODE_INPUT(GPIOI_NC_11) |          \
                                     PIN_MODE_INPUT(GPIOI_NC_12) |          \
                                     PIN_MODE_INPUT(GPIOI_NC_13) |          \
                                     PIN_MODE_INPUT(GPIOI_NC_14) |          \
                                     PIN_MODE_INPUT(GPIOI_NC_15))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOI_NC_0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_NC_15))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_2M(GPIOI_NC_0) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_1) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_2) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_3) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_4) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_5) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_6) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_7) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_8) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_9) |            \
                                     PIN_OSPEED_2M(GPIOI_NC_10) |           \
                                     PIN_OSPEED_2M(GPIOI_NC_11) |           \
                                     PIN_OSPEED_2M(GPIOI_NC_12) |           \
                                     PIN_OSPEED_2M(GPIOI_NC_13) |           \
                                     PIN_OSPEED_2M(GPIOI_NC_14) |           \
                                     PIN_OSPEED_2M(GPIOI_NC_15))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_PULLUP(GPIOI_NC_0) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_1) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_2) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_3) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_4) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_5) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_6) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_7) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_8) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_9) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_10) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_11) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_12) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_13) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_14) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_NC_15))
#define VAL_GPIOI_ODR               (PIN_ODR_HIGH(GPIOI_NC_0) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_1) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_2) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_3) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_4) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_5) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_6) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_7) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_8) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_9) |             \
                                     PIN_ODR_HIGH(GPIOI_NC_10) |            \
                                     PIN_ODR_HIGH(GPIOI_NC_11) |            \
                                     PIN_ODR_HIGH(GPIOI_NC_12) |            \
                                     PIN_ODR_HIGH(GPIOI_NC_13) |            \
                                     PIN_ODR_HIGH(GPIOI_NC_14) |            \
                                     PIN_ODR_HIGH(GPIOI_NC_15))
#define VAL_GPIOI_AFRL              (PIN_AFIO_AF(GPIOI_NC_0, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_1, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_2, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_3, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_4, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_5, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_6, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_7, 0))
#define VAL_GPIOI_AFRH              (PIN_AFIO_AF(GPIOI_NC_8, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_9, 0) |           \
                                     PIN_AFIO_AF(GPIOI_NC_10, 0) |          \
                                     PIN_AFIO_AF(GPIOI_NC_11, 0) |          \
                                     PIN_AFIO_AF(GPIOI_NC_12, 0) |          \
                                     PIN_AFIO_AF(GPIOI_NC_13, 0) |          \
                                     PIN_AFIO_AF(GPIOI_NC_14, 0) |          \
                                     PIN_AFIO_AF(GPIOI_NC_15, 0))


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
