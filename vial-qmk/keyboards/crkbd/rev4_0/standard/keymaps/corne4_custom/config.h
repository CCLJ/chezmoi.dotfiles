#pragma once

// rev4_0/config.h incorrectly assigns GP13 as SERIAL_USART_RX_PIN but the PCB
// uses GP13 for USB VBUS detection (same as rev4_1). Override to match rev4_1:
#undef SERIAL_USART_FULL_DUPLEX
#undef SERIAL_USART_RX_PIN
#define USB_VBUS_PIN GP13
#define SPLIT_USB_DETECT

#define VIAL_KEYBOARD_UID {0x10, 0x39, 0x62, 0xd4, 0x46, 0xaf, 0x54, 0xf8}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
