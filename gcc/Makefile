TARGET_CHIP := NRF51822_QFAA_CA
BOARD := BOARD_PCA10001

# application source
C_SOURCE_FILES += main.c
C_SOURCE_FILES += ble_nus.c
C_SOURCE_FILES += app_uart_fifo_mod.c
C_SOURCE_FILES += pwm.c
C_SOURCE_FILES += spi_bus.c
C_SOURCE_FILES += epd_spi.c
C_SOURCE_FILES += epd_v1.c
C_SOURCE_FILES += epd_app.c
C_SOURCE_FILES += printf.c

C_SOURCE_FILES += ble_srv_common.c
C_SOURCE_FILES += ble_advdata.c
C_SOURCE_FILES += ble_conn_params.c
C_SOURCE_FILES += softdevice_handler.c
C_SOURCE_FILES += app_timer.c
C_SOURCE_FILES += app_fifo.c
C_SOURCE_FILES += app_button.c
C_SOURCE_FILES += app_gpiote.c
C_SOURCE_FILES += ble_debug_assert_handler.c
C_SOURCE_FILES += spi_master.c
C_SOURCE_FILES += nrf_delay.c

SDK_PATH = ../../../../../

OUTPUT_FILENAME := ble_app_epd

DEVICE_VARIANT := xxaa

USE_SOFTDEVICE := S110

CFLAGS += -DDEBUG_NRF_USER 
CFLAGS += -DBLE_STACK_SUPPORT_REQD
CFLAGS += -DS110
CFLAGS += -DSPI_MASTER_0_ENABLE

CFLAGS += -DEPD_COG_VERSION=1
CFLAGS += -DEPD_DISPLAY_SIZE_1_44
#CFLAGS += -DEPD_DISPLAY_SIZE_2_0
#CFLAGS += -DEPD_DISPLAY_SIZE_2_7

# we do not use heap in this app
ASMFLAGS := -D__HEAP_SIZE=0

# Keep every function in separate section. 
# This will allow linker to dump unused functions
CFLAGS += -ffunction-sections

INCLUDEPATHS += -I"../"
INCLUDEPATHS += -I"../artwork"
INCLUDEPATHS += -I"$(SDK_PATH)Include/s110"
INCLUDEPATHS += -I"$(SDK_PATH)Include/ble"
INCLUDEPATHS += -I"$(SDK_PATH)Include/ble/device_manager"
INCLUDEPATHS += -I"$(SDK_PATH)Include/ble/ble_services"
INCLUDEPATHS += -I"$(SDK_PATH)Include/app_common"
INCLUDEPATHS += -I"$(SDK_PATH)Include/sd_common"

C_SOURCE_PATHS += $(SDK_PATH)Source/ble
C_SOURCE_PATHS += $(SDK_PATH)Source/ble/device_manager
C_SOURCE_PATHS += $(SDK_PATH)Source/app_common
C_SOURCE_PATHS += $(SDK_PATH)Source/sd_common

include $(SDK_PATH)Source/templates/gcc/Makefile.common
