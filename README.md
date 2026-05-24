# STM32 Traffic Signal Project

This project controls a traffic signal using STM32F4 bare-metal register-level programming.

## Features
- Red, Yellow, and Green LED control
- GPIOA pin configuration using registers
- Delay-based traffic light sequence
- No HAL library used in application logic
- Written in Embedded C

## Hardware Used
- STM32F4 development board
- Traffic light LED module
- Jumper wires

## Pin Connections
| Signal | STM32 Pin |
|---|---|
| Red LED | PA6 |
| Yellow LED | PA7 |
| Green LED | PA8 |

## Working
The program turns ON the LEDs in sequence:

Red → Green → Yellow → repeat

## Files
- `main.c` - main traffic signal application code
- `syscalls.c` - STM32CubeIDE system calls
- `sysmem.c` - STM32CubeIDE memory support
