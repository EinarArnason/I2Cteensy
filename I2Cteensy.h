#pragma once

#include "I2C/include/I2C.h"
#include <Arduino.h>
#include <i2c_t3.h>

class I2Cteensy : public I2C {
public:
  I2Cteensy();
  ~I2Cteensy();
  // Returns true if initialization is successful
  bool init();
  bool send(const Config &config, const char *buffer, int size);
  bool receive(const Config &config, char *buffer, int size);
};
