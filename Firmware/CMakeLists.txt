set(EXE_NAME ${PROJECT_NAME}.elf)
set(OPENOCD_CFG_NAME ${PROJECT_NAME}.cfg)

option(ENABLE_CACHE "Enable instruction and data cache" FALSE)

if(${ENABLE_CACHE})
  message(STATUS "Instruction and Data caches are enabled")
endif()

add_library(st STATIC)
target_sources(
  st
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c

  ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c

  ${CMAKE_CURRENT_SOURCE_DIR}/USB_DEVICE/App/usbd_cdc_if.c
  ${CMAKE_CURRENT_SOURCE_DIR}/USB_DEVICE/App/usbd_desc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/USB_DEVICE/App/usb_device.c
  ${CMAKE_CURRENT_SOURCE_DIR}/USB_DEVICE/Target/usbd_conf.c
)

target_include_directories(
  st
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
         ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc
         ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include
         ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
         ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
         ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Inc
         ${CMAKE_CURRENT_SOURCE_DIR}/USB_DEVICE/App
         ${CMAKE_CURRENT_SOURCE_DIR}/USB_DEVICE/Target
         )

target_compile_options(st PRIVATE -Wno-unused-parameter -Wno-shadow
                                  -ffunction-sections -fdata-sections)

target_compile_definitions(st PUBLIC STM32F446xx USE_HAL_DRIVER)

add_executable(
  ${EXE_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Startup/startup_stm32f446vctx.s
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/adc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/can.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/gpio.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/i2c.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/rtc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/spi.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32f4xx_hal_msp.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32f4xx_it.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/syscalls.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/sysmem.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/system_stm32f4xx.c
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/tim.c

)

target_include_directories(
  ${EXE_NAME}
  PRIVATE
    ${PROJECT_BINARY_DIR})

target_compile_options(${EXE_NAME} PRIVATE -Wall -Wextra -Wshadow
                                           -ffunction-sections -fdata-sections)

target_link_options(
  ${EXE_NAME} PRIVATE -T${CMAKE_CURRENT_SOURCE_DIR}/STM32F446VCTX_FLASH.ld
  -Wl,--gc-sections -specs=nano.specs -Wl,--no-warn-rwx-segment)

target_compile_definitions(${EXE_NAME} PRIVATE STM32)

target_link_libraries(${EXE_NAME} PRIVATE st)

add_custom_target(
  flash
  openocd -f ${CMAKE_CURRENT_SOURCE_DIR}/${OPENOCD_CFG_NAME} -c
  "program ${EXE_NAME} reset exit"
  VERBATIM)

add_custom_target(
  flash_no_reset
  openocd -f ${CMAKE_CURRENT_SOURCE_DIR}/${OPENOCD_CFG_NAME} -c
  "program ${EXE_NAME} exit"
  VERBATIM)

add_custom_target(
  connect
  openocd -f ${CMAKE_CURRENT_SOURCE_DIR}/${OPENOCD_CFG_NAME}
  VERBATIM)

add_custom_target(
  debug
  arm-none-eabi-gdb -ex "target extended-remote localhost:3333"
  ${CMAKE_BINARY_DIR}/${EXE_NAME}
  VERBATIM)

add_dependencies(flash ${EXE_NAME})
add_dependencies(flash_no_reset ${EXE_NAME})
add_dependencies(debug ${EXE_NAME})
