#include "int_set_generator.h"

bool unique_num(int lower_bound, int *unique, int num)
{
	if (unique[num - lower_bound] == 1)
		return false;
	unique[num - lower_bound] = 1;
	return true;
}

void set_unique(int *unique, int arr_size)
{
	int i;

	i = 0;
	while (i < arr_size)
	{
		unique[i] = 0;
		i++;
	}
	return;
}

int random_num(int lower_bound, int upper_bound)
{
	int num;

	num = (rand() % (upper_bound + 1 - lower_bound)) + lower_bound;
	return num;
}

void random_int_set(int lower_bound, int upper_bound)
{
	int i;
	int num;
	int unique[upper_bound - lower_bound + 1];

	i = 0;
	set_unique(unique, upper_bound - lower_bound + 1);
	while (i < upper_bound + 1 - lower_bound)
	{
		if (i != 0)
			printf(" ");
		num = random_num(lower_bound, upper_bound);
		while (!unique_num(lower_bound, unique, num))
		{
			num = random_num(lower_bound, upper_bound);
		}
		printf("%d", num);
		i++;
	}
	// printf("\n");
	return;
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: ./random_int_set lower_bound upper_bound\n");
	}
	srand(time(NULL));
	random_int_set(atoi(argv[1]), atoi(argv[2]));
	return 0;
}