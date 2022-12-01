#include <gb/gb.h>
#include <gbdk/font.h>

#include "globals.h"

#include "states/intro.h"
#include "states/01a.h"
#include "states/01b.h"

#include "../res/maps/intro_map.h"

void main(void) {
	// Create font
	font_init();

	const font_t spect_font = font_load(font_spect);
	font_set(spect_font);

	init_intro();
	state = STATE_INTRO;

    // Loop forever
    while(1) {
		UPDATE_KEYS();
		switch (state) {
			case STATE_INTRO:
				run_intro();
				break;
			case STATE_1A:
				run_1a();
				break;
			case STATE_1B:
				run_1b();
				break;
		}

		if (KEY_TICKED(J_START) && state != STATE_INTRO) {
			init_intro();
			state = STATE_INTRO;
		}
    }
}
