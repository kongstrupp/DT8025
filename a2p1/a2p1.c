/*
	Modified by Wagner Morais on Sep 2022.
 */

#include <stdio.h>
#include "piface.h"

int main()
{
	piface_init();
	
	while(1){
		piface_puts("Short string");
		delay(600);
		piface_clear();
		piface_puts("This is a long string");
		delay(600);
		piface_clear();
		piface_puts("1st line\n2nd line");
		delay(600);
		piface_clear();
	}
	
	return 0;
}