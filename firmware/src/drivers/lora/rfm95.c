#include "SPI.h"
#include "LoRa.h"
#include "rfm95.h"

#define LORA_SS 5
#define LORA_RST 14
#define LORA_DIO0 2

void lora_init() {
    LoRa_setPins(LORA_SS, LORA_RST, LORA_DIO0);

    if (!LoRa_begin(915E6)) {
        while (1); // trava se falhar
    }
}

void lora_send(const char *msg) {
    LoRa_beginPacket();
    LoRa_print(msg);
    LoRa_endPacket();
}