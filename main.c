
#include "panel_handler.h"
#include "stop_handler.h"
#include "door_handler.h"
#include <stdio.h>


int main() {
    	// Initialize hardware
    	if (!elev_init()) {
        	printf("Unable to initialize elevator hardware!\n");
        	return 1;
    	}
	door_open();
	while(!door_close()){
		
		
	}
	
    	struct elevator_data test_3 = {0,0,0,0,0,0,{{0,0,0,0},{0,0,0,0},{0,0,0,0}}};

    	elev_set_motor_direction(DIRN_UP);

    	while (1) {
        	// Change direction when we reach top/bottom floor
		//floor_get_update();
		panel_get(&test_3);
		panel_set_lights(test_3);
		stop_emergency_stop(&test_3);
	

        	if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
			test_3.dir = DIRN_DOWN;        	    	
        	} else if (elev_get_floor_sensor_signal() == 0) {
        	    	test_3.dir = DIRN_UP;   
			
        	}


		elev_set_motor_direction(test_3.dir);
        	// Stop elevator and exit program if the stop button is pressed
        	if (elev_get_stop_signal()) {
            		elev_set_motor_direction(DIRN_STOP);
            		//break;
        	}
    	}
    	return 0;
}


