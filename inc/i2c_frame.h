/****************************************************************************
 *
 *   Copyright (C) 2013 Fortiss An-Institut TU Munchen All rights reserved.
 *   Author: Thomas Boehm <thomas.boehm@fortiss.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
#ifndef I2C_FRAME_H_
#define I2C_FRAME_H_
#include <inttypes.h>

// ***Take care***: struct alignment isn't necessarily what you expect,
// so unaligned (i.e., single uint8_t values) should go at the end.
// Otherwise nothing will work.

typedef  struct i2c_frame
{
    uint8_t sonar_status;
    uint16_t frame_count;
    int16_t pixel_flow_x_sum;
    int16_t pixel_flow_y_sum;
    int16_t flow_comp_m_x;
    int16_t flow_comp_m_y;
    int16_t qual;
    int16_t gyro_x_rate;
    int16_t gyro_y_rate;
    int16_t gyro_z_rate;
    uint8_t gyro_range;
    uint8_t sonar_timestamp;
    int16_t ground_distance;
} __attribute__((packed)) i2c_frame;

#define I2C_FRAME_SIZE (sizeof(i2c_frame))


typedef struct i2c_integral_frame
{
    uint8_t sonar_status;
    uint16_t frame_count_since_last_readout;
    int16_t pixel_flow_x_integral;
    int16_t pixel_flow_y_integral;
    int16_t gyro_x_rate_integral;
    int16_t gyro_y_rate_integral;
    int16_t gyro_z_rate_integral;
    uint32_t integration_timespan;
    uint32_t sonar_timestamp;
    uint16_t ground_distance;
    int16_t gyro_temperature;
    uint8_t qual;
} __attribute__((packed)) i2c_integral_frame;

#define I2C_INTEGRAL_FRAME_SIZE (sizeof(i2c_integral_frame))

#endif /* I2C_FRAME_H_ */
