# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
OLED_ENABLE = no
SPLIT_KEYBOARD = yes        # Use shared split_common code
LAYOUTS = split_3x5_2

# Added by me
COMBO_ENABLE = yes
UNICODEMAP_ENABLE = yes
TAP_DANCE_ENABLE=yes
EXTRAFLAGS += -flto # to save space
SWAP_HANDS_ENABLE = yes
LEADER_ENABLE = yes
