#include "unity.h"
#include "bmp280.h"

// Definição das variáveis globais
float mock_temperature = 25.0f;
float mock_pressure = 1000.0f;

// ========================
// TESTES
// ========================

void test_bmp280_init_should_not_crash(void) {
    bmp280_init();
    TEST_PASS();
}

void test_bmp280_should_return_valid_temperature(void) {
    mock_temperature = 30.0f;

    float temp = bmp280_read_temperature();

    TEST_ASSERT_EQUAL_FLOAT(30.0f, temp);
}

void test_bmp280_should_reject_high_temperature(void) {
    mock_temperature = 120.0f;

    float temp = bmp280_read_temperature();

    TEST_ASSERT_EQUAL_FLOAT(-999.0f, temp);
}

void test_bmp280_should_reject_low_temperature(void) {
    mock_temperature = -100.0f;

    float temp = bmp280_read_temperature();

    TEST_ASSERT_EQUAL_FLOAT(-999.0f, temp);
}

void test_bmp280_should_return_valid_pressure(void) {
    mock_pressure = 1013.0f;

    float press = bmp280_read_pressure();

    TEST_ASSERT_EQUAL_FLOAT(1013.0f, press);
}

void test_bmp280_should_reject_negative_pressure(void) {
    mock_pressure = -50.0f;

    float press = bmp280_read_pressure();

    TEST_ASSERT_EQUAL_FLOAT(-1.0f, press);
}

void test_bmp280_should_reject_extreme_pressure(void) {
    mock_pressure = 2000.0f;

    float press = bmp280_read_pressure();

    TEST_ASSERT_EQUAL_FLOAT(-1.0f, press);
}