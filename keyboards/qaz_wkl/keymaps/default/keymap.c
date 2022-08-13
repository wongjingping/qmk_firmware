// Copyright 2021 jp_smasher (@jp_smasher)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _L1,
    _L2,
    _L3,
};

// define layers
#define L1  LT(_L1, KC_ENT)
#define L2  LT(_L2, KC_SPC)
#define L3  MO(_L3)

// define home-row styled alpha-mods
#define C_C     LCTL_T(KC_C)
#define C_M     LCTL_T(KC_M)
#define G_A     CMD_T(KC_A)
#define G_SC    CMD_T(KC_SCLN)
#define A_X     LOPT_T(KC_X)
#define A_COMM  LOPT_T(KC_COMM)
#define S_Z     SFT_T(KC_Z)
#define S_DOT   SFT_T(KC_DOT)

// combos for application shortcuts
#define SG_LBRC SGUI(KC_LBRC)
#define SG_RBRC SGUI(KC_RBRC)
#define G_LBRC  G(KC_LBRC)
#define G_RBRC  G(KC_RBRC)
#define A_SLSH  A(KC_SLSH)

/* combos */
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(jk_combo, KC_ESC)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
  [_BASE] = LAYOUT(
    KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    G_A,      KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     G_SC,
    S_Z,      A_X,      C_C,      KC_V,      KC_B,               KC_N,     C_M,      A_COMM,   S_DOT,
    A_SLSH,		L3,       L1,        L2,                 KC_RSFT,  KC_RSFT
  ),

  [_L1] = LAYOUT(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,
    KC_LPRN,  KC_RPRN,  KC_LCBR,  KC_RCBR,  KC_GRV,             KC_QUOT,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PIPE,
    _______,  KC_SLSH,  KC_QUES,  KC_TAB,   _______,            KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,
    _______,            _______,  _______,  KC_LSFT,            _______,  _______
  ),

  [_L2] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,    KC_9,     KC_0,
    _______,  _______,  _______,  _______,   KC_DOT,             KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_BSPC,
    KC_LSFT,  _______,  _______,  _______,   _______,            SG_LBRC,  SG_RBRC,  G_LBRC,   G_RBRC,
    _______, 		KC_LGUI,  KC_LALT,   _______,            _______,  _______
  ),

  [_L3] = LAYOUT(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
    _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  KC_F11,   KC_F12,
    _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,
    _______, 		_______,  _______,   _______,            _______,  _______
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L2:
        case L3:
        case C_C:
        case C_M:
        case G_A:
            return 300;
        default:
            return TAPPING_TERM;
    }
}
