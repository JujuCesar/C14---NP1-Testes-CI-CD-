#ifndef MPU6050_H
#define MPU6050_H

#ifdef __cplusplus
extern "C" {
#endif

void mpu6050_init();

void mpu6050_read_acc(float *x, float *y, float *z);
void mpu6050_read_gyro(float *x, float *y, float *z);

#ifdef __cplusplus
}
#endif

#endif