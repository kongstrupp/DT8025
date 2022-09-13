//
// Created by Wilhelm on 2022-09-08.
//

//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Updated by Wagner Morais and Hazem Ali on 26/08/21.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"

int powerOf(int x,int n) {
    int i;
    int number = 1;

    for (i = 0; i < n; ++i) {
        number *= x;
    }

    return(number);
}

void resetBit(int i, iRegister *r) {
    // pre-condition
    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to resetBit\n");
        return;
    }
    // pre-condition
    if( i < 0 || i > 31)
    {
        fprintf(stderr,"Error: Invalid bit in resetBit\n");
        return;
    }

    r->content &= ~(1 << i); //sets bit to zero

    // post-condition
    if((r->content & (1<<i)) != 0)
    {
        fprintf(stderr, "Error: Failed to reset Bit in resetBit\n");
        return;
    }



}

void resetAll(iRegister *r) {

    // pre-condition
    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to resetAll\n");
        return;
    }

    for( int i = 0; i < 32; i++){
        r->content &= ~(1 << i);
    }

    int n = r->content;
    //Post condition check all the zeros
    for( int i = 0; i < 32; i++){
        if(((n & ( 1 << i )) >> i) == 1){
            fprintf(stderr, "Error: Failed to Reset all in resetAll\n");
            break;
        }
    }

}

void setBit(int i, iRegister *r) {

    // pre-condition
    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to setBit\n");
        return;
    }
    // pre-condition
    if( i < 0 || i > 31)
    {
        fprintf(stderr,"Error: Invalid bit in setBit\n");
        return;
    }

    r->content |= (1 << i); //sets bit to zero

    //Post Condtion
    if((r->content & (1<<i)) == 0)
    {
        fprintf(stderr, "Error: Failed to set Bit in setBit\n");
        return;
    }

}

void setAll(iRegister *r) {

    // Pre-condition
    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to setAll\n");
        return;
    }

    for(int i = 0; i < 32; i++){
        r->content |= (1 << i);
    }

    //Post condition
    for(int i = 0; i < 32; i++){
        if((r->content & (1<<i)) == 0)
        {
            fprintf(stderr, "Error: A bit was not set in setAll\n");
            return;
        }
    }

}

int getBit(int i, iRegister *r) {

    //Pre condition
    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to getBit\n");
        return 0;
    }

    //Pre condition
    if( i < 0 || i > 31)
    {
        fprintf(stderr,"Error: Invalid bit in getBit\n");
        return 0;
    }

    int ret = r->content >> i & 1;

    //Post condition
    if(ret < 0 || ret > 1) {
        fprintf(stderr,"Error: Failed to get bit in getBit\n");
        return 0;
    }

    return ret;
}

void assignNibble(int pos , int value , iRegister *r) {

    // pre-condition
    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to assignNibble\n");
        return;
    }

    // pre-condition
    if(pos < 0 || pos > 7)
    {
        fprintf(stderr,"Invalid nibble position\n");
        return;
    }

    // pre-condition
    if (value < 0 || value > 15){
        fprintf(stderr,"Invalid value\n");
        return;
    }

    int binaryNum[4] = {0,0,0,0};
    int i=0;

    // Make an array that have an binary representation of the number
    for ( ;value > 0; ){
        binaryNum[i++] = value % 2;
        value /= 2;
    }

    //Target the starting bit of the nibble
    int targetPos = pos * 4;

    // for (int j = i-1; j >= 0; j--)
    //Loop binary array and set the bits in r
    for (int j = 0; j < 4; j++) {

        if (binaryNum[j] == 1) {
            setBit(targetPos,r);
            targetPos++;
        }
        if (binaryNum[j] == 0) {
            resetBit(targetPos,r);
            targetPos++;
        }
    }

    int targetPosCon = pos * 4;

    //Post condition
    for(int n = 0; n < 4; n++){
        if (binaryNum[n] != getBit(targetPosCon,r)){
            fprintf(stderr,"Nibble was not assigned in assignNibble\n");
            return;
        }
        targetPosCon++;
    }
}

int getNibble(int pos, iRegister *r) {

    // pre-condition
    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to assignNibble\n");
        return 0;
    }

    // pre-condition
    if( pos < 0 || pos > 7)
    {
        fprintf(stderr,"Invalid nibble position\n");
        return 0;
    }

    int targetPos = pos * 4;;
    int nibble[4] = {0,0,0,0};

    for (int j = 0; j < 4; j++) {
        nibble[j] = getBit(targetPos,r);
        targetPos++;
    }

    int nibbleValue = 0;

    for(int k = 0; k < 4; k++) {
        if (nibble[k] == 1){
            nibbleValue += powerOf(2,k);
        }
    }

    if (nibbleValue < 0 || nibbleValue > 15) {
        fprintf(stderr,"Error: Failed to get the nibble value\n");
        return 0;
    }

    //Post Condition
    return nibbleValue;
}

char *reg2str(iRegister r) {
    char* binary = (char*)malloc(sizeof(char) * 32);
    int k = 0;
    for (unsigned i = (1 << (32 - 1)); i > 0; i = i / 2) {
        binary[k++] = ((r.content) & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}

void shiftRight(int i, iRegister *r) {

    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to shiftRight\n");
        return;
    }

    r->content = (r->content >> i);
}

void shiftLeft(int i, iRegister *r) {

    if(r == NULL)
    {
        fprintf(stderr, "Error: A NULL pointer was given to shiftLeft\n");
        return;
    }

    r->content = (r->content << i);
}



