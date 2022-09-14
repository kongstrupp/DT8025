//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#ifndef lab0_iregister_h
#define lab0_iregister_h

/**
 *  iRegister
 *  An iRegister is a structure which represents an 32-bit register and
 *  is equipped with standard operations to modify and display them.
 */ 
typedef struct{
    int content;
} iRegister;

/** @brief Resets all the bits 
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: Check all bits == zero 
 */
void resetAll(iRegister *);

/** @brief set a bit to 1
 * 
 *  @param i The bit position that will be set 
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: iRegister != Null and ( i < 0 || i > 31)
 * 
 *  Post-condition: ((r->content & (1<<i)) == 0) check that it is not zero
 */
void setBit(int, iRegister *);

/** @brief set all bits to 1
 *  
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: (r->content & (1<<i)) == 0) check all bits that they are not zero
 */
void setAll(iRegister *);

/** @brief get a bit at postion
 *  
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @param i bit position to get bit from  
 *
 *  @return int
 * 
 *  Pre-condition: iRegister != Null and ( i < 0 || i > 31)
 * 
 *  Post-condition: (ret < 0 || ret > 1) check that it return a bit value
 */
int getBit(int, iRegister *);

/** @brief assign a nibble value to a 32 bit register
 *  
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @param pos nibble position in the 32 bit register 
 *
 *  @param value value that is assign to the given nibble position 
 *
 *  @return void
 * 
 *  Pre-condition: iRegister != Null and (pos < 0 || pos > 7) and value < 0 || value > 15
 * 
 *  Post-condition: getNibble(pos,r) != value check that the nibble was assigned
 */
void assignNibble(int, int, iRegister *);

/** @brief assign a nibble value to a 32 bit register
 *  
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @param pos nibble position in the 32 bit register 
 *
 *  @return int
 * 
 *  Pre-condition: iRegister != Null and (pos < 0 || pos > 7) 
 * 
 *  Post-condition: (nibble < 0 || nibble > 15) check that faulty value was not extracetd
 */
int getNibble(int, iRegister *);

/** @brief turn a 32 bit register into an string
 *  
 *  @param r a iRegister data structure.
 *
 *  @return char
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: check that the string ended with \0
 */
char *reg2str(iRegister);

/** @brief shift right i steps
 *  
 *  @param r A pointer to a memory location of a iRegister data structure.
 *
 *  @param i steps to shift 
 *
 *  @return void 
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: 
 */
void shiftRight(int, iRegister *);

/** @brief shift left i steps
 *  
 *  @param r A pointer to a memory location of a iRegister data structure.
 *
 *  @param i steps to shift
 *
 *  @return void 
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: 
 */
void shiftLeft(int, iRegister *);


/** @brief Resets the i'th bit of the iRegister (to 0)
 *
 *  @param i Is i'th bit of the iRegister to be reset
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after reset(i, r) the i'th bit of iRegister is 0, all other 
 *  bits remain unchanged
 *  properties: 
 *  after resetBit(i, r),  getBit(i, r) = 0
 *  if getBit(i, r) == 0 then  
 *    getBit(j, r) returns the same value for all 
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 * 
 */
void resetBit(int, iRegister *);

#endif
