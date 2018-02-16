#ifndef __INCLUDE_STATE_MACHINE_H__
#define __INCLUDE_STATE_MACHINE_H__

#include "elev.h"
#include <stdio.h>
#include "panel_handler.h"
#define N_STATES "SKRIVNOEHER"

enum elevator_state{
	state_init = 0,
	state_waiting = 1,
	state_stop = 2,
	state_checkinput = 3,
	state_checkpos = 4,
	state_drive = 5,
};


void new_state(void);

#endif //__INCLUDE_STATE_MACHINE_H__
