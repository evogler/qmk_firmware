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
  TAB_COMBO,
  ESC_COMBO,
  DEL_COMBO,
  RET_COMBO,
  UP_COMBO,
  DOWN_COMBO,
  LEFT_COMBO,
  RIGHT_COMBO,
  CONSOLE_LOG,
  LGOC_COMBO,
  RGOC_COMBO,
  LGS_COMBO,
  RGS_COMBO,
  LGO_COMBO,
  RGO_COMBO,
  LGUI_COMBO,
  RGUI_COMBO,
  LOPT_COMBO,
  ROPT_COMBO,
  LCTRL_COMBO,
  RCTRL_COMBO,
  LOS_COMBO,
  ROS_COMBO,
  LCS_COMBO,
  RCS_COMBO,
  LGC_COMBO,
  RGC_COMBO,
  LOC_COMBO,
  ROC_COMBO,
  LGOS_COMBO,
  RGOS_COMBO,
  LGCS_COMBO,
  RGCS_COMBO,
  LOCS_COMBO,
  ROCS_COMBO,
  LGOCS_COMBO,
  RGOCS_COMBO,

  OPTLEFT_COMBO,
  OPTRIGHT_COMBO,
  GUILEFT_COMBO,
  GUIRIGHT_COMBO,
  OPTBKSP_COMBO,
  GUIBKSP_COMBO,

  FAUXSWAP_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
// semicolon keycode

#define R1 KC_L
#define R2 KC_U
#define R3 KC_Y
#define R4 KC_LEAD
#define L1 KC_P
#define L2 KC_F
#define L3 KC_W
#define L4 KC_Q
const uint16_t PROGMEM tab_combo[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_H, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM ret_combo[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM up_combo[] = {KC_N, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM down_combo[] = {KC_N, KC_COMMA, KC_I, COMBO_END};
const uint16_t PROGMEM left_combo[] = {KC_N, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM right_combo[] = {KC_L, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM console_log_combo[] = {KC_L, KC_O, KC_G, COMBO_END};
const uint16_t PROGMEM lgoc_combo[] = {L1, L2, L3, COMBO_END};
const uint16_t PROGMEM rgoc_combo[] = {R1, R2, R3, COMBO_END};
const uint16_t PROGMEM lgs_combo[] = {L1, L4, COMBO_END};
const uint16_t PROGMEM rgs_combo[] = {R1, R4, COMBO_END};
const uint16_t PROGMEM lgo_combo[] = {L1, L2, COMBO_END};
const uint16_t PROGMEM rgo_combo[] = {R1, R2, COMBO_END};
const uint16_t PROGMEM lgui_combo[] = {KC_T, L1, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_N, R1, COMBO_END};
const uint16_t PROGMEM lopt_combo[] = {KC_S, L2, COMBO_END};
const uint16_t PROGMEM ropt_combo[] = {KC_E, R2, COMBO_END};
const uint16_t PROGMEM lctrl_combo[] = {KC_R, L3, COMBO_END};
const uint16_t PROGMEM rctrl_combo[] = {KC_I, R3, COMBO_END};
const uint16_t PROGMEM los_combo[] = {L2, L4, COMBO_END};
const uint16_t PROGMEM ros_combo[] = {R2, R4, COMBO_END};
const uint16_t PROGMEM lcs_combo[] = {L3, L4, COMBO_END};
const uint16_t PROGMEM rcs_combo[] = {R3, R4, COMBO_END};
const uint16_t PROGMEM lgc_combo[] = {L1, L3, COMBO_END};
const uint16_t PROGMEM rgc_combo[] = {R1, R3, COMBO_END};
const uint16_t PROGMEM loc_combo[] = {L2, L3, COMBO_END};
const uint16_t PROGMEM roc_combo[] = {R2, R3, COMBO_END};
const uint16_t PROGMEM lgos_combo[] = {L1, L2, L4, COMBO_END};
const uint16_t PROGMEM rgos_combo[] = {R1, R2, R4, COMBO_END};
const uint16_t PROGMEM lgcs_combo[] = {L1, L3, L4, COMBO_END};
const uint16_t PROGMEM rgcs_combo[] = {R1, R3, R4, COMBO_END};
const uint16_t PROGMEM locs_combo[] = {L2, L3, L4, COMBO_END};
const uint16_t PROGMEM rocs_combo[] = {R2, R3, R4, COMBO_END};
const uint16_t PROGMEM lgocs_combo[] = {L1, L2, L3, L4, COMBO_END};
const uint16_t PROGMEM rgocs_combo[] = {R1, R2, R3, R4, COMBO_END};

const uint16_t PROGMEM optleft_combo[] = {KC_E, KC_Y, KC_LEAD, COMBO_END};
const uint16_t PROGMEM optright_combo[] = {KC_U, KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM guileft_combo[] = {KC_M, KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM guiright_combo[] = {KC_J, KC_L, KC_E, COMBO_END};
const uint16_t PROGMEM optbksp_combo[] = {KC_COMMA, KC_I, KC_O,COMBO_END};
const uint16_t PROGMEM guibksp_combo[] = {KC_K, KC_N, KC_E, COMBO_END};

const uint16_t PROGMEM fauxswap_combo[] = {KC_SPC, MO(2), COMBO_END};

combo_t key_combos[] = {
  [TAB_COMBO] = COMBO_ACTION(tab_combo),
  [ESC_COMBO] = COMBO_ACTION(esc_combo),
  [DEL_COMBO] = COMBO_ACTION(del_combo),
  [RET_COMBO] = COMBO_ACTION(ret_combo),
  [UP_COMBO] = COMBO_ACTION(up_combo),
  [DOWN_COMBO] = COMBO_ACTION(down_combo),
  [LEFT_COMBO] = COMBO_ACTION(left_combo),
  [RIGHT_COMBO] = COMBO_ACTION(right_combo),
  [CONSOLE_LOG] = COMBO_ACTION(console_log_combo),
  [LGOC_COMBO] = COMBO_ACTION(lgoc_combo),
  [RGOC_COMBO] = COMBO_ACTION(rgoc_combo),
  [LGS_COMBO] = COMBO_ACTION(lgs_combo),
  [RGS_COMBO] = COMBO_ACTION(rgs_combo),
  [LGO_COMBO] = COMBO_ACTION(lgo_combo),
  [RGO_COMBO] = COMBO_ACTION(rgo_combo),
  [LGUI_COMBO] = COMBO_ACTION(lgui_combo),
  [RGUI_COMBO] = COMBO_ACTION(rgui_combo),
  [LOPT_COMBO] = COMBO_ACTION(lopt_combo),
  [ROPT_COMBO] = COMBO_ACTION(ropt_combo),
  [LCTRL_COMBO] = COMBO_ACTION(lctrl_combo),
  [RCTRL_COMBO] = COMBO_ACTION(rctrl_combo),
  [LOS_COMBO] = COMBO_ACTION(los_combo),
  [ROS_COMBO] = COMBO_ACTION(ros_combo),
  [LCS_COMBO] = COMBO_ACTION(lcs_combo),
  [RCS_COMBO] = COMBO_ACTION(rcs_combo),
  [LGC_COMBO] = COMBO_ACTION(lgc_combo),
  [RGC_COMBO] = COMBO_ACTION(rgc_combo),
  [LOC_COMBO] = COMBO_ACTION(loc_combo),
  [ROC_COMBO] = COMBO_ACTION(roc_combo),
  [LGOS_COMBO] = COMBO_ACTION(lgos_combo),
  [RGOS_COMBO] = COMBO_ACTION(rgos_combo),
  [LGCS_COMBO] = COMBO_ACTION(lgcs_combo),
  [RGCS_COMBO] = COMBO_ACTION(rgcs_combo),
  [LOCS_COMBO] = COMBO_ACTION(locs_combo),
  [ROCS_COMBO] = COMBO_ACTION(rocs_combo),
  [LGOCS_COMBO] = COMBO_ACTION(lgocs_combo),
  [RGOCS_COMBO] = COMBO_ACTION(rgocs_combo),
  [OPTLEFT_COMBO] = COMBO_ACTION(optleft_combo),
  [OPTRIGHT_COMBO] = COMBO_ACTION(optright_combo),
  [GUILEFT_COMBO] = COMBO_ACTION(guileft_combo),
  [GUIRIGHT_COMBO] = COMBO_ACTION(guiright_combo),
  [OPTBKSP_COMBO] = COMBO_ACTION(optbksp_combo),
  [GUIBKSP_COMBO] = COMBO_ACTION(guibksp_combo),
  [FAUXSWAP_COMBO] = COMBO_ACTION(fauxswap_combo)

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
    case TAB_COMBO:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case ESC_COMBO:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
    case CONSOLE_LOG:
      if (pressed) {
        SEND_STRING("console.log(");
      }
      break;
    case RET_COMBO:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
    case DEL_COMBO:
        if (pressed) {
            register_code16(KC_BACKSPACE);
        } else {
            unregister_code16(KC_BACKSPACE);
        }
        break;
    case UP_COMBO:
        if (pressed) {
            register_code16(KC_UP);
        } else {
            unregister_code16(KC_UP);
        }
        break;
    case DOWN_COMBO:
        if (pressed) {
            register_code16(KC_DOWN);
        } else {
            unregister_code16(KC_DOWN);
        }
        break;
    case LEFT_COMBO:
        if (pressed) {
            register_code16(KC_LEFT);
        } else {
            unregister_code16(KC_LEFT);
        }
        break;
    case RIGHT_COMBO:
        if (pressed) {
            register_code16(KC_RIGHT);
        } else {
            unregister_code16(KC_RIGHT);
        }
        break;
    case LGUI_COMBO:
      if (pressed) {
        register_mods(MOD_BIT(KC_LGUI));
      } else {
        unregister_mods(MOD_BIT(KC_LGUI));
      }
      break;
    case RGUI_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI));
        }
        break;
    case LOPT_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LALT));
        } else {
            unregister_mods(MOD_BIT(KC_LALT));
        }
        break;
    case ROPT_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RALT));
        } else {
            unregister_mods(MOD_BIT(KC_RALT));
        }
        break;
    case LCTRL_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LCTL));
        } else {
            unregister_mods(MOD_BIT(KC_LCTL));
        }
        break;
    case RCTRL_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RCTL));
        } else {
            unregister_mods(MOD_BIT(KC_RCTL));
        }
        break;
    case LGOC_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
        } else {
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
        }
        break;
    case RGOC_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT));
        }
        break;
    case LGS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
        } else {
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
        }
        break;
    case RGS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RSFT));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RSFT));
        }
        break;
    case LGO_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
        } else {
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
        }
        break;
    case RGO_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT));
        }
        break;
    case LOS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));

        } else {
            unregister_mods(MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        }
        break;
    case ROS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        } else {
            unregister_mods(MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        }
        break;
    case LCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
        } else {
            unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
        }
        break;
    case RCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSFT));
        } else {
            unregister_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSFT));
        }
        break;
    case FAUXSWAP_COMBO:
        if (pressed) {
            // SEND_STRING("Fauxswap!");
            layer_on(4);
        } else {
            layer_off(4);
        }
        break;
    case LGC_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL));
        } else {
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL));
        }
        break;
    case RGC_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL));
        }
        break;
    case LOC_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
        } else {
            unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
        }
        break;
    case ROC_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT));
        } else {
            unregister_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT));
        }
        break;
    case LGOS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        } else {
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        }
        break;
    case RGOS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        }
        break;
    case LGCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
        } else {
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
        }
        break;
    case RGCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSFT));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSFT));
        }
        break;
    case LOCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        } else {
            unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        }
        break;
    case ROCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        } else {
            unregister_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        }
        break;
    case LGOCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        } else {
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        }
        break;
    case RGOCS_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        } else {
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RSFT));
        }
        break;
    case OPTLEFT_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RALT));
            register_code16(KC_LEFT);
        } else {
            unregister_mods(MOD_BIT(KC_RALT));
            unregister_code16(KC_LEFT);
        }
        break;
    case OPTRIGHT_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RALT));
            register_code16(KC_RIGHT);
        } else {
            unregister_mods(MOD_BIT(KC_RALT));
            unregister_code16(KC_RIGHT);
        }
        break;
    case GUILEFT_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI));
            register_code16(KC_LEFT);
        } else {
            unregister_mods(MOD_BIT(KC_RGUI));
            unregister_code16(KC_LEFT);
        }
        break;
    case GUIRIGHT_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI));
            register_code16(KC_RIGHT);
        } else {
            unregister_mods(MOD_BIT(KC_RGUI));
            unregister_code16(KC_RIGHT);
        }
        break;
    case OPTBKSP_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RALT));
            register_code16(KC_BSPC);
        } else {
            unregister_mods(MOD_BIT(KC_RALT));
            unregister_code16(KC_BSPC);
        }
        break;
    case GUIBKSP_COMBO:
        if (pressed) {
            register_mods(MOD_BIT(KC_RGUI));
            register_code16(KC_BSPC);
        } else {
            unregister_mods(MOD_BIT(KC_RGUI));
            unregister_code16(KC_BSPC);
        }
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
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
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

    if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
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
            register_code16(SH_MON); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LPRN);
            register_code16(KC_LPRN);
            break;
        case TD_DOUBLE_HOLD:
            layer_on(3);
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
            unregister_code16(SH_MON); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case TD_DOUBLE_HOLD:
             if (layer_state_is(3)) {
                layer_off(3);
            }
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

#define _ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x12(
        KC_Q, KC_W, KC_F, KC_P, KC_B,  _, _,  KC_J, KC_L, KC_U, KC_Y, KC_LEAD,
        KC_A, KC_R, KC_S, KC_T, KC_G,  _, _,  KC_M, KC_N, KC_E, KC_I, KC_O,
        LSFT_T(KC_Z), KC_X, KC_C, KC_D, KC_V,  _, _,  KC_K, KC_H, KC_COMM, KC_DOT, RSFT_T(KC_QUOT),
        _, _, _,  MO(1), TD(ALT_LP),  _, _,  KC_SPC, MO(2), _, _, _
        ),
	[1] = LAYOUT_ortho_4x12(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,  _, _,  KC_CIRC, KC_AMPR, KC_ASTR, _, _,
        KC_1, KC_2, KC_3, KC_4, KC_5,              _, _,  KC_6, KC_7, KC_8, KC_9, KC_0,
        OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), _,   _, _,    KC_BSPC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        _, _, _, KC_TRNS, _,    _, _,   _, MO(3), _, _, _
        ),
	[2] = LAYOUT_ortho_4x12(
        KC_GT, KC_RCBR, KC_RBRC, KC_RPRN, _,    _, _,    KC_GRV, KC_MINS, KC_PPLS, KC_TILDE, _,
        KC_LT, KC_LCBR, KC_LBRC, KC_LPRN, _,    _, _,    KC_SCLN, KC_ENT, KC_EQL, KC_COLN, KC_UNDS,
        LSFT_T(KC_QUES), KC_BSLS, KC_PIPE, KC_SLSH, _,  _, _,    KC_BSPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        _, _, _, MO(3), _,                      _, _,    _, KC_TRNS, _, _, _
        ),
	[3] = LAYOUT_ortho_4x12(
        RESET, FORCE_REP, _, _, _,    _, _,   KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,
        G(A(S(KC_1))), G(A(S(KC_2))), G(A(S(KC_3))), G(A(S(KC_4))), G(A(S(KC_5))),   _, _,  G(A(S(KC_6))), G(A(S(KC_7))), G(A(S(KC_8))), G(A(S(KC_9))), G(A(S(KC_0))),
        _, _, _, _, _,          _, _,     _, _, _, _, _,
        _, _, _, KC_TRNS, _,    _, _,    _, KC_TRNS, _, _, _
        ),
    [4] = LAYOUT_ortho_4x12(
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), _, _, KC_B, KC_P, KC_F, KC_W, KC_Q,
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), _, _, KC_G, KC_T, KC_S, KC_R, KC_A,
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), _, _, KC_V, KC_D, KC_C, KC_X, KC_Z,
        X(BANG), X(BANG), X(BANG), X(BANG), X(BANG), _, _, KC_TRNS, KC_TRNS, _, _, _
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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    SEND_STRING("DD is awesome.");
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_A);
      unregister_code(KC_A);
      unregister_code(KC_LGUI);
    }
  }
}
