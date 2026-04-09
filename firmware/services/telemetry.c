#include "unity_config.h"
#include "unity.h"
#include <stdio.h>
#include "telemetry.h"


void telemetry_init(telemetry_t *t) {

    t->acc_x = 0;
    t->acc_y = 0;
    t->acc_z = 0;

    t->gyro_x = 0;
    t->gyro_y = 0;
    t->gyro_z = 0;

    t->mag_x = 0;
    t->mag_y = 0;
    t->mag_z = 0;

    t->pressure = 0;
    t->temperature = 0;
}

void telemetry_print(const telemetry_t *t) {

    printf("ACC: %f %f %f\n", t->acc_x, t->acc_y, t->acc_z);
    printf("GYRO: %f %f %f\n", t->gyro_x, t->gyro_y, t->gyro_z);
    printf("MAG: %f %f %f\n", t->mag_x, t->mag_y, t->mag_z);
    printf("TEMP: %f\n", t->temperature);
    printf("PRESS: %f\n", t->pressure);
}