# Temperature-Controlled Fan Controller

An embedded C project that implements an intelligent temperature-controlled fan system using the ATmega32 microcontroller. The system automatically adjusts fan speed based on ambient temperature readings from an LM35 sensor and displays real-time information on an LCD.

## Features

- **Automatic Temperature Control**: Fan speed adjusts automatically based on temperature
- **Variable Speed Control**: PWM-based motor control with 4 different speed levels
- **Real-time Display**: LCD shows current temperature and fan status
- **Temperature Monitoring**: Uses LM35 sensor for accurate temperature readings
- **Energy Efficient**: Fan only operates when needed (temperature ≥ 30°C)

## Hardware Requirements

### Components
- **ATmega32 Microcontroller** - Main controller
- **LM35 Temperature Sensor** - Temperature measurement
- **16x2 LCD Display** - Status and temperature display
- **DC Motor/Fan** - Cooling fan
- **Power Supply** - 5V DC
- **Connecting wires and breadboard**

### Pin Connections

| Component | ATmega32 Pin | Description |
|-----------|--------------|-------------|
| LM35 Output | ADC2 (PA2) | Temperature sensor analog input |
| DC Motor Pin 1 | PB6 | Motor control pin 1 |
| DC Motor Pin 2 | PB7 | Motor control pin 2 |
| LCD Data Bus | Port C | LCD data connections |
| LCD Control | Port D | LCD enable/register select |

## Temperature Control Logic

| Temperature Range | Fan Status | Speed (PWM) |
|-------------------|------------|-------------|
| < 30°C | OFF | 0% |
| 30°C - 59°C | ON | 25% |
| 60°C - 89°C | ON | 50% |
| 90°C - 119°C | ON | 75% |
| 120°C - 150°C | ON | 100% |

## Software Requirements

- **AVR-GCC Compiler** - For compiling C code
- **Eclipse IDE** (optional) - Development environment
- **AVRDUDE** - For programming the microcontroller
- **WinAVR/AVR Studio** (Windows) or **avr-gcc** (Linux/Mac)

## Project Structure

```
project3/project3/
├── app.c              # Main application logic
├── adc.c/h            # ADC driver for sensor reading
├── lcd.c/h            # LCD display driver
├── motor.c/h          # DC motor control driver
├── lm35_sensor.c/h    # LM35 temperature sensor driver
├── timer0_pwm.c/h     # Timer0 PWM for motor speed control
├── gpio.c/h           # GPIO operations
├── std_types.h        # Standard type definitions
└── common_macros.h    # Common macro definitions
```

## Building and Installation

### 1. Clone the Repository
```bash
git clone https://github.com/MahmoudAbdelrahman2002/fanController.git
cd fanController
```

### 2. Compile the Project
```bash
cd project3/project3
avr-gcc -mmcu=atmega32 -Os *.c -o fanController.elf
avr-objcopy -O ihex fanController.elf fanController.hex
```

### 3. Program the Microcontroller
```bash
avrdude -p m32 -c usbasp -U flash:w:fanController.hex:i
```

## Usage

1. **Power On**: Connect 5V power supply to the circuit
2. **Temperature Monitoring**: The LCD will display current temperature
3. **Automatic Operation**: Fan will start automatically when temperature reaches 30°C
4. **Speed Adjustment**: Fan speed increases with temperature according to the control logic
5. **Status Display**: LCD shows "FAN ON" or "FAN OFF" along with current temperature

## Circuit Setup

1. Connect the LM35 sensor output to ADC2 (PA2) of ATmega32
2. Connect the DC motor to pins PB6 and PB7 through a motor driver circuit
3. Connect the LCD display to the designated ports (refer to lcd.h for specific pins)
4. Ensure proper power supply connections (VCC, GND)
5. Add pull-up resistors where necessary

## Configuration

- **ADC Configuration**: Internal voltage reference, prescaler 8
- **PWM Frequency**: Controlled by Timer0 settings
- **LCD Mode**: 4-bit or 8-bit mode (configurable in lcd.h)
- **Temperature Sensor**: Channel 2, max voltage 1.5V, max temperature 150°C

## Author

**Mahmoud Abdelrahman** - Embedded Systems Developer

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly with hardware
5. Submit a pull request

## License

This project is open source. Please check with the author for specific licensing terms.

---

*This project demonstrates practical embedded systems programming with real-world applications in temperature control and automation.*
