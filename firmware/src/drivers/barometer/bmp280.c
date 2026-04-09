#include <Adafruit_BMP280.h>

static Adafruit_BMP280 bmp;

void bmp280_init() {
    Adafruit_BMP280_begin(&bmp, 0x76);
}

float bmp280_read_temperature() {
    float temp = Adafruit_BMP280_readTemperature(&bmp);

    if (temp > 85.0f || temp < -40.0f) {
        return -999.0f;
    }

    return temp;
}

float bmp280_read_pressure() {
    float press = Adafruit_BMP280_readPressure(&bmp);

    if (press < 300.0f || press > 1100.0f) {
        return -1.0f;
    }

    return press;
}