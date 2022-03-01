# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

LAYOUTS = ortho_4x12

# Added by me
COMBO_ENABLE = yes
UNICODEMAP_ENABLE = yes
TAP_DANCE_ENABLE=yes
EXTRAFLAGS += -flto # to save space
SWAP_HANDS_ENABLE = yes
