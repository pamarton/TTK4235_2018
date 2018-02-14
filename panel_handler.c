#include "panel_handler.h"
#define PRINTOUT 1
void panel_print(int printout[N_BUTTONTYPES][N_FLOORS]){
	
	printf("\tDOWN\tUP\t\tFLOOR\n");
	for(int i = N_BUTTONTYPES; i >= 0; i--){
		printf("|\t%i\t%i\t|\n",printout[BUTTON_CALL_DOWN][i],printout[BUTTON_CALL_UP][i]);
	}
	printf("####################################\nCOMMAND\t%i\t%i\t%i\t%i\n",printout[BUTTON_COMMAND][0],printout[BUTTON_COMMAND][1],printout[BUTTON_COMMAND][2],printout[BUTTON_COMMAND][3]);	
}

int panel_get(int orders[N_BUTTONTYPES][N_FLOORS]){
	int pressed = 0;
	for(int floor = 0; floor < N_FLOORS; floor++){
		if(elev_get_button_signal(BUTTON_COMMAND,floor) && !orders[BUTTON_COMMAND][floor]){
			orders[BUTTON_COMMAND][floor] = 1;
			pressed = 1;
		}
	}
	for(int floor = 0; floor < N_FLOORS-1; floor++){
		if(elev_get_button_signal(BUTTON_CALL_DOWN,floor+1) && !orders[BUTTON_CALL_DOWN][floor+1]){
			orders[BUTTON_CALL_DOWN][floor+1] = 1;
			pressed = 1;
		}
		if(elev_get_button_signal(BUTTON_CALL_UP,floor) && !orders[BUTTON_CALL_UP][floor]){
			orders[BUTTON_CALL_UP][floor] = 1;
			pressed = 1;
		}
	}
	if(pressed){
		
		panel_set_lights(orders);
		return 1;
	}
	return 0;
}

void panel_set_lights(int orders[N_BUTTONTYPES][N_FLOORS]){
	for(int floor = 0; floor < N_FLOORS; floor++){
		elev_set_button_lamp(BUTTON_COMMAND,floor,orders[BUTTON_COMMAND][floor]);
	}
	for(int floor = 0; floor < N_FLOORS-1; floor++){
		elev_set_button_lamp(BUTTON_CALL_DOWN,floor+1,orders[BUTTON_CALL_DOWN][floor+1]);
		elev_set_button_lamp(BUTTON_CALL_UP,floor,orders[BUTTON_CALL_UP][floor]);
	}
	#if PRINTOUT
	panel_print(orders);
	printf("LYS SATT\n");
	#endif
}


int test(void){
	printf("TEST 2");
	return 0;
}

