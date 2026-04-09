#include "unity.h"
#include "rfm95.h"

void test_lora_init_should_not_crash(void) {
    lora_init();
    TEST_PASS();
}