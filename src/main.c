#include "push_swap.h"

/*
1.	check input-positive int, negative int, no repeats. arr size of strlen.
		to check repetitions-check if no val in array is set.
2.	write input to a list

*/

// bool sorted(Num_list *top)
// {
// 	Num_list *tmp_top;

// 	tmp_top = top;
// 	while (tmp_top->next != NULL)
// 	{
// 		if (tmp_top->num > tmp_top->next->num)
// 			return false;
// 		tmp_top = tmp_top->next;
// 	}
// 	return true;
// }

// void set_swap_operation(char stack_name, Operation *operation)
// {
// 	if (stack_name == 'a')
// 		operation->arr[SWAP_A] = true;
// 	else
// 		operation->arr[SWAP_B] = true;
// 	return;
// }

// void set_rotate_operation(char stack_name, Operation *operation)
// {
// 	if (stack_name == 'a')
// 		operation->arr[ROTATE_A] = true;
// 	else
// 		operation->arr[ROTATE_B] = true;
// 	return;
// }

// void set_reverse_rotate_operation(char stack_name, Operation *operation)
// {
// 	if (stack_name == 'a')
// 		operation->arr[REVERSE_ROTATE_A] = true;
// 	else
// 		operation->arr[REVERSE_ROTATE_B] = true;
// 	return;
// }

// void place_min_num_on_top(char stack_name, Stack *stack, Operation *operation)
// {
// 	if (stack->top->num < stack->top->next->num &&
// 			stack->top->num < stack->bottom->num)
// 		return;
// 	else if (stack->top->next->num < stack->top->num &&
// 					 stack->top->next->num < stack->bottom->num)
// 	{
// 		set_swap_operation(stack_name, operation);
// 	}
// 	else
// 	{
// 		set_reverse_rotate_operation(stack_name, operation);
// 	}
// 	return;
// }

// void place_max_num_on_top(char stack_name, Stack *stack, Operation *operation)
// {
// 	if (stack->top->num > stack->top->next->num &&
// 			stack->top->num > stack->bottom->num)
// 		return;
// 	else if (stack->top->next->num > stack->top->num &&
// 					 stack->top->next->num > stack->bottom->num)
// 	{
// 		set_swap_operation(stack_name, operation);
// 	}
// 	else
// 	{
// 		set_reverse_rotate_operation(stack_name, operation);
// 	}
// 	return;
// }

// void place_max_num_on_bottom(char stack_name, Stack *stack, Operation *operation)
// {
// 	if (stack->bottom->num > stack->top->num)
// 		return;
// 	else
// 		set_rotate_operation(stack_name, operation);
// 	return;
// }

// bool execute_operation(Stack *stack_a, Stack *stack_b, Operation *operation)
// {
// 	int i;
// 	bool ret;

// 	i = 0;
// 	ret = false;
// 	while (i < NUM_OPERATIONS)
// 	{
// 		if (operation->arr[i] == true)
// 		{
// 			operation->function[i](stack_a, stack_b, operation);
// 			ret = true;
// 		}
// 		i++;
// 	}
// 	return ret;
// }

// void sort_three_nums(char stack_name, Stack *stack, Operation *operation)
// {
// 	while (stack->top->next->num < stack->top->num ||
// 				 stack->top->next->num > stack->bottom->num)
// 	{
// 		if (stack->top->num > stack->top->next->num && stack->top->num > stack->bottom->num)
// 			stack_name == 'a' ? rotate_a(stack, stack, operation) : rotate_b(stack, stack, operation);
// 		if (stack->bottom->num > stack->top->num &&
// 				stack->bottom->num > stack->top->next->num &&
// 				stack->top->next->num < stack->top->num &&
// 				stack->top->next->num < stack->bottom->num)
// 			stack_name == 'a' ? swap_a(stack, stack, operation) : swap_b(stack, stack, operation);
// 		if (stack->top->next->num > stack->top->num &&
// 				stack->top->next->num > stack->bottom->num &&
// 				stack->top->num < stack->top->next->num &&
// 				stack->top->num < stack->bottom->num)
// 			stack_name == 'a' ? swap_a(stack, stack, operation) : swap_b(stack, stack, operation);
// 		if (stack->top->next->num > stack->top->num &&
// 				stack->top->next->num > stack->bottom->num &&
// 				stack->bottom->num < stack->top->num &&
// 				stack->bottom->num < stack->top->next->num)
// 			stack_name == 'a' ? reverse_rotate_a(stack, stack, operation) : reverse_rotate_b(stack, stack, operation);
// 	}
// 	stack->min = stack->top;
// 	return;
// }

// void push_max_num_to_b(Stack *stack_a, Stack *stack_b, Operation *operation)
// {
// 	place_max_num_on_top('a', stack_a, operation);
// 	execute_operation(stack_a, stack_b, operation);
// 	push_b(stack_a, stack_b, operation);
// 	return;
// }

/*
find index of insertion
	if size / 2 >= index
		while index != 0
			rb
			index --
	else if size / 2 < index
		while index != size
			rrb
			index ++

*/

void move_stack_for_insertion(int index, Stack *stack_b, Operation *operation)
{
	if (stack_b->size / 2 >= index)
	{
		while (index != 0)
		{
			rotate_b(stack_b, stack_b, operation);
			index--;
		}
	}
	else if (stack_b->size / 2 < index)
	{
		while (index != stack_b->size)
		{
			reverse_rotate_b(stack_b, stack_b, operation);
			index++;
		}
	}
	return;
}

void find_insertion_place(int num_to_insert, Stack *stack_b, Operation *operation)
{
	Num_list *tmp;
	int index;

	tmp = stack_b->top;
	index = 0;
	if (stack_b->min == tmp && num_to_insert < tmp->num)
		return;
	if (num_to_insert < stack_b->top->num && num_to_insert > stack_b->bottom->num)
		return;
	while (tmp->next != NULL)
	{
		index++;
		if ((num_to_insert > tmp->num && num_to_insert < tmp->next->num) ||
				(stack_b->min == tmp->next && (num_to_insert < tmp->next->num ||
																			 (num_to_insert > tmp->num && num_to_insert > tmp->next->num))))
		{
			move_stack_for_insertion(index, stack_b, operation);
			break;
		}
		tmp = tmp->next;
	}
	return;
}

int num_moves_for_insertion(int num_to_insert, Stack *stack_b)
{
	Num_list *tmp;
	int index;

	tmp = stack_b->top;
	index = 0;
	if (stack_b->min == tmp && (num_to_insert < tmp->num || num_to_insert > stack_b->bottom->num))
		return index;
	if (num_to_insert < stack_b->top->num && num_to_insert > stack_b->bottom->num)
		return index;
	while (tmp->next != NULL)
	{
		index++;
		if ((num_to_insert > tmp->num && num_to_insert < tmp->next->num) ||
				(stack_b->min == tmp->next && (num_to_insert < tmp->next->num ||
																			 (num_to_insert > tmp->num && num_to_insert > tmp->next->num))))
		{
			if (stack_b->size / 2 >= index)
			{
				return index;
			}
			else if (stack_b->size / 2 < index)
			{
				return stack_b->size - index;
			}
		}
		tmp = tmp->next;
	}
	return index;
}

bool is_better_num(Stack *stack_a, Stack *stack_b, Operation *operation, int run)
{
	int top;
	int next;
	int bottom;

	top = num_moves_for_insertion(stack_a->top->num, stack_b);
	next = num_moves_for_insertion(stack_a->top->next->num, stack_b);
	bottom = num_moves_for_insertion(stack_a->bottom->num, stack_b);
	if ((top <= next && top <= bottom) || (run == 2 && top <= next))
	{
		return false;
	}
	else if ((next <= top && next <= bottom) || (run == 2 && next <= top))
	{
		swap_a(stack_a, stack_a, operation);
		return true;
	}
	else if (run == 1 && bottom <= top && bottom <= next)
	{
		reverse_rotate_a(stack_a, stack_a, operation);
		return true;
	}
	return false;
}

void find_num_to_push_to_b(Stack *stack_a, Stack *stack_b, Operation *operation, int run)
{
	if (run == 1)
	{
		while (is_better_num(stack_a, stack_b, operation, run))
		{
			;
		}
	}
	else if (run == 2)
	{
		while (is_better_num(stack_a, stack_b, operation, run))
		{
			;
		}
	}
	return;
}

/*
create first run with min on top
	size = n % 2 == 0 ? n/2 : n/2 + 1
	while stack_b_size < size
		find num closest to b_top
			while is_better_num_for_b_top
				move the num to a_top
		insert in place
	while (B-top is not min)
		if (min position < size / 2)
			rb
		else
			rrb
	while (B-top != NULL)
		pa
*/

void create_first_run(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	int size;

	size = (stack_a->size % 2 == 0) ? (stack_a->size / 2) : (stack_a->size / 2 + 1);
	while (stack_b->size <= size)
	{
		// place_max_num_on_top('a', stack_a, operation);
		// execute_operation(stack_a, stack_b, operation);
		find_num_to_push_to_b(stack_a, stack_b, operation, 1);
		find_insertion_place(stack_a->top->num, stack_b, operation);
		if (stack_b->min->num > stack_a->top->num)
			stack_b->min = stack_a->top;
		push_b(stack_a, stack_b, operation);
	}
	find_insertion_place(stack_b->min->num - 1, stack_b, operation);
	while (stack_b->top != NULL)
	{
		push_a(stack_a, stack_b, operation);
		rotate_a(stack_a, stack_b, operation);
	}
	return;
}

void create_second_run(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	int size;

	size = (stack_a->size % 2 == 0) ? (stack_a->size / 2) : (stack_a->size / 2 + 1);
	if (VERBOSE)
		printf("creating second run:\n");
	while (stack_b->size <= size)
	{
		// if (stack_a->top->num < stack_a->top->next->num)
		// 	swap_a(stack_a, stack_b, operation);
		find_num_to_push_to_b(stack_a, stack_b, operation, 2);
		find_insertion_place(stack_a->top->num, stack_b, operation);
		if (stack_b->min->num > stack_a->top->num)
			stack_b->min = stack_a->top;
		push_b(stack_a, stack_b, operation);
	}
	find_insertion_place(stack_b->min->num - 1, stack_b, operation);
	return;
}

// int calculate_closest_num(int a, int b_next, int b_bottom)
// {
// 	int diff_next;
// 	int diff_bottom;

// 	diff_next = b_next - a;
// 	diff_bottom = a - b_bottom;
// 	if (diff_bottom > 0 && (diff_next < 0 || diff_bottom < diff_next))
// 		return diff_bottom;
// 	if (diff_next > 0 && (diff_bottom < 0 || diff_next < diff_bottom))
// 		return diff_next;
// 	return 0;
// }

/*
a_top
a_next
a_bottom

num < b_next
num > b_bottom

find A-closest to B-next or B-bottom
*/

// bool num_to_push_to_run(Stack *stack_a, Stack *stack_b, Operation *operation)
// {
// 	int a_top;
// 	int a_next;
// 	int a_bottom;

// 	if (stack_a->top->next->next->next == NULL)
// 		return false;
// 	a_top = calculate_closest_num(stack_a->top->num, stack_b->top->next->num, stack_b->bottom->num);
// 	a_next = calculate_closest_num(stack_a->top->next->num, stack_b->top->next->num, stack_b->bottom->num);
// 	a_bottom = calculate_closest_num(stack_a->bottom->num, stack_b->top->next->num, stack_b->bottom->num);
// 	if (a_top != 0 && (a_top <= a_next || a_next == 0) && (a_top <= a_bottom || a_bottom == 0))
// 	{
// 		return true;
// 	}
// 	if (a_next != 0 && (a_next <= a_top || a_top == 0) && (a_next <= a_bottom || a_bottom == 0))
// 	{
// 		operation->arr[SWAP_A] = true;
// 		return true;
// 	}
// 	if (a_bottom != 0 && (a_bottom <= a_top || a_top == 0) && (a_bottom <= a_next || a_next == 0))
// 	{
// 		operation->arr[REVERSE_ROTATE_A] = true;
// 		return true;
// 	}
// 	return false;
// }

// void make_next_run(Stack *stack_a, Stack *stack_b, Operation *operation)
// {
// 	static int i = 1;
// 	while (num_to_push_to_run(stack_a, stack_b, operation))
// 	{
// 		printf("composing run no %d\n", i);
// 		execute_operation(stack_a, stack_b, operation);
// 		push_b(stack_a, stack_b, operation);
// 		if (stack_b->top->num > stack_b->bottom->num)
// 			operation->arr[ROTATE_B] = true;
// 		else if (stack_b->top->num > stack_b->top->next->num)
// 			operation->arr[SWAP_B] = true;
// 	}
// 	execute_operation(stack_a, stack_b, operation);
// 	i++;
// 	return;
// }

// void create_runs_on_b(Stack *stack_a, Stack *stack_b, Operation *operation)
// {
// 	make_next_run(stack_a, stack_b, operation);
// 	while (stack_a->top->next->next->next != NULL)
// 	{
// 		push_max_num_to_b(stack_a, stack_b, operation);
// 		push_max_num_to_b(stack_a, stack_b, operation);
// 		if (stack_b->top->num > stack_b->top->next->num)
// 			operation->arr[SWAP_B] = true;
// 		make_next_run(stack_a, stack_b, operation);
// 	}
// 	return;
// }

void merge_a_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	if (VERBOSE)
		printf("merging:\n");
	while (stack_b->top->num > stack_a->top->num &&
				 stack_b->top->num > stack_a->top->next->num &&
				 stack_b->top->num > stack_a->top->next->next->num)
	{
		push_a(stack_a, stack_b, operation);
		rotate_a(stack_a, stack_b, operation);
	}
	while (stack_b->top != NULL)
	{
		if (stack_a->bottom->num > stack_a->top->num &&
				stack_a->bottom->num < stack_b->top->num)
		{
			push_a(stack_a, stack_b, operation);
			rotate_a(stack_a, stack_b, operation);
		}
		else if ((stack_a->bottom->num < stack_a->top->num &&
							stack_a->bottom->num > stack_b->top->num) ||
						 stack_a->top->num < stack_b->top->num)
		{
			rotate_a(stack_a, stack_b, operation);
		}
		else
		{
			push_a(stack_a, stack_b, operation);
			rotate_a(stack_a, stack_b, operation);
		}
	}
	while (stack_a->top->num > stack_a->bottom->num)
		rotate_a(stack_a, stack_b, operation);
	return;
}

void set_initial_stack_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	push_b(stack_a, stack_b, operation);
	stack_b->min = stack_b->top;
	return;
}

/*
	set stack_b
		push_b
		min->num = stack_b->top
	create first run
	set stack_b
	create second run
	merge
*/

void sort(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	set_initial_stack_b(stack_a, stack_b, operation);
	create_first_run(stack_a, stack_b, operation);
	set_initial_stack_b(stack_a, stack_b, operation);
	create_second_run(stack_a, stack_b, operation);
	merge_a_b(stack_a, stack_b, operation);
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
	sort(&stack_a, &stack_b, &operation);
	printf("%d\n", operation.num);
	free_num_list(&stack_a.top);
	return 0;
}
