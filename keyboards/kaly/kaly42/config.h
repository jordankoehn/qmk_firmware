// Copyright 2023 Kael Soares Augusto (@Dwctor)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.

#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 220

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
/*#define QUICK_TAP_TERM 0*/

#define TAPPING_TOGGLE 2
#define ONESHOT_TAP_TOGGLE 2

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

// #define AUTO_SHIFT_MODIFIERS

#define MOUSEKEY_MAX_SPEED 2
#define MOUSEKEY_TIME_TO_MAX 45
