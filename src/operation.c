#include "push_swap.h"

void swap(Stack *stack)
{
	Num_list *tmp;

	tmp = stack->top->next;
	stack->top->next = stack->top->next->next;
	tmp->next = stack->top;
	stack->top = tmp;
	if (stack->bottom == stack->top)
		stack->bottom = stack->top->next;
	return;
}

//20->13->7
//13->20->7

void swap_a(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	if (operation->arr[SWAP_B] == true)
	{
		swap_a_and_b(stack_a, stack_b, operation);
		return;
	}
	swap(stack_a);
	operation->arr[SWAP_A] = false;
	printf("sa");
	if (VERBOSE)
		printf(" - swap %d, %d", stack_a->top->next->num, stack_a->top->num);
	printf("\n");
	return;
}

void swap_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	if (operation->arr[SWAP_A] == true)
	{
		swap_a_and_b(stack_a, stack_b, operation);
		return;
	}
	swap(stack_b);
	operation->arr[SWAP_B] = false;
	printf("sb");
	if (VERBOSE)
		printf(" - swap %d, %d", stack_b->top->next->num, stack_b->top->num);
	printf("\n");
	return;
}

void swap_a_and_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	printf("ss");
	swap(stack_a);
	swap(stack_b);
	if (VERBOSE)
	{
		printf(":\nsa");
		printf(" - swap %d, %d\n", stack_a->top->next->num, stack_a->top->num);
		printf("sb");
		printf(" - swap %d, %d", stack_b->top->next->num, stack_b->top->num);
	}
	printf("\n");

	operation->arr[SWAP_A] = false;
	operation->arr[SWAP_B] = false;
	return;
}

void push(Stack *to, Stack *from)
{
	Num_list *tmp_top;
	Num_list *tmp_next;

	tmp_top = from->top;
	from->top = from->top->next;
	tmp_next = to->top;
	to->top = tmp_top;
	to->top->next = tmp_next;
	return;
}

void push_a(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	push(stack_a, stack_b);
	operation->arr[PUSH_A] = false;
	printf("pa");
	if (VERBOSE)
		printf(" - %d to stack_a", stack_a->top->num);
	printf("\n");
	return;
}

// 20->13->7
// 10->12->45

// 10->20->13->7
// 12->45

void push_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	push(stack_b, stack_a);
	operation->arr[PUSH_B] = false;
	if (stack_b->bottom == NULL)
	{
		stack_b->bottom = stack_b->top;
	}
	printf("pb");
	if (VERBOSE)
		printf(" - %d to stack_b", stack_b->top->num);
	printf("\n");
	return;
}

void rotate(Stack *stack)
{
	// The first element becomes the last one.
	Num_list *tmp_top;

	tmp_top = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = tmp_top;
	stack->bottom = stack->bottom->next;
	stack->bottom->next = NULL;
	return;
}

void rotate_a(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	if (operation->arr[ROTATE_B] == true)
	{
		rotate_a_and_b(stack_a, stack_b, operation);
		return;
	}
	rotate(stack_a);
	operation->arr[ROTATE_A] = false;
	printf("ra");
	if (VERBOSE)
		printf(" - %d to the bottom of stack_a", stack_a->bottom->num);
	printf("\n");
	return;
}

void rotate_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	if (operation->arr[ROTATE_A] == true)
	{
		rotate_a_and_b(stack_a, stack_b, operation);
		return;
	}
	rotate(stack_b);
	operation->arr[ROTATE_B] = false;
	printf("rb");
	if (VERBOSE)
		printf(" - %d to the bottom of stack_b", stack_b->bottom->num);
	printf("\n");
	return;
}

void rotate_a_and_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	printf("rr");
	rotate(stack_a);
	rotate(stack_b);
	operation->arr[ROTATE_A] = false;
	operation->arr[ROTATE_B] = false;
	if (VERBOSE)
	{
		printf(":\nra - %d to the bottom of stack_a\n", stack_a->bottom->num);
		printf("rb - %d to the bottom of stack_b", stack_b->bottom->num);
	}
	printf("\n");
	return;
}

void reverse_rotate(Stack *stack)
{
	// The last element becomes the first one.
	Num_list *tmp_top;
	Num_list *tmp_bottom;

	tmp_top = stack->top;
	tmp_bottom = stack->bottom;
	while (stack->top->next->next != NULL)
	{
		stack->top = stack->top->next;
	}
	stack->bottom = stack->top;
	stack->bottom->next = NULL;
	stack->top = tmp_bottom;
	stack->top->next = tmp_top;
	return;
}

void reverse_rotate_a(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	if (operation->arr[REVERSE_ROTATE_B] == true)
	{
		reverse_rotate_a_and_b(stack_a, stack_b, operation);
		return;
	}
	reverse_rotate(stack_a);
	operation->arr[REVERSE_ROTATE_A] = false;
	printf("rra");
	if (VERBOSE)
		printf(" - %d to the top of stack_a", stack_a->top->num);
	printf("\n");
	return;
}

void reverse_rotate_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	if (operation->arr[REVERSE_ROTATE_A] == true)
	{
		reverse_rotate_a_and_b(stack_a, stack_b, operation);
		return;
	}
	reverse_rotate(stack_b);
	operation->arr[REVERSE_ROTATE_B] = false;
	printf("rrb");
	if (VERBOSE)
		printf(" - %d to the top of stack_b", stack_b->top->num);
	printf("\n");

	return;
}

void reverse_rotate_a_and_b(Stack *stack_a, Stack *stack_b, Operation *operation)
{
	printf("rrr");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	operation->arr[REVERSE_ROTATE_A] = false;
	operation->arr[REVERSE_ROTATE_B] = false;
	if (VERBOSE)
	{
		printf(":\nrra - %d to the top of stack_a\n", stack_a->top->num);
		printf("rrb - %d to the top of stack_b", stack_b->top->num);
	}
	printf("\n");
	return;
}
