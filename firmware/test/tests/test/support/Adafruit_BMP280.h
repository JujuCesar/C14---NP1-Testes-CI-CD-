#ifndef ADAFRUIT_BMP280_H
#define ADAFRUIT_BMP280_H

typedef struct {
    int dummy;
} Adafruit_BMP280;

// Variáveis globais controláveis pelo teste
extern float mock_temperature;
extern float mock_pressure;

static inline int Adafruit_BMP280_begin(Adafruit_BMP280 *self, int addr) {
    return 1;
}

static inline float Adafruit_BMP280_readTemperature(Adafruit_BMP280 *self) {
    return mock_temperature;
}

static inline float Adafruit_BMP280_readPressure(Adafruit_BMP280 *self) {
    return mock_pressure;
}

#endif