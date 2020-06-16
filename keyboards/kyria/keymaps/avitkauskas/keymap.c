/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "keymap_lithuanian_alvis_iso.h"

enum layers {
    _BASE = 0,
    _NAT,
    _NAV,
    _ADJ
};

enum custom_keycodes {
    CK_LPRN = SAFE_RANGE,
    CK_RPRN,
    CK_QUES,
    CK_MINS,
    CK_LT,
    CK_GT,
    CK_AND,
    CK_OR
};

// For the CA_CC_CV (Select all, copy, paste)
enum {
    CA_CC_CV = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Modified Colemak
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ Esc │  Q  │  W  │  F  │  P  │  G  │                          │  J  │  L  │  U  │  Y  │ ( / │ ) \ │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │ BS  │  A  │  S  │  R  │  T  │  D  │                          │  K  │  N  │  E  │  I  │  O  │ ' " │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐  ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │A/C/P│  Z  │  X  │  C  │  V  │  B  │ Alt │Ctrl │  │Ctrl │ Alt │  M  │  H  │ , ; │ . : │ ? ! │ - _ │
 * └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │ Adj │ Cmd │     │CLock│ Tab │  │Enter│Space│     │ Cmd │ Nav │
 *                   │     │     │ Nat │Shift│     │  │     │Shift│ Nat │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
 */
    [_BASE] = LAYOUT(
      KC_ESC,       LT_Q, LT_W, LT_F, LT_P, LT_G,                                                               LT_J, LT_L, LT_U,    LT_Y,   CK_LPRN, CK_RPRN,
      KC_BSPC,      LT_A, LT_S, LT_R, LT_T, LT_D,                                                               LT_K, LT_N, LT_E,    LT_I,   LT_O,    LT_QUOT,
      TD(CA_CC_CV), LT_Z, LT_X, LT_C, LT_V, LT_B, OSM(MOD_LALT), OSM(MOD_LCTL),   OSM(MOD_LCTL), OSM(MOD_LALT), LT_M, LT_H, LT_COMM, LT_DOT, CK_QUES, CK_MINS,
                     TG(_ADJ), OSM(MOD_LGUI), OSL(_NAT), OSM(MOD_LSFT), KC_TAB,   KC_ENT, SFT_T(KC_SPC), OSL(_NAT), OSM(MOD_LGUI), TG(_NAV)
    ),
/*
 * National Layer: National symbols, numbers and special characters
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │  @  │  1  │  3  │  5  │  7  │  9  │                          │  2  │  4  │  6  │  8  │  0  │  =  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  Ą  │  Š  │  Ū  │  Ž  │ < { │                          │ > } │  Ų  │  Ė  │  Į  │  +  │  -  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐  ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  #  │  %  │ & ~ │ | ^ │  Č  │  [  │  ¡  │     │  │     │  ¿  │  ]  │  Ę  │  „  │  “  │  *  │  /  │
 * └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │     │     │     │     │     │  │     │     │     │     │     │
 *                   │     │     │     │     │     │  │     │     │     │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
 */
    [_NAT] = LAYOUT(
        LT_AT,   LT_1,    LT_3,    LT_5,    LT_7,    LT_9,                                          LT_2,    LT_4,    LT_6,    LT_8,    LT_0,    LT_EQL,
        _______, LT_AOGO, LT_SCAR, LT_UMAC, LT_ZCAR, CK_LT,                                         CK_GT,   LT_UOGO, LT_EDOT, LT_IOGO, LT_PLUS, LT_MINS,
        LT_HASH, LT_PERC, CK_AND,  CK_OR,   LT_CCAR, LT_LBRC, LT_IEXL, _______,   _______, LT_IQUE, LT_RBRC, LT_EOGO, LT_DQL9, LT_DQH6, LT_ASTR, LT_SLSH,
                                   _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),
/*
* Navigation Layer: National symbols, numbers and special characters
*
* ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┐
* │ XXX │ XXX │ Mw↑ │ Ms↑ │ Mw↓ │ XXX │                          │ XXX │ Pg↑ │  ↑  │ Pg↓ │ XXX │ XXX │
* ├─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┤
* │     │ XXX │ Ms← │ Ms↓ │ Ms→ │ XXX │                          │ XXX │  ←  │  ↓  │  →  │ XXX │ XXX │
* ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐  ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
* │     │ XXX │ XXX │ XXX │ XXX │ XXX │     │     │  │     │     │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
* └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
*                   │     │     │     │ Mb1 │     │  │ Mb2 │ Mb3 │     │     │     │
*                   │     │     │     │     │     │  │     │     │     │     │     │
*                   └─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
*/
    [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,                                       XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                                       XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
                                 _______, _______, _______, KC_BTN1, _______,   KC_BTN2, KC_BTN3, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJ] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
///*
// * Layer:
// *
// * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┐
// * │     │     │     │     │     │     │                          │     │     │     │     │     │     │
// * ├─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┤
// * │     │     │     │     │     │     │                          │     │     │     │     │     │     │
// * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐  ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// * │     │     │     │     │     │     │     │     │  │     │     │     │     │     │     │     │     │
// * └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
// *                   │     │     │     │     │     │  │     │     │     │     │     │
// *                   │     │     │     │     │     │  │     │     │     │     │     │
// *                   └─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
// */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case CK_LPRN:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(LT_5);
                } else {
                    add_mods(MOD_MASK_SHIFT);
                    register_code(LT_9);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_5);
                } else {
                    unregister_code(LT_9);
                    del_mods(MOD_MASK_SHIFT);
                }
            }
            return false;
        case CK_RPRN:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_IOGO);
                    add_mods(MOD_MASK_SHIFT);
                } else {
                    add_mods(MOD_MASK_SHIFT);
                    register_code(LT_0);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_IOGO);
                    del_mods(MOD_MASK_ALT);
                } else {
                    unregister_code(LT_0);
                    del_mods(MOD_MASK_SHIFT);
                }
            }
            return false;
        case CK_QUES:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(LT_1);
                } else {
                    add_mods(MOD_MASK_SHIFT);
                    register_code(LT_3);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_1);
                } else {
                    unregister_code(LT_3);
                    del_mods(MOD_MASK_SHIFT);
                }
            }
            return false;
        case CK_MINS:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_EDOT);
                    add_mods(MOD_MASK_SHIFT);
                } else {
                    add_mods(MOD_MASK_SHIFT);
                    register_code(LT_7);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_EDOT);
                    del_mods(MOD_MASK_ALT);
                } else {
                    unregister_code(LT_7);
                    del_mods(MOD_MASK_SHIFT);
                }
            }
            return false;
        case CK_LT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_UOGO);
                    add_mods(MOD_MASK_SHIFT);
                } else {
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_UMAC);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_UOGO);
                    del_mods(MOD_MASK_ALT);
                } else {
                    unregister_code(LT_UMAC);
                    del_mods(MOD_MASK_ALT);
                }
            }
            return false;
        case CK_GT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_ZCAR);
                    add_mods(MOD_MASK_SHIFT);
                } else {
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_EOGO);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_ZCAR);
                    del_mods(MOD_MASK_ALT);
                } else {
                    unregister_code(LT_EOGO);
                    del_mods(MOD_MASK_ALT);
                }
            }
            return false;
        case CK_AND:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_AOGO);
                    add_mods(MOD_MASK_SHIFT);
                } else {
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_7);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_AOGO);
                    del_mods(MOD_MASK_ALT);
                } else {
                    unregister_code(LT_7);
                    del_mods(MOD_MASK_ALT);
                }
            }
            return false;
        case CK_OR:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_6);
                    add_mods(MOD_MASK_SHIFT);
                } else {
                    add_mods(MOD_MASK_ALT);
                    register_code(LT_8);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(LT_6);
                    del_mods(MOD_MASK_ALT);
                } else {
                    unregister_code(LT_8);
                    del_mods(MOD_MASK_ALT);
                }
            }
            return false;
        default:
            return true;
    }
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.2\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _NAT:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif

// Tapdance states
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// track the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    }
    if (state->count == 2) {
        return DOUBLE_SINGLE_TAP;
    }
    else {
        return 3; // any number higher than the maximum state value you return above
    }
}

// handle the possible states for each tapdance keycode you define
void CA_CC_CV_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            tap_code16(C(LT_C));
            break;
        case SINGLE_HOLD:
            tap_code16(C(LT_A));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(C(LT_V));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL)
};
// Just add TD(CA_CC_CV) anywhere in your layout to use
