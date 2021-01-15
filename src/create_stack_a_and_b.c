#include "push_swap.h"

void show_usage()
{
	ft_printf("Usage: ./push_swap 3 2 1 0\n");
	return;
}

void free_num_list(Num_list **top)
{
	Num_list *tmp_top;

	while (*top != NULL)
	{
		tmp_top = *top;
		*top = (*top)->next;
		free(tmp_top);
	}
	return;
}

void memory_allocation(Num_list **top, Num_list **tmp_top)
{
	*top = (Num_list *)malloc(sizeof(Num_list));
	if (*top == NULL)
	{
		free_num_list(tmp_top);
		printf("Error: allocation failed.\n");
		exit(0);
	}
	return;
}

void check_value(char *s, Num_list **top)
{
	if (ft_isdigit(s[0]))
		return;
	ft_printf("Error: \"%s\" is not a number\n", s);
	show_usage();
	free_num_list(top);
	exit(0);
}

bool take_bottom_number(int argc, char **argv, int *number, Num_list **top)
{
	static int i;
	static int j;

	if (j < 0)
		return false;
	if (i == 0)
	{
		i = argc - 1;
		j = ft_strlen(argv[i]) - 1;
	}
	while (ft_isdigit(argv[i][j]) && j >= 0)
		j--;
	check_value(&argv[i][j + 1], top);
	*number = ft_atoi(&argv[i][j + 1]);
	if (j > 0)
	{
		j--;
	}
	else if (i > 1)
	{
		i--;
		j = ft_strlen(argv[i]) - 1;
	}
	return true;
}

void copy_arguments_to_stack_a(int argc, char **argv, Num_list **top, Num_list **bottom)
{
	int number;
	Num_list *tmp_top;

	tmp_top = NULL;
	while (take_bottom_number(argc, argv, &number, top))
	{
		//check for repetitions

		memory_allocation(top, &tmp_top);
		(*top)->num = number;
		(*top)->next = tmp_top;
		tmp_top = *top;
		if ((*top)->next == NULL)
			*bottom = *top;
	}
	return;
}

void set_default_stack(Stack *stack, char name)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->min = NULL;
	stack->size = 0;
	stack->name = name;
	return;
}

void create_stack_a_and_b(int argc, char **argv, Stack *stack_a, Stack *stack_b)
{
	if (argc > 1)
	{
		set_default_stack(stack_a, 'a');
		set_default_stack(stack_b, 'b');
		copy_arguments_to_stack_a(argc, argv, &stack_a->top, &stack_a->bottom);
		stack_a->size = argc - 1;
		return;
	}
	ft_printf("Error: not enough arguments.\n");
	show_usage();
	exit(0);
	return;
}