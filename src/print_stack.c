#include "push_swap.h"

void print_stack(char stack_name, Num_list *top)
{
	Num_list *tmp_top;

	tmp_top = top;
	printf("stack_%c top->	", stack_name);
	while (tmp_top != NULL)
	{
		printf("%d ", tmp_top->num);
		tmp_top = tmp_top->next;
	}
	printf("|bottom\n");
	return;
}
