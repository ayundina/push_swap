#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdbool.h>
#include <stdio.h> //delete

#define SWAP_A 0
#define SWAP_B 1
#define SWAP_A_B 2
#define PUSH_A 3
#define PUSH_B 4
#define ROTATE_A 5
#define ROTATE_B 6
#define ROTATE_A_B 7
#define REVERSE_ROTATE_A 8
#define REVERSE_ROTATE_B 9
#define REVERSE_ROTATE_A_B 10

#define VERBOSE 1

#define NUM_OPERATIONS 11

typedef struct s_num_list
{
	int num;
	struct s_num_list *next;
} Num_list;

typedef struct s_stack
{
	Num_list *top;
	Num_list *bottom;
	Num_list *min;
	int size;
	char name;
} Stack;

typedef struct s_operation Operation;
typedef void (*Fptr)(Stack *stack_a, Stack *stack_b, Operation *operation);

struct s_operation
{
	int num;
	bool arr[NUM_OPERATIONS];
	Fptr function[NUM_OPERATIONS];
};

void create_stack_a_and_b(int argc, char **argv, Stack *stack_a, Stack *stack_b);
void print_stack(char stack_name, Num_list *top);
void free_num_list(Num_list **top);

void swap_a(Stack *stack_a, Stack *stack_b, Operation *operation);
void swap_b(Stack *stack_a, Stack *stack_b, Operation *operation);
void swap_a_and_b(Stack *stack_a, Stack *stack_b, Operation *operation);
void push_a(Stack *stack_a, Stack *stack_b, Operation *operation);
void push_b(Stack *stack_a, Stack *stack_b, Operation *operation);
void rotate_a(Stack *stack_a, Stack *stack_b, Operation *operation);
void rotate_b(Stack *stack_a, Stack *stack_b, Operation *operation);
void rotate_a_and_b(Stack *stack_a, Stack *stack_b, Operation *operation);
void reverse_rotate_a(Stack *stack_a, Stack *stack_b, Operation *operation);
void reverse_rotate_b(Stack *stack_a, Stack *stack_b, Operation *operation);
void reverse_rotate_a_and_b(Stack *stack_a, Stack *stack_b, Operation *operation);

#endif