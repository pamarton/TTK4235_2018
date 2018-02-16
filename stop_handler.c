#include "stop_handler.h"

void stop_emergency_stop(struct elevator_data * inputmap){
	if(inputmap->stop){
		elev_set_motor_direction(DIRN_STOP);	
		for(int type = 0; type < N_BUTTONTYPES; type++){
			for(int floor = 0; floor < N_FLOORS; floor++){
				inputmap->orders[type][floor] = 0;
			}	
		}
		panel_set_lights(*inputmap);
		while(elev_get_stop_signal());
		if (inputmap->floor >= 0 && inputmap->floor < N_FLOORS){
			door_open();
		}else{
			
		}
	}
	
	
	//if floor: open door
	//if floor: wait for 3 seconds
	//if floor: close door
}
