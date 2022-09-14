/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
	Wagner de Morais (Wagner.deMorais@hh.se)
*/

#include <stdio.h>
#include "uart.h"
#include "iregister.h"

#define LINE 80

// Itoa from the regular library doest seem to work so took an finished function from the internet 
char* itoa(int value, char* result, int base) {
    if (base < 2 || base > 36) { *result = '\0'; return result; }
    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

// Scan the next String
void scanNext(char str[LINE]){

	char str1[LINE];
	char c;
	int i = 0;

	while(c=uart_getc()) {
		if (c == '\n' || i == LINE)	{
		   str[i++] = '\0';
		   break;
		}
		str[i++] = c;
		str1[0] = c;
		str1[1] = '\0';
		uart_puts(str1);
	}
	
}

// Scan the next number and return that number as an int 
int scanNextNumber(char str[LINE]){

	char str1[LINE];
	int retNumber;
	char c;
	int i = 0;

	while(c=uart_getc()) {
		if (c == '\n' || i == LINE)	{
		   str[i++] = '\0';
		   break;
		}
		str[i++] = c;
		str1[0] = c;
		str1[1] = '\0';
		uart_puts(str1);
	}

	retNumber = atoi(str);

	return retNumber;
}


int main() {

	iRegister r;

	char str[LINE];
	char str1[LINE];
	char str2[LINE];
	char str3[LINE];

	char inum[LINE];
	char inib[LINE];
	char ib[LINE];
	char is[LINE];

	char c;
	int inumber, inibble, ibit, ishift = 0;
	int i = 0;
		
	uart_init();
	uart_clear();

	uart_puts("DT8025 - Assignment 1 - Part 1\n");
	uart_puts("\n");
	uart_puts("Enter your name: ");
	scanNext(str);
	uart_puts("\n");
	uart_puts("Welcome ");
	uart_puts(str);


	uart_puts("\n");
	uart_puts("Enter an integer numeber (32-bit): ");
	inumber = scanNextNumber(inum);
	r.content = inumber;
	
	uart_puts("\n");
	uart_puts("Enter a bit position (0<=bit<=31): ");
	ibit = scanNextNumber(ib);

	uart_puts("\n");
	uart_puts("Enter a nibble position (0<=nibble<=7): ");
	inibble = scanNextNumber(inib);


	uart_puts("\n");
	uart_puts("Enter the number of bits to shift (1<=bits<=31): ");
	ishift = scanNextNumber(is);

	uart_puts("\n");
	uart_puts("You entered the number: ");
	uart_puts(inum);
	uart_puts(" ");
	uart_puts(reg2str(r));
	
	uart_puts("\n");
	uart_puts("Bit: ");
	uart_puts(ib);

	uart_puts(" Nibble: ");
	uart_puts(inib);

	uart_puts("\n");
	uart_puts("setAll(&r) ");
	uart_puts("returned ");
	setAll(&r);
	itoa(r.content,str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	uart_puts("resetAll(&r) ");
	uart_puts("returned ");
	resetAll(&r);
	itoa(r.content,str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	itoa(ibit,str3,10);
	uart_puts("setBit(");
	uart_puts(str3);
	uart_puts(",&r) ");
	uart_puts("returned ");
	setBit(ibit,&r);
	itoa(r.content,str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	uart_puts("getBit(");
	uart_puts(str3);
	uart_puts(",&r) ");
	uart_puts("returned ");
	itoa(getBit(ibit,&r),str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("resetBit(");
	uart_puts(str3);
	uart_puts(",&r) ");
	uart_puts("returned ");
	resetBit(ibit,&r);
	itoa(r.content,str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	itoa(inibble,str3,10);
	uart_puts("assignNibble(");
	uart_puts(str3);
	uart_puts(",1,&r) ");
	uart_puts("returned ");
	assignNibble(inibble,1,&r);
	itoa(r.content,str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	uart_puts("getNibble(");
	uart_puts(str3);
	uart_puts(",&r) ");
	uart_puts("returned ");
	itoa(getNibble(inibble,&r),str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	itoa(ishift,str3,10);
	uart_puts("shiftRight(");
	uart_puts(str3);
	uart_puts(",&r) ");
	uart_puts("returned ");
	shiftRight(ishift,&r);
	itoa(r.content,str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("shiftLeft(");
	uart_puts(str3);
	uart_puts(",&r) ");
	uart_puts("returned ");
	shiftLeft(ishift,&r);
	itoa(r.content,str2,10);
	uart_puts(str2);
	uart_puts(" ");
	uart_puts(reg2str(r));
}
