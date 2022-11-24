/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

int32_t val3=0, val2=0, val1=0, val0=0, val4=0, val5=0, val6=0, val7=0, val8=0, val9=0, val10=0, val11=0, countstat2, countstat, countstat1, max=0;

/* Example code to talk to a MPU6050 MEMS accelerometer and gyroscope

   This is taking to simple approach of simply reading registers. It's perfectly
   possible to link up an interrupt line and set things up to read from the
   inbuilt FIFO to make it more useful.

   NOTE: Ensure the device is capable of being driven at 3.3v NOT 5v. The Pico
   GPIO (and therefor I2C) cannot be used at 5v.

   You will need to use a level shifter on the I2C lines if you want to run the
   board at 5v.

   Connections on Raspberry Pi Pico board, other boards may vary.

   GPIO PICO_DEFAULT_I2C_SDA_PIN (On Pico this is GP4 (pin 6)) -> SDA on MPU6050 board
   GPIO PICO_DEFAULT_I2C_SCL_PIN (On Pico this is GP5 (pin 7)) -> SCL on MPU6050 board
   3.3v (pin 36) -> VCC on MPU6050 board
   GND (pin 38)  -> GND on MPU6050 board
*/

// By default these devices  are on bus address 0x68 - documentation
static int addr = 0x68;



float getHeight(float value)
{
    //float calculatedheight = map(value, min, max, -90, 90);

    countstat1 = value;
    // if (value < (float)100){
    //     float calculatedheight = 0;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 100 && value < 110){
    //     float calculatedheight = 0.1;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 110 && value < 120){
    //     float calculatedheight = 0.2;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;
        
    // }else if (value > 120 && value < 130){
    //     float calculatedheight = 0.3;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;
    // }else if (value > 130 && value < 140){
    //     float calculatedheight = 0.4;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 140 && value < 150){
    //     float calculatedheight = 0.5;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 150 && value < 160){
    //     float calculatedheight = 0.6;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 160 && value < 170){
    //     float calculatedheight = 0.7;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 170 && value < 180){
    //     float calculatedheight = 0.8;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 180 && value < 190){
    //     float calculatedheight = 0.9;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 190 && value < 200){
    //     float calculatedheight = 1.0;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 200 && value < 210){
    //     float calculatedheight = 1.1;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 210 && value < 220){
    //     float calculatedheight = 1.2;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 220 && value < 230){
    //     float calculatedheight = 0.1;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 230 && value < 240){
    //     float calculatedheight = 1.3;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 240 && value < 250){
    //     float calculatedheight = 1.4;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 250 && value < 260){
    //     float calculatedheight = 1.5;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 260 && value < 270){
    //     float calculatedheight = 1.6;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 270 && value < 280){
    //     float calculatedheight = 1.7;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 280 && value < 290){
    //     float calculatedheight = 1.8;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 290 && value < 300){
    //     float calculatedheight = 1.9;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 300 && value < 310){
    //     float calculatedheight = 2.0;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 310 && value < 320){
    //     float calculatedheight = 2.1;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 320 && value < 330){
    //     float calculatedheight = 2.2;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 330 && value < 340){
    //     float calculatedheight = 2.3;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 340 && value < 350){
    //     float calculatedheight = 2.4;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }else if (value > 350 && value < 360){
    //     float calculatedheight = 2.5;
    //     val3 = val2;
    //     val2 = val1;
    //     val1 = val0;
    //     val0 = calculatedheight;

    //     countstat1 =(val3+val2+val1+val0)>>2;

    // }

    // if (value < 100){
    //     float calculatedheight = 0.0;
    //     countstat1 = calculatedheight;

    // }else if (value > 100 && value < 110){
    //     float calculatedheight = 0.1;
    //     countstat1 = calculatedheight;

    // }else if (value > 110 && value < 120){
    //     float calculatedheight = 0.2;
    //     countstat1 = calculatedheight;
        
    // }else if (value > 120 && value < 130){
    //     float calculatedheight = 0.3;
    //     countstat1 = calculatedheight;
    // }else if (value > 130 && value < 140){
    //     float calculatedheight = 0.4;
    //     countstat1 = calculatedheight;

    // }else if (value > 140 && value < 150){
    //     float calculatedheight = 0.5;
    //     countstat1 = calculatedheight;

    // }else if (value > 150 && value < 160){
    //     float calculatedheight = 0.6;
    //     countstat1 = calculatedheight;

    // }else if (value > 160 && value < 170){
    //     float calculatedheight = 0.7;
    //     countstat1 = calculatedheight;

    // }else if (value > 170 && value < 180){
    //     float calculatedheight = 0.8;
    //     countstat1 = calculatedheight;

    // }else if (value > 180 && value < 190){
    //     float calculatedheight = 0.9;
    //     countstat1 = calculatedheight;

    // }else if (value > 190 && value < 200){
    //     float calculatedheight = 1.0;
    //     countstat1 = calculatedheight;

    // }else if (value > 200 && value < 210){
    //     float calculatedheight = 1.1;
    //     countstat1 = calculatedheight;

    // }else if (value > 210 && value < 220){
    //     float calculatedheight = 1.2;
    //     countstat1 = calculatedheight;

    // }else if (value > 220 && value < 230){
    //     float calculatedheight = 0.1;
    //     countstat1 = calculatedheight;

    // }else if (value > 230 && value < 240){
    //     float calculatedheight = 1.3;
    //     countstat1 = calculatedheight;

    // }else if (value > 240 && value < 250){
    //     float calculatedheight = 1.4;
    //     countstat1 = calculatedheight;

    // }else if (value > 250 && value < 260){
    //     float calculatedheight = 1.5;
    //     countstat1 = calculatedheight;

    // }else if (value > 260 && value < 270){
    //     float calculatedheight = 1.6;
    //     countstat1 = calculatedheight;

    // }else if (value > 270 && value < 280){
    //     float calculatedheight = 1.7;
    //     countstat1 = calculatedheight;

    // }else if (value > 280 && value < 290){
    //     float calculatedheight = 1.8;
    //     countstat1 = calculatedheight;

    // }else if (value > 290 && value < 300){
    //     float calculatedheight = 1.9;
    //     countstat1 = calculatedheight;
    // }else if (value > 300 && value < 310){
    //     float calculatedheight = 2.0;
    //     countstat1 = calculatedheight;

    // }else if (value > 310 && value < 320){
    //     float calculatedheight = 2.1;
    //     countstat1 = calculatedheight;

    // }else if (value > 320 && value < 330){
    //     float calculatedheight = 2.2;
    //     countstat1 = calculatedheight;


    // }else if (value > 330 && value < 340){
    //     float calculatedheight = 2.3;
    //     countstat1 = calculatedheight;

    // }else if (value > 340 && value < 350){
    //     float calculatedheight = 2.4;
    //     countstat1 = calculatedheight;

    // }else if (value > 350 && value < 360){
    //     float calculatedheight = 2.5;
    //     countstat1 = calculatedheight;

    // }
    /* Calculating distance in cm */
    


    return countstat1;
}

#ifdef i2c_default
static void mpu6050_reset() {
    // Two byte reset. First byte register, second byte data
    // There are a load more options to set up the device in different ways that could be added here
    uint8_t buf[] = {0x6B, 0x00};
    i2c_write_blocking(i2c_default, addr, buf, 2, false);
}

static void mpu6050_read_raw(int16_t accel[3], int16_t gyro[3], int16_t *temp) {
    // For this particular device, we send the device the register we want to read
    // first, then subsequently read from the device. The register is auto incrementing
    // so we don't need to keep sending the register we want, just the first.

    uint8_t buffer[6];

    // Start reading acceleration registers from register 0x3B for 6 bytes
    uint8_t val = 0x3B;
    i2c_write_blocking(i2c_default, addr, &val, 1, true); // true to keep master control of bus
    i2c_read_blocking(i2c_default, addr, buffer, 6, false);

    for (int i = 0; i < 3; i++) {
        accel[i] = (buffer[i * 2] << 8 | buffer[(i * 2) + 1]);
    }

    // Now gyro data from reg 0x43 for 6 bytes
    // The register is auto incrementing on each read
    val = 0x43;
    i2c_write_blocking(i2c_default, addr, &val, 1, true);
    i2c_read_blocking(i2c_default, addr, buffer, 6, false);  // False - finished with bus

    for (int i = 0; i < 3; i++) {
        gyro[i] = (buffer[i * 2] << 8 | buffer[(i * 2) + 1]);;
    }

    // Now temperature from reg 0x41 for 2 bytes
    // The register is auto incrementing on each read
    val = 0x41;
    i2c_write_blocking(i2c_default, addr, &val, 1, true);
    i2c_read_blocking(i2c_default, addr, buffer, 2, false);  // False - finished with bus

    *temp = buffer[0] << 8 | buffer[1];
}
#endif

int main() {
    stdio_init_all();
#if !defined(i2c_default) || !defined(PICO_DEFAULT_I2C_SDA_PIN) || !defined(PICO_DEFAULT_I2C_SCL_PIN)
    #warning i2c/mpu6050_i2c example requires a board with I2C pins
    puts("Default I2C pins were not defined");
#else
    printf("Hello, MPU6050! Reading raw data from registers...\n");

    // This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    mpu6050_reset();

    int16_t acceleration[3], gyro[3], temp;

    while (1) {
        mpu6050_read_raw(acceleration, gyro, &temp);
        //float value = getHeight((float)gyro[1]);

        val11 = val10;
        val10 = val9;
        val9 = val8;
        val8 = gyro[2];
        
        val7 = val6;
        val6 = val5;
        val5 = val4;
        val4 = gyro[1];

        val3 = val2;
        val2 = val1;
        val1 = val0;
        val0 = gyro[0];

        max = max+1;

        if (max>3){
            // int countstat =(val3+val2+val1+val0)/4;
            int countstat1 =(val7+val6+val5+val4)/4;
            // int countstat2 = (val11+val10+val9+val8)/4;

            if (countstat1 >= -500){
                float calculatedheight = 0.0;
                printf("height1 = %.1f \n", calculatedheight);
                printf("countstat = %d \n", countstat1);

            }else if (countstat1 < -500 && countstat1 >= -800){
                float calculatedheight = 0.5;
                printf("height1 = %.1f \n", calculatedheight);
                printf("countstat = %d \n", countstat1);

            }else if (countstat1 < -800 && countstat1 >= -1100){
                float calculatedheight = 1.0;
                printf("height1 = %.1f \n", calculatedheight);
                printf("countstat = %d \n", countstat1);
            
            }
            else if (countstat1 < -1100 && countstat1 >= -1400){
                float calculatedheight = 1.5;
                printf("height1 = %.1f \n", calculatedheight);
                printf("countstat = %d \n", countstat1);
            
            }
            else if (countstat1 < -1400 && countstat1 >= -1700){
                float calculatedheight = 2.0;
                printf("height1 = %.1f \n", calculatedheight);
                printf("countstat = %d \n", countstat1);
            
            }
            else if (countstat1 < -1700 && countstat1 >= -2000){
                float calculatedheight = 2.5;
                printf("height1 = %.1f \n", calculatedheight);
                printf("countstat = %d \n", countstat1);
            
            }
            else if (countstat1 < -2000 && countstat1 >= -2300){
                float calculatedheight = 3.0;
                printf("height1 = %.1f \n", calculatedheight);
                printf("countstat = %d \n", countstat1);
            
            }
        }

        // if (gyro[2] <= -500){
        //     float calculatedheight = 0.0;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[2] > -500 && gyro[2] <= -300){
        //     float calculatedheight = 1.0;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[2] > -300 && gyro[2] <= -100){
        //     float calculatedheight = 2.0;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);
            
        // }else if (gyro[1] > 180 && gyro[1] < 215){
        //     float calculatedheight = 0.3;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 215 && gyro[1] <= 250){
        //     float calculatedheight = 0.4;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 250 && gyro[1] <= 320){
        //     float calculatedheight = 0.5;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 320 && gyro[1] <= 355){
        //     float calculatedheight = 0.6;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 355 && gyro[1] <= 390){
        //     float calculatedheight = 0.7;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 390 && gyro[1] <= 425){
        //     float calculatedheight = 0.8;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 425 && gyro[1] <= 460){
        //     float calculatedheight = 0.9;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 460 && gyro[1] <= 495){
        //     float calculatedheight = 1.0;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 495 && gyro[1] <= 530){
        //     float calculatedheight = 1.1;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 530 && gyro[1] <= 565){
        //     float calculatedheight = 1.2;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 565 && gyro[1] <= 600){
        //     float calculatedheight = 0.1;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 635 && gyro[1] <= 670){
        //     float calculatedheight = 1.3;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 670 && gyro[1] <= 705){
        //     float calculatedheight = 1.4;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 705 && gyro[1] <= 740){
        //     float calculatedheight = 1.5;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 740 && gyro[1] <= 775){
        //     float calculatedheight = 1.6;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 775 && gyro[1] <= 810){
        //     float calculatedheight = 1.7;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 810 && gyro[1] <= 845){
        //     float calculatedheight = 1.8;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 845 && gyro[1] <= 880){
        //     float calculatedheight = 1.9;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 880 && gyro[1] <= 915){
        //     float calculatedheight = 2.0;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 915 && gyro[1] <= 950){
        //     float calculatedheight = 2.1;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 950 && gyro[1] <= 985){
        //     float calculatedheight = 2.2;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 985 && gyro[1] <= 1020){
        //     float calculatedheight = 2.3;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 1020 && gyro[1] <= 1055){
        //     float calculatedheight = 2.4;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }else if (gyro[1] > 1055 && gyro[1] <= 1090){
        //     float calculatedheight = 2.5;
        //     countstat1 = calculatedheight;
        //     printf("height1 = %.1f \n", calculatedheight);

        // }

        // float calculatedheight = countstat - countstat1;
        // These are the raw numbers from the chip, so will need tweaking to be really useful.
        // See the datasheet for more information
        //printf("Acc. X = %d, Y = %d, Z = %d\n", acceleration[0], acceleration[1], acceleration[2]);
        // printf("height1 = %.1f \n", calculatedheight);
        //printf("%d \n", gyro[1]);
        // printf("%d, %d, %d\n", countstat, countstat1, countstat2);
        // printf("%d %d %d %d\n", val0, val1, val2, val3);
        // printf("%d %d %d %d\n", val4, val5, val6, val7);
        // printf("%d %d %d %d\n", val8, val9, val10, val11);
        // Temperature is simple so use the datasheet calculation to get deg C.
        // Note this is chip temperature.
        //printf("Temp. = %f\n", (temp / 340.0) + 36.53);

        sleep_ms(1000);
    }

#endif
    return 0;
}
