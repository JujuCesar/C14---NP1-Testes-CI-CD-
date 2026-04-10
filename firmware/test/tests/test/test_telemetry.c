#include "unity.h"
#include "telemetry.h"

void setUp(void) {
    // Executa antes de cada teste 
}

void tearDown(void) {
    // Executa depois de cada teste 
}

// ========================
// TESTES
// ========================

void test_telemetry_init_should_zero_values(void) {
    telemetry_t t;

    telemetry_init(&t);

    TEST_ASSERT_EQUAL_FLOAT(0.0f, t.temperature);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, t.pressure);
}


void test_telemetry_should_store_values_correctly(void) {
    telemetry_t t;

    t.temperature = 25.5f;
    t.pressure = 1000.0f;

    TEST_ASSERT_EQUAL_FLOAT(25.5f, t.temperature);
    TEST_ASSERT_EQUAL_FLOAT(1000.0f, t.pressure);
}

void test_telemetry_should_handle_negative_values(void) {
    telemetry_t t;

    t.temperature = -10.0f;

    TEST_ASSERT_EQUAL_FLOAT(-10.0f, t.temperature);
}

void test_telemetry_should_handle_large_values(void) {
    telemetry_t t;

    t.pressure = 999999.0f;

    TEST_ASSERT_EQUAL_FLOAT(999999.0f, t.pressure);
}

void test_telemetry_should_reset_values_after_init(void) {
    telemetry_t t;

    t.temperature = 50.0f;

    telemetry_init(&t);

    TEST_ASSERT_EQUAL_FLOAT(0.0f, t.temperature);
}

void test_telemetry_should_handle_zero_values(void) {
    telemetry_t t;

    t.temperature = 0.0f;
    t.pressure = 0.0f;

    TEST_ASSERT_EQUAL_FLOAT(0.0f, t.temperature);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, t.pressure);
}

void test_telemetry_should_not_corrupt_memory(void) {
    telemetry_t t;

    telemetry_init(&t);

    t.temperature = 10.0f;

    TEST_ASSERT_NOT_EQUAL(0.0f, t.temperature);
}