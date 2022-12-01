#include <gb/gb.h>
#include <stdio.h>
#include <string.h>
#include <gbdk/console.h>

#include "../globals.h"
#include "../helpers.h"
#include "../../inputs/input_01.h"

#pragma bank 1

bool executed_1a;

void init_1a() {
	executed_1a = false;
}

void execute_1a() {
	uint32_t highest_calories = 0;
	uint32_t calories = 0;

	for (uint16_t i = 0; i < array_size; ++i) {
		if (input_array[i] != 0) {
			calories += input_array[i];
			if (calories > highest_calories) {
				highest_calories = calories;
			}
		} else {
			calories = 0;
		}
	}

	gotoxy(0, 0);
	print_32(&highest_calories);
}

void run_1a() {
	if (!executed_1a) {
		execute_1a();
		executed_1a = true;
	}
	wait_vbl_done();
}
