/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
	Wagner de Morais (Wagner.deMorais@hh.se)
*/

#include <stdio.h>

#include "expstruct.h"
#include "piface.h"

int main()
{
	piface_init();
	piface_clear();
	
	char str[80];
	
	piface_puts("DT8025 - A2P2");
	RPI_WaitMicroSeconds(2000000);	
    piface_clear();
	
    ExpStruct* value;
	
    while(1){
		for (int i = 0; i < 22; i++){
		value = iexp(i);
		sprintf(str,"%d: %d.%d", i, value->expInt, value->expFraction);
		piface_clear();
		piface_puts(str);
		free(value);
	    }
	}

	return 0;

}