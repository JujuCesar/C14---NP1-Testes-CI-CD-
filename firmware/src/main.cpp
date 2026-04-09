#include <Arduino.h>

#include "services/telemetry.h"
#include "drivers/barometer/bmp280.h"
#include "drivers/lora/rfm95.h"

telemetry_t telemetry;

void setup() {
    Serial.begin(115200);
    delay(1000);

    bmp280_init();
    lora_init();
    telemetry_init(&telemetry);
}

void loop() {

    telemetry.temperature = bmp280_read_temperature();
    telemetry.pressure = bmp280_read_pressure();

    // cria payload simples
    char msg[64];
    snprintf(msg, sizeof(msg),
             "T:%.2f P:%.2f",
             telemetry.temperature,
             telemetry.pressure);

    Serial.println(msg);

    lora_send(msg);

    delay(5000);
}