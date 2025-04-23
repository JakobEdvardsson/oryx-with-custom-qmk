#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_2(
KC_Q, LT(6,KC_W), LT(5,KC_F), LT(4,KC_P), LT(7,KC_B), KC_J, KC_L, KC_U, MT(MOD_RALT, KC_Y), TD(DANCE_0), MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LCTL, KC_S), MT(MOD_LSFT, KC_T), KC_G, KC_M, MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_E), MT(MOD_LALT, KC_I), MT(MOD_LGUI, KC_O), LT(2,KC_Z), KC_X, KC_C, LT(8,KC_D), KC_V, KC_K, LT(8,KC_H), TD(DANCE_1), TD(DANCE_2), TD(DANCE_3), LT(3,KC_SPACE), KC_LEFT_SHIFT, MO(1), KC_BSPC),
  [1] = LAYOUT_split_3x5_2(
KC_EXLM, SE_AT, KC_HASH, SE_AMPR, SE_QUES, SE_PLUS, SE_ASTR, SE_TILD, SE_GRV, KC_TRANSPARENT, SE_DLR, KC_PERC, SE_LPRN, SE_RPRN, SE_SLSH, SE_EQL, SE_LCBR, SE_RCBR, SE_ACUT, SE_PND, RALT(SE_PLUS), SE_PIPE, SE_LESS, SE_GRTR, ST_MACRO_0, SE_MINS, SE_LBRC, SE_RBRC, SE_CIRC, SE_EURO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
  [2] = LAYOUT_split_3x5_2(
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, SE_AA, SE_ADIA, SE_OSLH, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
  [3] = LAYOUT_split_3x5_2(
KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_MS_WH_UP, KC_HOME, KC_END, CW_TOGG, KC_PAGE_UP, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_INSERT, KC_MS_WH_DOWN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, LCTL(KC_LEFT_SHIFT), KC_PSCR, LCTL(KC_0), LCTL(SE_MINS), LCTL(SE_PLUS), KC_TRANSPARENT, KC_PGDN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
  [4] = LAYOUT_split_3x5_2(
KC_NO, KC_NO, KC_NO, KC_TRANSPARENT, KC_NO, SE_PLUS, KC_7, KC_8, KC_9, SE_ASTR, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_NO, SE_SLSH, KC_4, KC_5, KC_6, KC_COMMA, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SE_MINS, KC_1, KC_2, KC_3, KC_DOT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC, KC_0),
  [5] = LAYOUT_split_3x5_2(
KC_NO, KC_NO, KC_TRANSPARENT, KC_NO, KC_NO, SE_PLUS, LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), SE_ASTR, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_NO, SE_SLSH, LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), KC_COMMA, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SE_MINS, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), KC_DOT, KC_NO, KC_NO, KC_BSPC, LCTL(KC_0)),
  [6] = LAYOUT_split_3x5_2(
KC_NO, KC_TRANSPARENT, KC_NO, KC_NO, KC_NO, SE_PLUS, LALT(KC_7), LALT(KC_8), LALT(KC_9), SE_ASTR, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_NO, SE_SLSH, LALT(KC_4), LALT(KC_5), LALT(KC_6), KC_COMMA, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SE_MINS, LALT(KC_1), LALT(KC_2), LALT(KC_3), KC_DOT, KC_NO, KC_NO, KC_BSPC, LALT(KC_0)),
  [7] = LAYOUT_split_3x5_2(
KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
  [8] = LAYOUT_split_3x5_2(
LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_NO, KC_NO, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RIGHT), LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), KC_LEFT_SHIFT, KC_TRANSPARENT, LALT(KC_RIGHT), LALT(KC_LEFT), KC_TRANSPARENT, KC_LEFT_SHIFT, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
};
const uint16_t PROGMEM combo0[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LCTL, KC_S), MT(MOD_LSFT, KC_T), COMBO_END};
const uint16_t PROGMEM combo2[] = { MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_E), COMBO_END};
const uint16_t PROGMEM combo3[] = { LT(5,KC_F), LT(4,KC_P), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ENTER),
    COMBO(combo1, KC_TAB),
    COMBO(combo2, KC_DELETE),
    COMBO(combo3, KC_ESCAPE),
};
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4,KC_P):
            return TAPPING_TERM -60;
        default:
            return TAPPING_TERM;
    }
}


void keyboard_post_init_user(void) {
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(50)  SS_LSFT(SS_TAP(X_9))SS_DELAY(50)  SS_TAP(X_SPACE)SS_DELAY(50)  SS_LSFT(SS_TAP(X_0))SS_DELAY(50)  SS_LSFT(SS_TAP(X_NUBS))SS_DELAY(50)  SS_TAP(X_SPACE)SS_DELAY(50)  SS_RALT(SS_TAP(X_7))SS_DELAY(50)  SS_RALT(SS_TAP(X_0)));
    }
    break;

      }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[4];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(SE_APOS);
        tap_code16(SE_APOS);
        tap_code16(SE_APOS);
    }
    if(state->count > 3) {
        tap_code16(SE_APOS);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(SE_APOS); break;
        case SINGLE_HOLD: register_code16(SE_DQUO); break;
        case DOUBLE_TAP: register_code16(SE_APOS); register_code16(SE_APOS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(SE_APOS); register_code16(SE_APOS);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(SE_APOS); break;
        case SINGLE_HOLD: unregister_code16(SE_DQUO); break;
        case DOUBLE_TAP: unregister_code16(SE_APOS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(SE_APOS); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(SE_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(SE_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(SE_COLN); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(SE_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(SE_MINS);
        tap_code16(SE_MINS);
        tap_code16(SE_MINS);
    }
    if(state->count > 3) {
        tap_code16(SE_MINS);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(SE_MINS); break;
        case SINGLE_HOLD: register_code16(SE_UNDS); break;
        case DOUBLE_TAP: register_code16(SE_MINS); register_code16(SE_MINS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(SE_MINS); register_code16(SE_MINS);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(SE_MINS); break;
        case SINGLE_HOLD: unregister_code16(SE_UNDS); break;
        case DOUBLE_TAP: unregister_code16(SE_MINS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(SE_MINS); break;
    }
    dance_state[3].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
};