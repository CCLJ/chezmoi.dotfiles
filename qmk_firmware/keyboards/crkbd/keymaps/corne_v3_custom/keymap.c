/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FKEYS,
    _GAMING,
    _SETTNGS,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------.                    ,--------------------------------------------------------------------------------.
       KC_TAB,         KC_Q,          KC_W,          KC_E,          KC_R,    KC_T,                         KC_Y,          KC_U,          KC_I,          KC_O,             KC_P,  KC_BSPC,
  //|--------+-------------+--------------+--------------+--------------+--------|                    |--------+--------------+--------------+--------------+-----------------+---------|
      KC_LCTL, LALT_T(KC_A),  LGUI_T(KC_S),  LSFT_T(KC_D),  LCTL_T(KC_F),    KC_G,                         KC_H,  RCTL_T(KC_J),  RSFT_T(KC_K),  RGUI_T(KC_L),  RALT_T(KC_SCLN),  KC_QUOT,
  //|--------+-------------+--------------+--------------+--------------+--------|                    |--------+--------------+--------+--------+-----------+-----------------+---------|
      KC_LSFT,         KC_Z,  LALT_T(KC_X),          KC_C,          KC_V,    KC_B,                         KC_N,          KC_M,       KC_COMM,        KC_DOT,          KC_SLSH,  KC_MINS,
  //|--------+-------------+--------------+--------------+--------------+--------+--------|  |--------+--------+--------------+--------------+--------------+--------+--------+---------|
                                                                KC_LGUI, TO(_BASE), KC_SPC,   KC_ENT, TO(_NAV), RSFT_T(KC_ESC)
                                                            //`--------------------------'  `--------------------------'

  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------------------------------.                    ,-------------------------------------------------------------.
       KC_TAB,          KC_GRV,         KC_SLSH,         KC_LBRC,         KC_LPRN,  KC_LEFT,                        KC_UP,    KC_7,          KC_8,    KC_9, KC_BSPC,    KC_DEL,
  //|--------+-----------------+---------------+----------------+----------------+---------|                    |--------+--------+--------------+--------+--------+----------|
      KC_LCTL, LALT_T(KC_BSLS), LGUI_T(KC_QUOT), LSFT_T(KC_RBRC),        KC_RPRN,  KC_RGHT,                       KC_DOWN,    KC_4,  LSFT_T(KC_5),    KC_6,    KC_0,   KC_CAPS,
  //|--------+----------------+----------------+----------------+----------------+---------|                    |--------+--------+--------------+--------+--------+----------|
      KC_LSFT,            KC_N,            KC_P,         KC_MINS,          KC_EQL,  KC_COMM,                       KC_DOT,    KC_1,          KC_2,    KC_3,   KC_NO, TO(_BASE),
  //|--------+----------------+----------------+----------------+----------------+---------|                    |--------+--------+--------------+--------+--------+----------|
                                                                        KC_SCLN, TO(_BASE), KC_SPC,         KC_ENT, TO(_FKEYS), KC_ESC
                                                                    //`----------------------------'       `--------------------------'
  ),

    [_FKEYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_NO, KC_NO, TO(_GAMING), KC_NO, KC_PGUP,                        KC_F1,   KC_F2,    KC_F3,  KC_F4,   KC_F5,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PGDN,                        KC_F6,   KC_F7,    KC_F8,   KC_F9,  KC_F10, KC_CAPS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LCTL, KC_LALT, KC_PSCR, KC_RCTL, KC_RALT,                       KC_F11,  KC_F12, KC_HOME,  KC_END, KC_RALT, TO(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LGUI, TO(_BASE), KC_SPC,   KC_ENT, TO(_GAMING), RSFT_T(KC_ESC)
                                      //`--------------------------'  `--------------------------'
  ),

    [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_1,    KC_2,    KC_3,    KC_4,         KC_5,      KC_P,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+-------------+----------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,         KC_I,      KC_O,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+-------------+----------|
      KC_LSFT,    KC_Z,LALT_T(KC_X),KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_PSCR, KC_RALT, MO(_SETTNGS), TO(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+-------------+----------|
                                      KC_LGUI, KC_LALT, KC_SPC,       KC_ENT, KC_BSPC, RSFT_T(KC_ESC)
                                      //`--------------------------'  `--------------------------'
  ),

    [_SETTNGS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      BL_TOGG, BL_STEP, BL_BRTG,   BL_ON,   BL_UP,   KC_NO,                      RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,  BL_OFF, BL_DOWN,   KC_NO,                        KC_NO, RGB_VAD, RGB_VAI, RGB_HUD, RGB_SAD, RGB_SPD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU,                      QK_BOOT,   KC_NO,    KC_NO,  KC_NO, KC_TRNS, TO(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, RSFT_T(KC_ESC)
                                      //`--------------------------'  `--------------------------'
  ),

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SETTNGS:
            rgblight_sethsv(0, 255, 64); // red
            break;
        case _GAMING:
            rgblight_sethsv(191, 255, 64); // purple
            break;
        case _FKEYS:
            rgblight_sethsv(21, 255, 64); // orange
            break;
        case _NAV:
            rgblight_sethsv(128, 255, 64); // cyan
            break;
        default: // for any other layers, or the default layer
            rgblight_sethsv(85, 255, 64); // green
            break;
    }
    return state;
}
