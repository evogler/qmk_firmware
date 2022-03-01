#include QMK_KEYBOARD_H
#include <stdlib.h>
#include "rev2.h"

enum custom_keycodes {
    REP = SAFE_RANGE,
    FORCE_REP,
    CLEAR_KEYB,
};

// note: if this array gets larger than 3, there's a variable you have to set
enum unicode_names {
    BANG,
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
};

enum combo_events {
  EM_EMAIL,
  CONSOLE_LOG,
  OPEN_PAREN,
  SHEL,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM email_combo[] = {KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM console_log_combo[] = {KC_L, KC_O, KC_G, COMBO_END};
const uint16_t PROGMEM open_paren[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM shel_combo[] = {KC_S, KC_H, KC_E, COMBO_END};


combo_t key_combos[] = {
  [EM_EMAIL] = COMBO_ACTION(email_combo),
  [CONSOLE_LOG] = COMBO_ACTION(console_log_combo),
  [OPEN_PAREN] = COMBO_ACTION(open_paren),
  [SHEL] = COMBO_ACTION(shel_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

// uint16_t n = 0;

// uint16_t num_to_code(uint16_t num) {
//     switch (num) {
//         case 0:
//             return KC_0;
//         case 1 ... 9:
//             return KC_1 + num - 1;
//         case 10 ... 15:
//             return KC_A + num - 10;
//         default:
//             return KC_NO;
//     }
// }

// void output_num(uint16_t num) {
//     tap_code16(KC_SPC);
//     tap_code16(num_to_code((num >> 12) & 0x0F));
//     tap_code16(num_to_code((num >> 8) & 0x0F));
//     tap_code16(num_to_code((num >> 4) & 0x0F));
//     tap_code16(num_to_code((num >> 0) & 0x0F));
//     tap_code16(KC_SPC);
// }

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EM_EMAIL:
    //   if (pressed) {
    //     SEND_STRING("ARST NEIO");
    //   }
      break;
    case CONSOLE_LOG:
      if (pressed) {
        SEND_STRING("console.log(");
      }
      break;
    case OPEN_PAREN:
      if (pressed) {
          SEND_STRING("(");
      }
      break;
    case SHEL:
    //   if (pressed) {
    //       SEND_STRING("shelby");
    //       tap_code(KC_LEFT);
    //       tap_code(KC_LEFT);
    //       tap_code(KC_LEFT);
    //   }
      break;
  }
}

// For key repeater:
// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;
uint8_t mod_state;
uint8_t oneshot_mod_state;
bool ignore_key = 0;
bool force_rep = 0;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode == last_keycode && record->event.pressed) {
        ignore_key = 1;
        return;
    } else {
        ignore_key = 0;
    }
    if (keycode != REP) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    int code = GET_TAP_KC(keycode);
                    // if (code != 0) {
                        last_modifier = code;
                    // }
                }
                break;
            default:
                if (record->event.pressed) {
                    int code = GET_TAP_KC(keycode);
                    if (code != 0) {
                        last_keycode = code;
                    }
                }
                break;
        }
    } else { // keycode == REP
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}


// Tap Dance keycodes
enum td_keycodes {
    ALT_LP // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void altlp_finished(qk_tap_dance_state_t *state, void *user_data);
void altlp_reset(qk_tap_dance_state_t *state, void *user_data);


// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void altlp_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(last_keycode);
            register_code16(last_modifier);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LPRN);
            register_code16(KC_LPRN);
            break;
        default:
            break;
    }
}

void altlp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);;
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [ALT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlp_finished, altlp_reset)
};


const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x12(
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, REP, KC_BSPC,
        KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_QUOT),
        OSM(MOD_LCTL), KC_NO, OSM(MOD_LALT), OSM(MOD_LGUI), OSL(1),
        // TD(ALT_LP),
        OP_SH_ON_OFF,
        KC_SPC, OSL(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        ),
	[1] = LAYOUT_ortho_4x12(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PIPE,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, OSL(3), KC_TRNS, OSL(2), KC_NO, KC_NO, KC_NO, KC_NO
        ),
	[2] = LAYOUT_ortho_4x12(
        KC_TILDE, KC_GT, KC_RCBR, KC_RBRC, KC_RPRN, KC_NO, KC_NO, KC_MINS, KC_PPLS, KC_NO, KC_NO, KC_DEL,
        KC_TRNS, KC_LT, KC_LCBR, KC_LBRC, KC_LPRN, KC_HOME, KC_END, KC_SCLN, KC_EQL, KC_COLN, KC_UNDS, KC_BSLS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_PGDN, SGUI(KC_LBRC), SGUI(KC_RBRC), KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, OSL(1), KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        ),
	[3] = LAYOUT_ortho_4x12(
        RESET, FORCE_REP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO,
        KC_NO, G(A(S(KC_1))), G(A(S(KC_2))), G(A(S(KC_3))), G(A(S(KC_4))), G(A(S(KC_5))), G(A(S(KC_6))), G(A(S(KC_7))), G(A(S(KC_8))), G(A(S(KC_9))), G(A(S(KC_0))), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO
        ),
    [4] = LAYOUT_ortho_4x12(
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG),
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG),
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG),
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), X(BANG)
    )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode != KC_BSPC
     && keycode != KC_LEFT
     && keycode != KC_DOWN
     && keycode != KC_UP
     && keycode != KC_RGHT
     && keycode != KC_SPC
     && keycode != KC_ENT
     ) {
        process_repeat_key(keycode, record);
        bool is_alpha = keycode >= KC_A && keycode <= KC_Z;
        if (force_rep && ignore_key && is_alpha) {
            return false;
        }
    } else {
        ignore_key = 0;
        last_keycode = KC_NO;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case FORCE_REP:
                force_rep = !force_rep;
                break;
            case CLEAR_KEYB:
                clear_mods();
                layer_move(0);
                break;

        }
    }

    // For key repeater
    // It's important to update the mod variables *after* calling process_repeat_key, or else
    // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    return true;
};

