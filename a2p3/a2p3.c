/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
	Wagner de Morais (Wagner.deMorais@hh.se)
*/

#include <stdio.h>
#include "expstruct.h"
#include "piface.h"
#include "led.h"

#define LINE 32

int main()
{
	
	char str[LINE];
	led_init();
	piface_init();
	piface_clear();

	piface_puts("DT8025 - A2P3");
	RPI_WaitMicroSeconds(2000000);	
	
    ExpStruct* value;
  
	int cnt = 0;
    int i; 
	// cyclic execution
    while (1){
        for(i=1; i < 21; i++){
			value = iexp(i);
			sprintf(str,"%d: %d.%d", i, value->expInt, value->expFraction);
			piface_clear();
			piface_puts(str);
			free(value);
        }        
    }
	return 0;

}
