# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(animacoes_matriz C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Inclui todos os arquivos .c da pasta src
file(GLOB SOURCES "src/*.c")
# Inclui todos os arquivos .c da pasta src/lib
file(GLOB LIB_SOURCES "src/lib/*.c")
# Combina todos os arquivos em um único executável
add_executable(animacoes_matriz ${SOURCES} ${LIB_SOURCES} ${CMAKE_CURRENT_LIST_DIR})

pico_set_program_name(animacoes_matriz "animacoes_matriz")
pico_set_program_version(animacoes_matriz "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(animacoes_matriz 0)
pico_enable_stdio_usb(animacoes_matriz 1)

pico_generate_pio_header(animacoes_matriz ${CMAKE_CURRENT_LIST_DIR}/animacoes_matriz.pio)

target_sources(animacoes_matriz PRIVATE src/animacoes_matriz.c)

# Add the standard library to the build
target_link_libraries(animacoes_matriz PRIVATE
        pico_stdlib
        hardware_pio
        hardware_adc
        pico_bootrom
        hardware_pwm
        hardware_clocks
)

# Add the standard include files to the build
target_include_directories(animacoes_matriz PRIVATE
    ${PICO_SDK_PATH}/src/rp2_common/hardware_pio
    ${CMAKE_CURRENT_LIST_DIR}/src/lib
)

# Add any user requested libraries
target_link_libraries(animacoes_matriz 
        
        )

pico_add_extra_outputs(animacoes_matriz)
