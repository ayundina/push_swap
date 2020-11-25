#include "push_swap.h"

void find_max_num(Stack *stack)
{
	int first;
	int second;
	int last;

	if (stack->top == NULL) // empty stack
		return;
	else if (stack->top->next == NULL) // one num
	{
		if (VERBOSE)
			printf("compare %d. ", stack->top->num);
		stack->max = stack->top;
	}
	else if (stack->top->next->next == NULL) // two nums
	{
		first = stack->top->num;
		second = stack->top->next->num;
		if (VERBOSE)
			printf("compare %d, %d. ", first, second);
		if (first > second)
		{
			stack->max = stack->top;
		}
		else
		{
			stack->max = stack->top->next;
		}
	}
	else // more then two nums
	{
		first = stack->top->num;
		second = stack->top->next->num;
		last = stack->bottom->num;
		if (VERBOSE)
			printf("compare %d, %d, %d. ", first, second, last);
		if (first > second && first > last)
		{
			stack->max = stack->top;
		}
		else if (second > first && second > last)
		{
			stack->max = stack->top->next;
		}
		else
		{
			stack->max = stack->bottom;
		}
	}
	if (VERBOSE)
		printf("Max_num = %d\n", stack->max->num);
	return;
}

void find_min_num(Stack *stack)
{
	int first;
	int second;
	int last;

	if (stack->top == NULL) // empty stack
		return;
	else if (stack->top->next == NULL) // one num
	{
		if (VERBOSE)
			printf("compare %d. ", stack->top->num);
		stack->min = stack->top;
	}
	else if (stack->top->next->next == NULL) // two nums
	{
		first = stack->top->num;
		second = stack->top->next->num;
		if (VERBOSE)
			printf("compare %d, %d. ", first, second);
		if (first < second)
		{
			stack->min = stack->top;
		}
		else
		{
			stack->min = stack->top->next;
		}
	}
	else // more then two nums
	{
		first = stack->top->num;
		second = stack->top->next->num;
		last = stack->bottom->num;
		if (VERBOSE)
			printf("compare %d, %d, %d. ", first, second, last);
		if (first < second && first < last)
		{
			stack->min = stack->top;
		}
		else if (second < first && second < last)
		{
			stack->min = stack->top->next;
		}
		else
		{
			stack->min = stack->bottom;
		}
	}
	if (VERBOSE)
		printf("Min_num = %d\n", stack->min->num);
	return;
}