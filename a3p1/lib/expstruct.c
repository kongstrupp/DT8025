/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
 */
/*
 * Modified by Wagner Morais on Aug 2022.
 */
 
#include <stddef.h>
#include <stdlib.h>
#include "expstruct.h"
#include "rpi-systimer.h"

ExpStruct *iexp(int x){
	ExpStruct *e = malloc(sizeof(ExpStruct));

    double power;
    power = (double) x;
	
    double ans = 1;
    double temp = 1;
    int i = 1;
    
	while(temp > 0.001){
		RPI_WaitMicroSeconds(100000);
        led_blink();
		temp=(temp*power)/i;
        ans=ans+temp;
		i++;
	}


    e->expInt = (int) ans;
    e->expFraction = (int) ((ans - e->expInt) * 100);
	
	return e;
}
