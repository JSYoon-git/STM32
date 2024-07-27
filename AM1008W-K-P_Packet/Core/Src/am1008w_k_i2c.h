/*
 * am1008w_k_i2c.h
 *
 *  Created on: Jul 17, 2024
 *      Author: Yoon
 */

#ifndef SRC_AM1008W_K_I2C_H_
#define SRC_AM1008W_K_I2C_H_

#include <stdint.h>
#include "main.h"

#define AM1008W_K_I2C_ADDRESS 0x28

#define AM1008W_K_I2C_FRAME_STX 0x16
#define AM1008W_K_I2C_LEN_READ_DATA_COMMAND 25

#define AM1008W_K_I2C_PSO_CLOSE 0x00
#define AM1008W_K_I2C_PSO_TIMING_MEASURING_MODE 0x05
#define AM1008W_K_I2C_PSO_DYNAMIC_MEASURING_MODE 0x06
#define AM1008W_K_I2C_PSO_CONTINOUS_MEASURING_MODE 0x0C
#define AM1008W_K_I2C_PSO_SINGLE_MEASURING_MODE 0x0D

#define AM1008W_K_I2C_CTRL_CLOSE_MEASUREMENT 0x01
#define AM1008W_K_I2C_CTRL_OPEN_MEASUREMENT 0x02
#define AM1008W_K_I2C_CTRL_CO2_CALIBRATION 0x03
#define AM1008W_K_I2C_CTRL_SET_UP_TIMING_MEASUREMENT 0x05
#define AM1008W_K_I2C_CTRL_SET_UP_DYNAMIC_MEASUREMENT 0x06
#define AM1008W_K_I2C_CTRL_SET_UP_PM_CALIBRATION_COEFFICIENT 0x07
#define AM1008W_K_I2C_CTRL_SET_UP_CONTINUOUSLY_MEASUREMENT 0x0C
#define AM1008W_K_I2C_CTRL_SET_UP_SINGLE_MEASUREMENT 0x0D

typedef union
{
    uint8_t value;
    struct
    {
        uint8_t fan_at_high_revolving_speed:1;
        uint8_t fan_at_low_revolving_speed:1;
        uint8_t working_temperature_is_high:1;
        uint8_t working_temperature_is_low:1;
    } bits;
} am1008w_k_i2c_status;

#ifdef __cplusplus
extern "C" {
#endif

void am1008w_k_i2c_begin(I2C_HandleTypeDef *hi2c);
uint8_t am1008w_k_i2c_pm_sensor_mode_close();
uint8_t am1008w_k_i2c_pm_sensor_mode_open();
uint8_t am1008w_k_i2c_pm_sensor_mode_single_measurement(uint16_t range);
uint8_t am1008w_k_i2c_pm_sensor_mode_continuously_measurement();
uint8_t am1008w_k_i2c_pm_sensor_mode_timing_measurement(uint16_t range);
uint8_t am1008w_k_i2c_pm_sensor_mode_dynamic_measurement();
uint8_t am1008w_k_i2c_set_pm_coefficient(uint8_t range);
uint8_t am1008w_k_i2c_calibrate_co2(uint16_t range);
uint8_t am1008w_k_i2c_read_data_command();
uint8_t am1008w_k_i2c_get_pm_operation_mode();
uint16_t am1008w_k_i2c_get_co2();
uint16_t am1008w_k_i2c_get_voc();
int am1008w_k_i2c_get_humidity();
int am1008w_k_i2c_get_temperature();
uint16_t am1008w_k_i2c_get_pm1p0();
uint16_t am1008w_k_i2c_get_pm2p5();
uint16_t am1008w_k_i2c_get_pm10();
uint16_t am1008w_k_i2c_get_voc_now_r_ref_r();
uint16_t am1008w_k_i2c_get_voc_ref_r();
uint16_t am1008w_k_i2c_get_voc_now_r();
am1008w_k_i2c_status am1008w_k_i2c_get_pm_sensor_status_alarm();

#ifdef __cplusplus
}
#endif

#endif /* SRC_AM1008W_K_I2C_H_ */
