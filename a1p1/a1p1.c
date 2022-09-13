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


char* toBinary(int n, int len){
    char* binary = (char*)malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}


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
	setAll(&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	uart_puts("resetAll(&r) ");
	resetAll(&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("setBit(2,&r) ");
	setBit(ibit,&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	//r.content = inumber;
	uart_puts("getBit(2,&r) ");
	getBit(ibit,&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("resetBit(2,&r) ");
	resetBit(ibit,&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("assignNibble(2,1,&r) ");
	assignNibble(inibble,1,&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("getNibble(2,&r) ");
	getNibble(inibble,&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("shiftRight(2,&r) ");
	shiftRight(ishift,&r);
	uart_puts(reg2str(r));

	uart_puts("\n");
	r.content = inumber;
	uart_puts("shiftLeft(2,&r) ");
	shiftLeft(ishift,&r);
	uart_puts(reg2str(r));

	
	











	

	
	
}


/*

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
	
	uart_puts("\n");
	uart_puts("Welcome ");
	uart_puts(str);

	uart_puts("Enter an integer numeber (32-bit): ");
	uart_puts("Enter a bit position (0<=bit<=31): ");
	uart_puts("Enter a nibble position (0<=nibble<=7): ");
	uart_puts("Enter the number of bits to shift (1<=bits<=31): ")
	uart_puts("You entered number ");

	

	r = malloc(sizeof(* r));
	r->content = 24213;

	uart_puts(toBinary(r->content,32));
	uart_puts("\n");
	resetBit(1,r);
	uart_puts(toBinary(r->content,32));

	free(r);
	

*/ 



/*
//uart_puts(c);
//int i = 0;



	
	str[0] = 'H';
	str[1] = 'i';
	str[2] = '\0';
	uart_puts(str);
	while(c=uart_getc()) {
		if (c = '\n'){
		   break;
		}
		str[i++] = c;
		uart_puts(c);
	}
	
	
	8
	15/namespace
	str[0] = '1';
	str[1] = '2';
	str[2] = '\0';	
	int i = atoi(str);
	
	//uart_puts(str);
	
	
	//And Test this
	//uart_puts(x);
	//uart_puts("\n");
	
	
	
	iRegister *temp;
	temp = malloc(sizeof(* temp));
	temp->content = 12708934;
    uart_puts(toBinary(temp->content,32)); 
	resetBit(1,temp);
	uart_puts(toBinary(temp->content,32)); 
	
	//uart_puts("End of code\n");
    
    // To Display a string
	// uart_puts("String\n");
	// To get one character
	// c=uart_getc();
	
	// To get a number, you might want to call uart_getc multiple times until receiving a new line.
	// The results of each call to uart_getc can be stored into str
	// atoi(str) will result a number.
	*/