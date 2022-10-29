#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void CreateStack (Stack* ps)
{
	ps->top = 0;
}
void push (StackEntry e, Stack* ps)
{
	ps->entry[ps->top] = e;
    ps->top++;	
}
void pop (StackEntry* pe , Stack* ps)
{
	ps->top--;
	*pe = ps->entry[ps->top];
}
Stack_state StackEmpty (Stack* ps)
{
	if(ps->top <= 0)
	{
		return EMPTY;
	}
	else
	{
		return NOT_EMPTY;
	}
}
Stack_state StackFull (Stack* ps)
{
    if(ps->top == MAX_STACK)
	{
		return FULL;
	} 
	else if((ps->top > 0) && (ps->top == MAX_STACK))
	{
		return NOT_EMPTY;
	}
    else if(ps->top == 0)
	{
		return EMPTY;
	}
}
void StackTop (StackEntry* pe , Stack* ps)
{
	*pe = ps->entry[ps->top-1];
}
int32_t StackSize (Stack* ps)
{
    return  ps->top;	
}
void ClearStack (Stack* ps)
{
	ps->top = 0;
}
Stack_state TraverseStack (Stack* ps , void(*ptr_fun)(StackEntry))
{
	if(ps->top <= 0)
	{
		return EMPTY;
	}
	else
	{
        for(int32_t i = (ps->top-1) ; i >= 0 ; i--)
		{
			(*ptr_fun)(ps->entry[i]);
		}
        return NOT_EMPTY;		
	}		
}






