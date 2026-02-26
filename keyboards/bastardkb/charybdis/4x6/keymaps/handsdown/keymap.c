/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

enum combos {
    Q_WG,
    Z_XW,
    AE_AE,
    OE_OE,
    AO_AU,
    TH_TN,
    CH_CT,
    SH_ST,
    WH_WM,
    PH_PD,
    GH_GM
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
#define HIND_R MT(MOD_RSFT, KC_A)
#define HIND_L MT(MOD_LSFT, KC_T)
#define HMID_R MT(MOD_RCTL, KC_E)
#define HMID_L MT(MOD_LCTL, KC_N)
#define HING_R MT(MOD_RGUI, KC_I)
#define HING_L MT(MOD_LGUI, KC_C)
#define HINK_R MT(MOD_RALT, KC_H)
#define HINK_L MT(MOD_RALT, KC_S)
#define BMID_R LT(LAYER_POINTER, KC_O)
#define BMID_L LT(LAYER_POINTER, KC_L)
#define SHIFTDEL MT(MOD_RSFT, KC_DEL)
#define SHIFTBACK MT(MOD_LSFT, KC_BSPC)


#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮      ╭──────────────────────────────────────────────────────╮
        KC_LGUI,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤      ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_X,    KC_W,    KC_M,    KC_G,    KC_QUOT,       KC_SCLN,    KC_DOT,    KC_QUOT,    KC_J,    KC_B, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤      ├──────────────────────────────────────────────────────┤
       KC_Q,    HINK_L,    HING_L,    HMID_L,    HIND_L,    KC_K,       KC_COMM,    HIND_R,    HMID_R,    HING_R, HINK_R, KC_Z,
  // ├──────────────────────────────────────────────────────┤      ├──────────────────────────────────────────────────────┤
       KC_LCTL,    KC_V,    KC_P,    BMID_L,    KC_D,    KC_SLSH,       KC_N,    KC_U, BMID_R,  KC_Y, KC_F, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤      ├──────────────────────────────────────────────────────╯
                                       KC_ESC, KC_R,   LOWER,      RAISE,  KC_SPC,
                                           KC_ENT, SHIFTBACK,     SHIFTDEL
        //                        ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______,
                                           XXXXXXX, XXXXXXX,      KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LEFT,   KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, XXXXXXX,    _______, XXXXXXX,
                                           _______, _______,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,  EE_CLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

const uint16_t PROGMEM th_combo[] = {HIND_L, HMID_L, COMBO_END};
const uint16_t PROGMEM ch_combo[] = {HIND_L, HING_L, COMBO_END};
const uint16_t PROGMEM sh_combo[] = {HIND_L, HINK_L, COMBO_END};
const uint16_t PROGMEM wh_combo[] = {KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM ph_combo[] = {HIND_L, KC_D, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {HIND_R, HMID_R, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {HIND_R, KC_U, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {BMID_R, HMID_R, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_X, KC_W, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_G, KC_W, COMBO_END};


#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

combo_t key_combos[] = {
  [Q_WG] = COMBO(q_combo, KC_Q),
  [Z_XW] = COMBO(z_combo, KC_Z),
  [AE_AE] = COMBO(ae_combo, KC_A),
  [OE_OE] = COMBO(oe_combo, KC_E),
  [AO_AU] = COMBO(z_combo, KC_Z),
  [TH_TN] = COMBO_ACTION(th_combo),
  [CH_CT] = COMBO_ACTION(ch_combo),
  [SH_ST] = COMBO_ACTION(sh_combo),
  [WH_WM] = COMBO_ACTION(wh_combo),
  [PH_PD] = COMBO_ACTION(ph_combo),
  [GH_GM] = COMBO_ACTION(gh_combo),
    unregister_mods(MOD_MASK_SHIFT);  //
    tap_code(KC_H); // send "h" honoring CAPSLK state
    break;
};

uint16_t COMBO_LEN = COMBO_LENGTH;

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case TH_TN: // on first press
                tap_code(KC_T); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
        case SH_ST:
                tap_code(KC_S); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
        case WH_WM:
                tap_code(KC_W); // send "W" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
        case CH_CT: // not held
                tap_code(KC_C); // send "C" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case GH_GM: // not held
                tap_code(KC_G); // send "G" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case PH_PD:
                tap_code(KC_P); // send "P" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
}
                 if (combo_on) linger_timer = timer_read();
} else {
    if (combo_on && !combo_triggered) {
        switch (combo_index) {
            case TH_TN:
            case CH_CT:
            case WH_WM:
            case PH_PD:
            case GH_GM:
            case SH_ST:
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;     
        }
    } else {
switch(combo_index) {
}
    }
                combo_on = combo_triggered = false;
}
return;
}
    



void matrix_scan_user_process_combo() {
        if (!combo_triggered) {

            if ((timer_elapsed(linger_timer) > COMBO_HOLD) && combo_on) {
            saved_mods = get_mods();
            clear_mods();
                switch(combo_on) { 
                case SH_ST: // if these H digragh combos are held, then send T/SION instead
                case TH_TN: // TION = by far most common 4-gram, (then THAT/THER/WITH/MENT)
                    unregister_mods(MOD_MASK_SHIFT);
                    send_string("ion");
                    break;
                case GH_GM: // held, send "ght"
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_T); // add "t" ("ght" is 55% of all "gh" occurrences)
                    break;
                case CH_CT: //
                case WH_WM: //
                case PH_PD: //
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_I); // add "i"
                    break;
                }
                set_mods(saved_mods);
                combo_triggered = true;
            }
        }

}
