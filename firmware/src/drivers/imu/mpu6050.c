#include "mpu6050.h"

void mpu6050_init() {
    // depois entra I2C real
}

void mpu6050_read_acc(float *x, float *y, float *z) {
    *x = 0.1;
    *y = 0.2;
    *z = 0.3;
}

void mpu6050_read_gyro(float *x, float *y, float *z) {
    *x = 0.01;
    *y = 0.02;
    *z = 0.03;
}