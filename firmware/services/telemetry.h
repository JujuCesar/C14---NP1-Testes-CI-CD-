#ifndef TELEMETRY_H
#define TELEMETRY_H

typedef struct {

    float acc_x;
    float acc_y;
    float acc_z;

    float gyro_x;
    float gyro_y;
    float gyro_z;

    float mag_x;
    float mag_y;
    float mag_z;

    float pressure;
    float temperature;

} telemetry_t;

void telemetry_init(telemetry_t *t);


void telemetry_print(const telemetry_t *t);

#endif