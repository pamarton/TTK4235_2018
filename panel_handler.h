#ifndef __INCLUDE_PANEL_HANDLER_H__
#define __INCLUDE_PANEL_HANDLER_H__

#include "elev.h"
#include <stdio.h>
#define N_BUTTONTYPES 3
void panel_print(int printout[N_BUTTONTYPES][N_FLOORS]);
int test(void);
int panel_get(int orders[N_BUTTONTYPES][N_FLOORS]);
void panel_set_lights(int orders[N_BUTTONTYPES][N_FLOORS]);
#endif //__INCLUDE_PANEL_HANDLER_H__
