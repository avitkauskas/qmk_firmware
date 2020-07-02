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
#include <string.h>
#include "keymap_lithuanian_alvis_iso.h"

enum layers {
    _BASE = 0,
    _NAT,
    _NAV,
    _ADJ
};

enum custom_keycodes {
    MY_LPRN = SAFE_RANGE,
    MY_RPRN,
    MY_QUES,
    MY_MINS,
    MY_LCBR,
    MY_RCBR,
    MY_LBRC,
    MY_RBRC
};

// For the CA_CC_CV (Select all, copy, paste)
enum {
    CA_CC_CV = 0,
    SPC_NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: Modified Colemak
     *
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │ Esc │  Q  │  W  │  D  │  P  │  F  │                          │  J  │  L  │  U  │  Y  │ ( / │ ) \ │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │ BS  │  A  │  S  │  R  │  T  │  G  │                          │  K  │  N  │  E  │  I  │  O  │ ' " │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐  ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │A/C/P│  Z  │  X  │  C  │  V  │  B  │  {  │  [  │  │  ]  │  }  │  M  │  H  │ , ; │ . : │ ? ! │ - _ │
     * │     │     │     │     │     │     │ Alt │ Cmd │  │Ctrl │ Alt │     │     │     │     │     │     │
     * └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │ Adj │ Cmd │ Nat │CLock│ Tab │  │Enter│Space│Space│ Cmd │     │
     *                   │     │     │     │Shift│ Nav │  │ Nav │ Nav │     │     │     │
     *                   └─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
     */
    [_BASE] = LAYOUT(
      KC_ESC,       LT_Q, LT_W, LT_D, LT_P, LT_F,                                              LT_J, LT_L, LT_U,    LT_Y,   MY_LPRN, MY_RPRN,
      KC_BSPC,      LT_A, LT_S, LT_R, LT_T, LT_G,                                              LT_K, LT_N, LT_E,    LT_I,   LT_O,    LT_QUOT,
      TD(CA_CC_CV), LT_Z, LT_X, LT_C, LT_V, LT_B, MY_LCBR, MY_LBRC,          MY_RBRC, MY_RCBR, LT_M, LT_H, LT_COMM, LT_DOT, MY_QUES, MY_MINS,
      TG(_ADJ), OSM(MOD_LGUI), OSL(_NAT), OSM(MOD_LSFT), LT(_NAV, KC_TAB),   LT(_NAV, KC_ENT), TD(SPC_NAV), KC_SPC, OSM(MOD_LGUI), G(KC_UP)
    ),
/*
 * National Layer: National symbols, numbers and special characters
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │  @  │  5  │  3  │  1  │  7  │  9  │                          │  4  │  2  │  0  │  6  │  8  │  =  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  Ą  │  Š  │  Ū  │  Ž  │  <  │                          │  >  │  Ų  │  Ė  │  Į  │  +  │  -  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐  ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  #  │  %  │  ~  │  ^  │  Č  │  &  │  ¡  │  „  │  │  “  │  ¿  │  |  │  Ę  │     │     │  *  │  /  │
 * └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │     │     │     │     │     │  │     │     │     │     │     │
 *                   │     │     │     │     │     │  │     │     │     │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
 */
    [_NAT] = LAYOUT(
        LT_AT,   LT_5,    LT_3,    LT_1,    LT_7,    LT_9,                                          LT_4,    LT_2,    LT_0,    LT_6,    LT_8,    LT_EQL,
        _______, LT_AOGO, LT_SCAR, LT_UMAC, LT_ZCAR, LT_LABK,                                       LT_RABK, LT_UOGO, LT_EDOT, LT_IOGO, LT_PLUS, LT_MINS,
        LT_HASH, LT_PERC, LT_TILD, LT_CIRC, LT_CCAR, LT_AMPR, LT_IEXL, LT_DQL9,   LT_DQH6, LT_IQUE, LT_PIPE, LT_EOGO, _______, _______, LT_ASTR, LT_SLSH,
                                   _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),
/*
* Navigation Layer: Mouse control and arrows
*
* ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┐
* │     │ XXX │ XXX │ Mw↑ │ Mw↓ │ XXX │                          │ XXX │ Pg↓ │ Pg↑ │ XXX │ XXX │ XXX │
* ├─────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼─────┤
* │     │ Ms← │ Ms← │ Ms↑ │ Ms→ │ XXX │                          │ XXX │  ←  │  ↑  │  →  │  →  │ XXX │
* ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐  ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
* │     │ XXX │ XXX │ Ms↓ │ XXX │ XXX │ Mb3 │     │  │ Mb2 │ Mb1 │ XXX │ XXX │  ↓  │ XXX │ XXX │ XXX │
* └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
*                   │     │     │ Alt │     │     │  │     │     │     │Ctrl │     │
*                   │     │     │     │     │     │  │     │     │     │     │     │
*                   └─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
*/
    [_NAV] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX,                                       XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, KC_MS_L, KC_MS_L, KC_MS_U, KC_MS_R, XXXXXXX,                                       XXXXXXX, KC_LEFT, KC_UP,   KC_RGHT, KC_RGHT, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, KC_MS_D, XXXXXXX, XXXXXXX, KC_BTN3, _______,   KC_BTN2, KC_BTN1, XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,
                           _______, _______, OSM(MOD_LALT), _______, _______,   _______, _______, _______, OSM(MOD_LCTL), _______
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

static bool shift_pressed = false;
static uint16_t my_hash_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    uint8_t one_shot_mods = get_oneshot_mods();
    bool shift_mode = mods & MOD_MASK_SHIFT;
    bool oneshot_shift_mode = one_shot_mods & MOD_MASK_SHIFT;
    bool any_shift_mode = shift_mode | oneshot_shift_mode;

    switch (keycode) {
        case MY_LPRN:
            if (record->event.pressed) {
                shift_pressed = any_shift_mode;
                if (shift_pressed) {
                    register_code(LT_5);
                } else {
                    register_code16(LT_LPRN);
                }
            } else {
                if (shift_pressed) {
                    unregister_code(LT_5);
                } else {
                    unregister_code16(LT_LPRN);
                }
            }
            return false;
        case MY_RPRN:
            if (record->event.pressed) {
                shift_pressed = any_shift_mode;
                if (shift_pressed) {
                    if (shift_mode) {
                        clear_mods();
                        register_code16(LT_BSLS);
                        set_mods(mods);
                    } else {
                        clear_oneshot_mods();
                        register_code16(LT_BSLS);
                        set_oneshot_mods(one_shot_mods & (!MOD_MASK_SHIFT));
                    }
                } else {
                    register_code16(LT_RPRN);
                }
            } else {
                if (shift_pressed) {
                    unregister_code16(LT_BSLS);
                } else {
                    unregister_code16(LT_RPRN);
                }
            }
            return false;
        case MY_QUES:
            if (record->event.pressed) {
                shift_pressed = any_shift_mode;
                if (shift_pressed) {
                    register_code(LT_1);
                } else {
                    register_code16(LT_QUES);
                }
            } else {
                if (shift_pressed) {
                    unregister_code(LT_1);
                } else {
                    unregister_code16(LT_QUES);
                }
            }
            return false;
        case MY_MINS:
            if (record->event.pressed) {
                shift_pressed = any_shift_mode;
                if (shift_pressed) {
                    if (shift_mode) {
                        clear_mods();
                        register_code16(LT_UNDS);
                        set_mods(mods);
                    } else {
                        clear_oneshot_mods();
                        register_code16(LT_UNDS);
                        set_oneshot_mods(one_shot_mods & (!MOD_MASK_SHIFT));
                    }
                } else {
                    register_code16(LT_MINS);
                }
            } else {
                if (shift_pressed) {
                    unregister_code16(LT_UNDS);
                } else {
                    unregister_code16(LT_MINS);
                }
            }
            return false;
        case MY_LCBR:
            if(record->event.pressed) {
                my_hash_timer = timer_read();
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
                    tap_code16(LT_LCBR);
                }
            }
            return false;
        case MY_RCBR:
            if(record->event.pressed) {
                my_hash_timer = timer_read();
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
                    tap_code16(LT_RCBR);
                }
            }
            return false;
        case MY_LBRC:
            if(record->event.pressed) {
                my_hash_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
                    tap_code16(LT_LBRC);
                }
            }
            return false;
        case MY_RBRC:
            if(record->event.pressed) {
                my_hash_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
                if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
                    tap_code16(LT_RBRC);
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
    // QMK Logo
    render_qmk_logo();

    // Host Keyboard Layer Status
    oled_write_P(PSTR("\n  L: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _NAT:
            oled_write_P(PSTR("SYMBOLS\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAVIGATION\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("ADJUSTMENTS\n"), false);
            break;
        default:
            oled_write_P(PSTR("undefined\n"), false);
    }

    uint8_t mods = get_mods() | get_oneshot_mods();
    char mods_str[18] = "";
    if (mods & MOD_MASK_SHIFT) {
        strcat(mods_str, " SFT");
    }
    if (mods & MOD_MASK_CTRL) {
        strcat(mods_str, " CTL");
    }
    if (mods & MOD_MASK_ALT) {
            strcat(mods_str, " ALT");
    }
    if (mods & MOD_MASK_GUI) {
        strcat(mods_str, " CMD");
    }
    if (strcmp(mods_str, "")) {
        oled_write_P(PSTR("\n  M:"), false);
    } else {
        oled_write_P(PSTR("\n"), false);
    }
    strcat(mods_str, "\n");
    oled_write(mods_str, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
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
    DOUBLE_TAP
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
        return DOUBLE_TAP;
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
            tap_code16(G(LT_C));
            break;
        case SINGLE_HOLD:
            tap_code16(A(KC_LEFT));
            tap_code16(S(A(KC_RIGHT)));
            break;
        case DOUBLE_TAP:
            tap_code16(G(LT_V));
    }
}

static bool was_held = false;
void SPC_NAV_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            tap_code(KC_SPC);
            break;
        case SINGLE_HOLD:
            was_held = true;
            layer_on(_NAV);
            break;
        case DOUBLE_TAP:
            layer_invert(_NAV);
    }
}

void SPC_NAV_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (was_held) {
        layer_off(_NAV);
        was_held = false;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
    [SPC_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, SPC_NAV_finished, SPC_NAV_reset)
};
