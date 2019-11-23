/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"
#include "./mpu6050.h"

// // for use in mpu6050
// #define I2C_SDA I2C1_SDA
// #define I2C_SDL I2C1_SDL

// #include "MPU6050.h"
#include "MPU6050.h"


// Blinking rate in milliseconds
// #define DIG_SWITCH_RATE 2
// #define DIG_SWITCH_COUNT 100
// #define INCREMENT_PERIOD 20
// #define DIG_SWITCH_RATE 1
// #define DIG_SWITCH_COUNT (INCREMENT_PERIOD / DIG_SWITCH_RATE)
#define SLEEP_PERIOD 20

Serial pc(SERIAL_TX, SERIAL_RX);

// I2C i2c(PF_0, PF_1);

int main()
{
	MPU6050 mpu;

    pc.printf("Initializing I2C devices...\n");
    mpu.initialize();

    // verify connection
    pc.printf("Testing device connections...\n");
    pc.printf(mpu.testConnection() ? "MPU6050 connection successful\n" : "MPU6050 connection failed\n");

	int16_t ax;
	int16_t ay;
	int16_t az;

	int16_t gx;
	int16_t gy;
	int16_t gz;


	while (true) {
		// pc.printf("GETTING MOTION\n");
		mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
		// pc.printf("PRINTING MOTION\n");
		pc.printf("AX: %06d, AY: %06d, AZ: %06d\n", (int)ax, (int)ay, (int)az);
		// thread_sleep_for(SLEEP_PERIOD);
	}

	return 0;
}

// void show_digit(int digIdx, int val)
// {
// 	for (int i = 0; i < digIdx; ++i) {
// 		val /= 10;
// 	}

// 	//   a b c d e f g decimal-pt
// 	const int test[10][8] = {
// 		{1,1,1,1,1,1,0,0}, // 0
// 		{0,1,1,0,0,0,0,0}, // 1
// 		{1,1,0,1,1,0,1,0}, // 2
// 		{1,1,1,1,0,0,1,0}, // 3
// 		{0,1,1,0,0,1,1,0}, // 4
// 		{1,0,1,1,0,1,1,0}, // 5
// 		{1,0,1,1,1,1,1,0}, // 6
// 		{1,1,1,0,0,0,0,0}, // 7
// 		{1,1,1,1,1,1,1,0}, // 8
// 		{1,1,1,1,0,1,1,0}, // 9
// 	};

// 	int digit = val % 10;

// 	dig0 = (digIdx == 0);
// 	dig1 = (digIdx == 1);
// 	dig2 = (digIdx == 2);
// 	dig3 = (digIdx == 3);

// 	seg0 = !test[digit][0];
// 	seg1 = !test[digit][1];
// 	seg2 = !test[digit][2];
// 	seg3 = !test[digit][3];
// 	seg4 = !test[digit][4];
// 	seg5 = !test[digit][5];
// 	seg6 = !test[digit][6];
// 	seg7 = !test[digit][7];
// }

// int main()
// {
// 	int val = 0;

// 	// while (true) {
// 	// 	val++;
// 	// 	if (val == 10000) val = 0;
// 	// 	pc.printf("%d\n", val);

// 	// 	for (int i = 0; i < DIG_SWITCH_COUNT; ++i) {
// 	// 		// digit of display to multiplex to
// 	// 		int digIdx = i % 4;

// 	// 		show_digit(digIdx, val);
// 	// 		thread_sleep_for(DIG_SWITCH_RATE);
// 	// 	}
// 	// }
// }
