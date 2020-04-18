# I2Cteensy library

I2C implementation for Teensy microcontrollers

## The What

This library is a Teensy implementation for I<sup>2</sup>C controllers.

## The Why

Because this library inherits the I2C interface, it can be applied in a modular manner.

## The How

### Building

#### Dependencies

- Arduino IDE <https://www.arduino.cc/en/main/software>
- i2c_t3 <https://github.com/nox771/i2c_t3>

### Usage

Typical operation:

```c++
#include "I2Cteensy.h"

I2C::Config i2cConfig(0x00, 100000);
I2Cteensy i2c();
i2c.init();

char data[1] = 0xAA;
i2c.send(i2cConfig, data, sizeof(data));
i2c.receive(i2cConfig, data, sizeof(data));
```

## The Who

Einar Arnason  
<https://github.com/EinarArnason>  
<https://www.linkedin.com/in/einararnason/>
