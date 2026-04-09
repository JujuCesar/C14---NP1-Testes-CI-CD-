#ifndef RFM95_H
#define RFM95_H

#ifdef __cplusplus
extern "C" {
#endif

void lora_init();
void lora_send(const char *msg);

#ifdef __cplusplus
}
#endif

#endif