#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void InitiateStack(Stack*ps)
{
	ps-> top = NULL;
}
void push (StackEntry e, Stack*ps)
{
	StackNode*pn = (StackNode*)malloc(sizeof(StackNode));
	pn->entry = e;
    pn->next = ps->top;
    ps->top = pn; 	
}
void pop(StackEntry *pe , Stack*ps)
{
	StackNode*pn = ps->top;
	*pe = ps->top->entry;
	ps->top = ps->top->next;
	free(pn);
}
Stack_state StackEmpty (Stack* ps)
{
	if(ps->top == NULL)
	{
		return YES;
	}
	return NO;
}
Stack_state StackFull (Stack* ps)
{
	return NO;
}
void ClearStack (Stack* ps)
{
    StackNode* pn = ps->top;
    while(ps->top != NULL)
	{
		ps->top = ps->top->next;
		free(pn);
		pn = ps->top;
	}	
}
Stack_state TraverseStack (Stack* ps, void(*ptr_func)(StackEntry))
{
	if(ps-> top == NULL) /*The stack is empty.*/
	{
		return EMPTY;
	}
	else /*Not empty stack*/
	{
        StackNode*pn = ps->top;
		while(pn != NULL)
		{
			(*ptr_func)(pn->entry);
			pn = pn->next;
		}				
	}
}










