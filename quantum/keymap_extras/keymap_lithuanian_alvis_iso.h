/* Copyright 2020
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

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ Č │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ Ū │ Ę │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ Š │ Ų │ Ž │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ A │ S │ R │ T │ D │ K │ N │ E │ I │ O │ ' │ Į │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ Ą │ Z │ X │ C │ V │ B │ M │ H │ , │ . │ Ė │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define LT_CCAR KC_GRV  // Č
#define LT_1    KC_1    // 1
#define LT_2    KC_2    // 2
#define LT_3    KC_3    // 3
#define LT_4    KC_4    // 4
#define LT_5    KC_5    // 5
#define LT_6    KC_6    // 6
#define LT_7    KC_7    // 7
#define LT_8    KC_8    // 8
#define LT_9    KC_9    // 9
#define LT_0    KC_0    // 0
#define LT_UMAC KC_MINS // Ū
#define LT_EOGO KC_EQL  // Ę
// Row 2
#define LT_Q    KC_Q    // Q
#define LT_W    KC_W    // W
#define LT_F    KC_E    // F
#define LT_P    KC_R    // P
#define LT_G    KC_T    // G
#define LT_J    KC_Y    // J
#define LT_L    KC_U    // L
#define LT_U    KC_I    // U
#define LT_Y    KC_O    // Y
#define LT_SCAR KC_P    // Š
#define LT_UOGO KC_LBRC // Ų
#define LT_ZCAR KC_RBRC // Ž
// Row 3
#define LT_A    KC_A    // A
#define LT_S    KC_S    // S
#define LT_R    KC_D    // R
#define LT_T    KC_F    // T
#define LT_D    KC_G    // D
#define LT_K    KC_H    // K
#define LT_N    KC_J    // N
#define LT_E    KC_K    // E
#define LT_I    KC_L    // I
#define LT_O    KC_SCLN // O
#define LT_QUOT KC_QUOT // '
#define LT_IOGO KC_NUHS // Į
// Row 4
#define LT_AOGO KC_NUBS // Ą
#define LT_Z    KC_Z    // Z
#define LT_X    KC_X    // X
#define LT_C    KC_C    // C
#define LT_V    KC_V    // V
#define LT_B    KC_B    // B
#define LT_M    KC_N    // M
#define LT_H    KC_M    // H
#define LT_COMM KC_COMM // ,
#define LT_DOT  KC_DOT  // .
#define LT_EDOT KC_SLSH // Ė

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ ! │ @ │ ? │ * │ / │ + │ - │ = │ ( │ ) │   │   │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ " │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │ ; │ : │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define LT_EXLM S(LT_1)    // !
#define LT_AT   S(LT_2)    // @
#define LT_QUES S(LT_3)    // ?
#define LT_ASTR S(LT_4)    // *
#define LT_SLSH S(LT_5)    // /
#define LT_PLUS S(LT_6)    // +
#define LT_MINS S(LT_7)    // -
#define LT_EQL  S(LT_8)    // =
#define LT_LPRN S(LT_9)    // (
#define LT_RPRN S(LT_0)    // )
// Row 3
#define LT_DQUO S(LT_QUOT) // "
// Row 4
#define LT_COLN S(LT_DOT)  // :
#define LT_SCLN S(LT_COMM) // ;

/* Alt symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ ¡ │ # │ ¿ │ € │ % │ ^ │ & │ | │ [ │ ] │ < │ > │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │ ↕ │ ↔ │ ← │ ↓ │ ↑ │ → │ { │ } │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │ $ │   │   │   │   │ – │ € │   │   │ ` │ \ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ ~ │   │   │   │   │   │ — │   │ „ │ “ │ _ │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define LT_IEXL A(LT_1)    // ¡
#define LT_HASH A(LT_2)    // #
#define LT_IQUE A(LT_3)    // ¿
#define LT_EURO A(LT_4)    // €
#define LT_PERC A(LT_5)    // %
#define LT_CIRC A(LT_6)    // ^
#define LT_AMPR A(LT_7)    // &
#define LT_PIPE A(LT_8)    // |
#define LT_LBRC A(LT_9)    // [
#define LT_RBRC A(LT_0)    // ]
#define LT_LABK A(LT_UMAC) // <
#define LT_RABK A(LT_EOGO) // >
// Row 2
#define LT_UDAR A(LT_G)    // ↕
#define LT_LRAR A(LT_J)    // ↔
#define LT_LARR A(LT_L)    // ←
#define LT_DARR A(LT_U)    // ↓
#define LT_UARR A(LT_Y)    // ↑
#define LT_RARR A(LT_SCAR) // →
#define LT_LCBR A(LT_UOGO) // {
#define LT_RCBR A(LT_ZCAR) // }
// Row 3
#define LT_DLR  A(LT_S)    // $
#define LT_NDSH A(LT_N)    // –
#define LT_EURO A(LT_E)    // €
#define LT_GRV  A(LT_QUOT) // `
#define LT_BSLS A(LT_IOGO) // (backslash)
// Row 4
#define LT_TILD A(LT_AOGO) // ~
#define LT_MDSH A(LT_M)    // —
#define LT_DL9  A(LT_COMM) // „
#define LT_DH6  A(LT_DOT)  // “
#define LT_UNDS A(LT_EDOT) // _
