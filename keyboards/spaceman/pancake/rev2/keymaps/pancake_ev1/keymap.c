#include QMK_KEYBOARD_H
#include <stdlib.h>



enum combo_events {
  EM_EMAIL,
  CONSOLE_LOG,
  OPEN_PAREN,
  CLOSE_PAREN,
  OPEN_BRACKET,
  CLOSE_BRACKET,
  OPEN_BRACE,
  CLOSE_BRACE,
  OPEN_ANGLE,
  CLOSE_ANGLE,
  SHEL,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM email_combo[] = {KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM console_log_combo[] = {KC_L, KC_O, KC_G, COMBO_END};

const uint16_t PROGMEM open_paren[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM open_bracket[] = {KC_S, KC_R, COMBO_END};
const uint16_t PROGMEM open_brace[] = {KC_R, KC_A, COMBO_END};
const uint16_t PROGMEM open_angle[] = {KC_A, KC_ESC, COMBO_END};
const uint16_t PROGMEM close_paren[] = {KC_P, KC_F, COMBO_END};
const uint16_t PROGMEM close_bracket[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM close_brace[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM close_angle[] = {KC_Q, KC_TAB, COMBO_END};

const uint16_t PROGMEM shel_combo[] = {KC_S, KC_H, KC_E, COMBO_END};


combo_t key_combos[] = {
  [EM_EMAIL] = COMBO_ACTION(email_combo),
  [CONSOLE_LOG] = COMBO_ACTION(console_log_combo),
  [OPEN_PAREN] = COMBO_ACTION(open_paren),
  [CLOSE_PAREN] = COMBO_ACTION(close_paren),
  [OPEN_BRACKET] = COMBO_ACTION( open_bracket),
  [CLOSE_BRACKET] = COMBO_ACTION(close_bracket),
  [OPEN_BRACE] = COMBO_ACTION(open_brace),
  [CLOSE_BRACE] = COMBO_ACTION(close_brace),
  [OPEN_ANGLE] = COMBO_ACTION(open_angle),
  [CLOSE_ANGLE] = COMBO_ACTION(close_angle),
  [SHEL] = COMBO_ACTION(shel_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EM_EMAIL:
      if (pressed) {
        SEND_STRING("ARST NEIO");
      }
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
    case CLOSE_PAREN:
      if (pressed) {
          SEND_STRING(")");
      }
      break;
    case OPEN_BRACKET:
      if (pressed) {
          SEND_STRING("[");
      }
      break;
    case CLOSE_BRACKET:
      if (pressed) {
          SEND_STRING("]");
      }
      break;
    case OPEN_BRACE:
      if (pressed) {
          SEND_STRING("{");
      }
      break;
    case CLOSE_BRACE:
      if (pressed) {
          SEND_STRING("}");
      }
      break;
    case OPEN_ANGLE:
      if (pressed) {
          SEND_STRING("<");
      }
      break;
    case CLOSE_ANGLE:
      if (pressed) {
          SEND_STRING(">");
      }
      break;
    case SHEL:
        if (pressed) {
            SEND_STRING("shelby");
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
        }
        break;
  }
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x12(
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
        KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
        KC_LCTL, KC_NO, KC_LALT, KC_LGUI, MO(1), MO(4), KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        ),
	[1] = LAYOUT_ortho_4x12(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PIPE,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_NO, KC_NO, KC_NO, KC_NO
        ),
	[2] = LAYOUT_ortho_4x12(KC_TRNS, KC_GT, KC_RCBR, KC_RBRC, KC_RPRN, KC_NO, KC_NO, KC_MINS, KC_PPLS, KC_NO, KC_NO, KC_DEL, KC_TRNS, KC_LT, KC_LCBR, KC_LBRC, KC_LPRN, KC_HOME, KC_END, KC_SCLN, KC_EQL, KC_COLN, KC_UNDS, KC_BSLS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_PGDN, SGUI(KC_LBRC), SGUI(KC_RBRC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(3), KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO),
	[4] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, G(A(S(KC_1))), G(A(S(KC_2))), G(A(S(KC_3))), G(A(S(KC_4))), G(A(S(KC_5))), G(A(S(KC_6))), G(A(S(KC_7))), G(A(S(KC_8))), G(A(S(KC_9))), G(A(S(KC_0))), MACRO_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

int count = 0;
char countStr[8];

uint16_t key = 0;
// // bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if(record->event.pressed) {
//         if(keycode == REP) {
//             tap_code(key);
//             return false;
//         } else {
//             key = keycode;
//             return true;
//         }
//     }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MACRO_0:
                // if ((rand() % 2) == 0) {
                //   SEND_STRING("arst ");
                // } else {
                //   SEND_STRING("neio ");
                // }
                count = count + 1;
                itoa(count, countStr, 10);
                send_string(countStr);
                return false;
        }
    }

    return true;
};

