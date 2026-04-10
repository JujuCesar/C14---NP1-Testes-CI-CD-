#ifndef LORA_H
#define LORA_H

// Variáveis globais para teste
const char *last_message;

// Funções simuladas
static inline void LoRa_setPins(int ss, int rst, int dio0) {}

static inline int LoRa_begin(long freq) {
    return 1;
}

static inline void LoRa_beginPacket() {}

static inline void LoRa_print(const char *msg) {
    last_message = msg;
}

static inline void LoRa_endPacket() {}

#endif