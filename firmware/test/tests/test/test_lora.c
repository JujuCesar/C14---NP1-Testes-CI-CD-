#include "unity.h"
#include "rfm95.h"

// Variável vinda do mock (LoRa.h)
extern const char *last_message;

void setUp(void) {
    // Reset antes de cada teste
    last_message = 0;
}

void tearDown(void) {
}

// ========================
// TESTES
// ========================

void test_lora_init_should_not_crash(void) {
    lora_init();
    TEST_PASS();
}

void test_lora_should_send_valid_data(void) {
    char msg[] = "HELLO";

    lora_send(msg);

    TEST_ASSERT_EQUAL_STRING("HELLO", last_message);
}

void test_lora_should_handle_null_data(void) {
    lora_send(NULL);

    TEST_ASSERT_NULL(last_message);
}

void test_lora_should_handle_empty_string(void) {
    char msg[] = "";

    lora_send(msg);

    TEST_ASSERT_EQUAL_STRING("", last_message);
}

void test_lora_should_handle_large_payload(void) {
    char msg[256];

    for (int i = 0; i < 255; i++) {
        msg[i] = 'A';
    }
    msg[255] = '\0';

    lora_send(msg);

    TEST_ASSERT_EQUAL_STRING(msg, last_message);
}

void test_lora_should_handle_multiple_transmissions(void) {
    lora_send("DATA1");
    TEST_ASSERT_EQUAL_STRING("DATA1", last_message);

    lora_send("DATA2");
    TEST_ASSERT_EQUAL_STRING("DATA2", last_message);

    lora_send("DATA3");
    TEST_ASSERT_EQUAL_STRING("DATA3", last_message);
}