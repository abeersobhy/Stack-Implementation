#ifndef _STACK_H_
#define _STACK_H_
#include "stack_config.h"
/**************************************************************************************/
#define MAX_STACK MAX_STACK_SIZE /*Defined in stack_confg.h file.*/
#define StackEntry ENTRY_TYPE /*Defined in stack_confg.h file.*/
/*************************************************************************************/
typedef int                    int32_t;
typedef unsigned int           uint32_t;
typedef char                   int8_t;
typedef unsigned char          uint8_t;
typedef short int              int16_t;
typedef unsigned short int     uint16_t;
typedef float                  f32_t;
typedef double                 f64_t;
/************************************************************************************/
/*Enum for state of the stack.*/
typedef enum
{
   FULL,
   NOT_EMPTY,
   EMPTY,    
}Stack_state;
/************************************************************************************/
/*Stack Declaration.*/  
typedef struct stack
{
	int top;
	StackEntry entry[MAX_STACK];
}Stack;
/************************************************************************************/
/*Function to add new element to an implemented stack.*/
void                push                  (StackEntry , Stack*);
/*Function to get an element from an implemented stack then clear its position*/
void                pop                   (StackEntry* , Stack*);
/*Function to check if the stack is empty or not.*/
Stack_state         StackEmpty            (Stack*);
/*Function to check if the stack is full or not.*/
Stack_state         StackFull             (Stack*);
/*Function to initialize new created stack.*/
void                CreateStack           (Stack*);
/*Function to return a copy from the top element of an implemented stack.*/
void                StackTop              (StackEntry* , Stack*);
/*Function to return the size of the stack.*/
int32_t             StackSize             (Stack*);
/*Funstion to clear an implemented stack.*/
void                ClearStack            (Stack*);
/*Function to traverse the all the elements of the stack.*/
Stack_state         TraverseStack         (Stack* , void(*ptr_fun)(StackEntry));
/**************************************************************************************/
#endif