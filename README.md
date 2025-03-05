# STM32 UART Loopback and ADC Communication 🚀

This project implements UART loopback communication and ADC sensor reading on the STM32 microcontroller. It also builds a simple communication protocol between the STM32 and a console terminal.

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Implementation Steps](#implementation-steps)
- [Communication Protocol](#communication-protocol)
- [How to Use](#how-to-use)
- [Tools and Environment](#tools-and-environment)
- [Contributors](#contributors)
- [License](#license)

## Project Overview
This project showcases real-time UART loopback communication and ADC data acquisition on an STM32 microcontroller. The system receives console commands and sends sensor data in a specific protocol format.

## Features ✨
- **UART Loopback:** Echoes any received character back to the terminal.
- **ADC Sensor Reading:** Captures analog voltage from PA0 and converts it to digital value.
- **Real-time Data Transmission:** Sends ADC values over UART every 500ms.
- **Command Parsing:** Supports specific console commands to request and acknowledge data.
- **Timeout Management:** Resends data packet if no response is received within 3 seconds.

## Implementation Steps 🛠️
1. **Setup UART Communication:**
   - Configure USART2 for interrupt-driven communication.
   - Implement an interrupt callback for receiving and transmitting data.
2. **Initialize ADC:**
   - Read analog data from PA0.
   - Convert ADC value to a readable format and transmit over UART.
3. **Implement Command Parser FSM:**
   - Receive and buffer incoming characters.
   - Parse commands like `!RST#` and `!OK#`.
4. **Build Communication FSM:**
   - Respond to `!RST#` with ADC value in format `!ADC=1234#`.
   - Wait for `!OK#` acknowledgment.
   - Resend data if no response after 3 seconds.

## Communication Protocol 📡
| Command     | Description                  |
|-------------|----------------------------|
| `!RST#`     | Request sensor data         |
| `!ADC=xxxx#`| Response with ADC value     |
| `!OK#`      | Acknowledge received data   |

## How to Use 🧑‍💻
1. Flash the STM32 code onto your development board.
2. Open a terminal emulator and connect to STM32’s UART.
3. Send `!RST#` to request sensor data.
4. Observe ADC readings and acknowledge with `!OK#`.

## Tools and Environment 🧰
- STM32F103C6 Microcontroller
- STM32CubeIDE and HAL Library
- Proteus for Simulation (Optional)
- Serial Terminal Emulator (e.g., Tera Term, PuTTY)

## Contributors 👩‍💻👨‍💻
- Beckversync

## License 📝
HCMUT

