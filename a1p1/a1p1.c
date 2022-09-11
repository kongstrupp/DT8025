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






int main() {
	//iRegister r;
	char str[LINE];
	char str1[LINE];
	char c;
	int inumber, inibble, ibit, ishift = 0;
	int i = 0;
	
	uart_init();
	uart_clear();

	uart_puts("DT8025 - Assignment 1 - Part 1\n");
	uart_puts("Enter you name: ");

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
	
	
	
	
	
}


/*

//uart_puts(c);
	//int i = 0;


	/*
	
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
	*/
	/*
	8
	15/namespace
	str[0] = '1';
	str[1] = '2';
	str[2] = '\0';	
	int i = atoi(str);
	*/
	//uart_puts(str);
	
	
	//And Test this
	//uart_puts(x);
	//uart_puts("\n");
	
	
	/*
	iRegister *temp;
	temp = malloc(sizeof(* temp));
	temp->content = 12708934;
    uart_puts(toBinary(temp->content,32)); 
	resetBit(1,temp);
	uart_puts(toBinary(temp->content,32)); 
	*/
	//uart_puts("End of code\n");
    
    // To Display a string
	// uart_puts("String\n");
	// To get one character
	// c=uart_getc();
	
	// To get a number, you might want to call uart_getc multiple times until receiving a new line.
	// The results of each call to uart_getc can be stored into str
	// atoi(str) will result a number.



*/