
# Pin Assignments

## Overview

| Qty      | GPIO Mode      | PU/PD | Prph & Func |
| ---------------------- | ---------------------- | ---------------------- | ---------------------- |
| 2x      | EXTI RE      | PU       | Rotary SW, Rotary DT |
| 4x   | EXTI FE   | PU        | Button Array |
| 1x   | Input   | PU        | Rotary CLK |
| 1x   | AF DAC   | ? | Vvar Buck EN |
| 1x   | ?   | ?        | LED data |
| 3x   | Output PP   | ?        | Fixed Bucks EN |
| 2x   | AF PP   | None | Fan Tach, Fan PWM
| 2x   | AF OD   | None | I2C: SCL + SDA |
| 2x   | AF PGA ?   | ? | 3V3 shunts |
| 4x   | AF ADC ?   | ? | 5V, 12V, Vvar shunts |

## By Peripheral

### Rotary Encoder

| MCU Pin | Prph Pin      | GPIO Mode | PU/PD |
| ---------------------- | ---------------------- | ---------------------- | ---------------------- |
| ?      | SW      | EXTI Rising-Edge | Pull-up |
| ?   | DT   | EXTI Rising-Edge | Pull-up |
| ?   | CLK   | Input | Pull-up |

### Button Array

| MCU Pin | Prph Pin      | GPIO Mode | PU/PD |
| ---------------------- | ---------------------- | ---------------------- | ---------------------- |
| ?   | 1 | EXTI Falling-Edge | Pull-up |
| ?   | 2 | EXTI Falling-Edge | Pull-up |
| ?   | 3 | EXTI Falling-Edge | Pull-up |
| ?   | 4 | EXTI Falling-Edge | Pull-up |

### Buck Converters

| MCU Pin | Prph Pin      | GPIO Mode | PU/PD |
| ---------------------- | ---------------------- | ---------------------- | ---------------------- |
| ?   | EN | Output Push-Pull | ? |
| ?   | EN | Output Push-Pull | ? |
| ?   | EN | Output Push-Pull | ? |

### Current Sensors

| MCU Pin | Prph Pin      | GPIO Mode | PU/PD |
| ---------------------- | ---------------------- | ---------------------- | ---------------------- |
| ?   | 1 Out | AF ADC ? | ? |
| ?   | 1 Out | AF ADC ? | ? |
| ?   | 1 Out | AF ADC ? | ? |
| ?   | 1 Out | AF ADC ? | ? |

## Protocol

### I2C

### Temperature Sensors

| MCU Pin | Prph Pin      | GPIO Mode | PU/PD |
| ---------------------- | ---------------------- | ---------------------- | ---------------------- |
| ?   | 1 Out | AF ADC ? | ? |
| ?   | 1 Out | AF ADC ? | ? |
| ?   | 1 Out | AF ADC ? | ? |
| ?   | 1 Out | AF ADC ? | ? |