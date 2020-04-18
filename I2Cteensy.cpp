#include "I2Cteensy.h"

I2Cteensy::I2Cteensy() {}

I2Cteensy::~I2Cteensy() {}

bool I2Cteensy::init() {
    if (!Wire.availableForWrite()) {
        Wire.begin();
        // Wire.setDefaultTimeout(500);
    }
    return true;
}

bool I2Cteensy::send(const Config& config, const char* buffer, int size) {
    Wire.setRate(F_BUS, config.frequency);
    Wire.beginTransmission(config.address);
    if (Wire.write(buffer, size) == (unsigned int)size) {
        Wire.endTransmission();
        return true;
    }
    Wire.endTransmission();

    return false;
}

bool I2Cteensy::receive(const Config& config, char* buffer, int size) {
    Wire.setRate(F_BUS, config.frequency);
    Wire.beginTransmission(config.address);
    Wire.requestFrom(config.address, size);

    if (Wire.available() != size) {
        Wire.endTransmission();
        return false;
    }

    Wire.readBytes(buffer, size);
    Wire.endTransmission();

    return true;
}