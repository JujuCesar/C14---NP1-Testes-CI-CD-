#include <Adafruit_BMP280.h>

static Adafruit_BMP280 bmp;

void bmp280_init() {
    Adafruit_BMP280_begin(&bmp, 0x76);
}

float bmp280_read_temperature() {
    return Adafruit_BMP280_readTemperature(&bmp);
}

float bmp280_read_pressure() {
    return Adafruit_BMP280_readPressure(&bmp);
}