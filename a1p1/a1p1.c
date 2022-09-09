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
	char c;
	int inumber, inibble, ibit, ishift = 0;
	
	uart_init();
	uart_clear();
	uart_puts("a1p1\n");
	uart_puts("\n");
	uart_puts("Hello World!\n");
	uart_puts("Hello World1!\n");
	uart_puts("Hello World2!\n");

	
	
	iRegister *temp;
	temp = malloc(sizeof(* temp));
	temp->content = 12708934;
    uart_puts(toBinary(temp->content,32)); 
	resetBit(1,temp);
	uart_puts(toBinary(temp->content,32)); 
	
	uart_puts("End of code\n");
    
    // To Display a string
	// uart_puts("String\n");
	// To get one character
	// c=uart_getc();
	
	// To get a number, you might want to call uart_getc multiple times until receiving a new line.
	// The results of each call to uart_getc can be stored into str
	// atoi(str) will result a number.
}