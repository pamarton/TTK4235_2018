#ifndef __INCLUDE_COMMON_H__
#define __INCLUDE_COMMON_H__

#define N_BUTTONTYPES 3
#ifndef N_FLOORS 
#define N_FLOORS 4
#endif

struct elevator_data{
	int lock;
	int stop;
	int obstruct;
	int floor;
	int last_floor;
	int dir;
	int orders[N_BUTTONTYPES][N_FLOORS];
}inputs;

#endif //__INCLUDE_COMMON_H__
