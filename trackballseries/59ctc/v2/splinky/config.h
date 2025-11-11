/*
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Handedness. */
#define MASTER_RIGHT

// To use the handedness pin, resistors need to be installed on the adapter PCB.
// If so, uncomment the following code, and undefine MASTER_RIGHT above.
// #define SPLIT_HAND_PIN GP15
// #define SPLIT_HAND_PIN_LOW_IS_LEFT  // High -> right, Low -> left.

/* VBUS detection. */
#define USB_VBUS_PIN GP19

/* SPI & PMW3360 settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define PMW33XX_CS_PIN GP16

/* Reset. */
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP1
#define SERIAL_USART_RX_PIN GP0
// TX 마스터 핀은 RX 슬레이브의 핀과 연결하고, RX 마스터 핀은 TX 슬레이브 핀과 연결되어야 합니다.
// 이 설정은 내부적으로만 교체되어 실제 PCB를 바꿀 필요가 없습니다.
#define SERIAL_USART_PIN_SWAP

#define TAP_CODE_DELAY 10

#ifdef OLED_ENABLE
/* QMK 분할 전송을 사용할 때 현재 레이어 상태가 슬레이브에 전달되도록 합니다. */
#define SPLIT_LAYER_STATE_ENABLE
/* QMK 분할 전송을 사용할 때 캡스/넘/스크롤 상태 표시기가 슬레이브에도 반영되도록 합니다. */
#define SPLIT_LED_STATE_ENABLE
/* QMK 분할 전송을 사용할 때 현재 modifier 상태(정상, 약화, 단타)가 슬레이브에 전달됩니다. */
#define SPLIT_MODS_ENABLE
/* 양쪽 OLED의 켜짐/꺼짐 상태를 동기화합니다. */
#define SPLIT_OLED_ENABLE
/* QMK 분할 전송을 사용할 때 현재 WPM이 슬레이브에서 보여지도록 합니다. */
#define SPLIT_WPM_ENABLE
#define OLED_FONT_H "keyboards/trackballseries/59ctc/keymaps/via/glcdfont.c"
#define OLED_TIMEOUT 50000
#endif

// 슬레이브가 절전 모드에서 깨어나지 않는 문제를 해결합니다.
//#define FORCED_SYNC_THROTTLE_MS 100
//#define CHARYBDIS_CONFIG_SYNC
