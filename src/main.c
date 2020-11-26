#include "push_swap.h"

/*
1.	check input-positive int, negative int, no repeats. arr size of strlen.
		to check repetitions-check if no val in array is set.
2.	write input to a list

https://github.com/semenpindak/push_swap

Pseudocode

#define MIN 

for (stack_a == three numbers)
{
	sort in place stack_a
}

for (stack_a > 3 numbers)
{
	if (stack_a min is on top)
	{
		pb
	}
	else if (stack_a min is second from top)
	{
		sa
	}
	else if (stack_a min is on bottom)
	{
		rra
	}
}

*/

bool sorted(Num_list *top)
{
	// static int i = 0;
	// i++;
	// if (i > 1)
	// 	return true; // delete later
	Num_list *tmp_top;

	tmp_top = top;
	while (tmp_top->next != NULL)
	{
		if (tmp_top->num > tmp_top->next->num)
			return false;
		tmp_top = tmp_top->next;
	}
	return true;
}

void sort_in_ascending(Stack *stack_a, Operation *operation)
{
	if (stack_a->min == stack_a->top->next)
		operation->arr[SWAP_A] = true;
	else if (stack_a->min == stack_a->bottom)
		operation->arr[REVERSE_ROTATE_A] = true;
	return;
}

void sort_in_descending(Stack *stack_b, Operation *operation)
{
	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return;
	else if (stack_b->min == stack_b->top)
		operation->arr[ROTATE_B] = true;
	else if (stack_b->max == stack_b->top->next)
		operation->arr[SWAP_B] = true;
	else if (stack_b->max == stack_b->bottom)
		operation->arr[REVERSE_ROTATE_B] = true;
	return;
}

void define_operation(char stack_name, Stack *stack, Operation *operation)
{
	if (stack_name == 'a')
		sort_in_ascending(stack, operation);
	else if (stack_name == 'b')
		sort_in_descending(stack, operation);
	return;
}

bool execute_operation(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	int i;
	bool ret;

	i = 0;
	ret = false;
	while (i < NUM_OPERATIONS)
	{
		if (operation->arr[i] == true)
		{
			operation->function[i](stack_a, stack_b, operation);
			ret = true;
		}
		i++;
	}
	return ret;
}

void sort_three_nums(Stack *stack_a, Operation *operation)
{
	while (stack_a->min != stack_a->top || stack_a->max != stack_a->bottom)
	{
		if (stack_a->max == stack_a->top)
			rotate_a(stack_a, stack_a, operation);
		if (stack_a->max == stack_a->bottom && stack_a->min == stack_a->top->next)
			swap_a(stack_a, stack_a, operation);
		if (stack_a->max == stack_a->top->next && stack_a->min == stack_a->top)
			swap_a(stack_a, stack_a, operation);
		if (stack_a->max == stack_a->top->next && stack_a->min == stack_a->bottom)
			reverse_rotate_a(stack_a, stack_a, operation);
	}
	return;
}

/*
while (more then 3 nums on stack_a)
{
	find min on stack_a(first two and last number)
	find max on stack_b(first two and last number)
	if (stack_a->min > stack_b->max)
	{
		pb stack_a->min
	}
	if (stack_a->min < stack_b->max)
	{
		stack_a->min to top
		pa stack_b->max
	}
}
*/

bool three_nums_on_stack(Stack *stack)
{
	if (stack->top && stack->top->next && stack->top->next->next)
		return true;
	return false;
}

void sort(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	bool changing_top;

	changing_top = true;
	while (stack_a->top->next->next->next != NULL)
	{
		while (changing_top)
		{
			find_min_num(stack_a);
			find_min_num(stack_b);
			find_max_num(stack_b);
			define_operation('a', stack_a, operation);
			define_operation('b', stack_b, operation);
			changing_top = execute_operation(stack_a, stack_b, operation);
		}
		if (!three_nums_on_stack(stack_b) || !stack_b->max || (stack_b->max && stack_a->min->num > stack_b->max->num))
			push_b(stack_a, stack_b, operation);
		else if (three_nums_on_stack(stack_b) && stack_b->max && stack_a->min->num < stack_b->max->num)
		{
			push_a(stack_a, stack_b, operation);
		}
		stack_b->max = NULL;
		changing_top = true;
	}
	find_min_num(stack_a);
	find_max_num(stack_a);
	sort_three_nums(stack_a, operation);
	while (stack_b->top != NULL)
	{
		find_min_num(stack_a);
		find_max_num(stack_b);
		define_operation('a', stack_a, operation);
		define_operation('b', stack_b, operation);
		execute_operation(stack_a, stack_b, operation);
		push_a(stack_a, stack_b, operation);
	}
	return;
}

void set_operation_functions(Operation *operation)
{
	operation->num = 0;
	operation->function[SWAP_A] = swap_a;
	operation->function[SWAP_B] = swap_b;
	operation->function[SWAP_A_B] = swap_a_and_b;
	operation->function[PUSH_A] = push_a;
	operation->function[PUSH_B] = push_b;
	operation->function[ROTATE_A] = rotate_a;
	operation->function[ROTATE_B] = rotate_b;
	operation->function[ROTATE_A_B] = rotate_a_and_b;
	operation->function[REVERSE_ROTATE_A] = reverse_rotate_a;
	operation->function[REVERSE_ROTATE_B] = reverse_rotate_b;
	operation->function[REVERSE_ROTATE_A_B] = reverse_rotate_a_and_b;
	return;
}

int main(int argc, char **argv)
{
	Stack stack_a;
	Stack stack_b;
	Operation operation;

	create_stack_a_and_b(argc, argv, &stack_a, &stack_b);
	if (VERBOSE)
	{
		print_stack('a', stack_a.top);
		print_stack('b', stack_b.top);
	}
	set_operation_functions(&operation);
	int i = 0;
	while (!sorted(stack_a.top))
	{
		sort(&stack_a, &stack_b, &operation);
		i++;
	}
	printf("%d\n", i);
	printf("%d\n", operation.num);
	return 0;
}

/*

stack_a top->			20 17 11 19 15 18 4 10 12 14 8 9 5 16 |bottom
stack_b top->			13 7 6 3 2 1 |bottom

compare 20 17 16 on stack_a. Min = 16 max = 20
compare 13 7 1 on stack_b. Min = 1 max = 13
rra - 16 to top
compare 16 20 5 on stack_a. Min = 5 max = 20
rra - 5 to top
compare 5 16 9 on stack_a. Min = 5 max = 16
pa - 13 to stack_a
sa - 13 5
stack_a top->			5 13 16 20 17 11 19 15 18 4 10 12 14 8 9 |bottom
stack_b top->			7 6 3 2 1 |bottom

while (more then 3 nums on stack_a)
{
	find min on stack_a(first two and last number)
	find max on stack_b(first two and last number)
	if (stack_a->min > stack_b->max)
	{
		pb stack_a->min
	}
	if (stack_a->min < stack_b->max)
	{
		stack_a->min to top
		pa stack_b->max
	}
}

*/
