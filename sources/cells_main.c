#include "cells.h"

int	main(void)
{
	char		command;
	char		c = 'O';
	int			rule_arr[8] = {0};
	int			flag;
	term_size	t_size;

	srand(time(0));

	do {
		fflush(0);
		flag = 0;
		get_size(&t_size);
		get_rule(rule_arr);
		generate(rule_arr, &t_size, c);
		printf("Run again? (y/n) or change char? (c): ");
		command = getchar();
		if (command == 'c' || command == 'C')
		{
			c = change_char();
			flag = 1;
		}
	} while (command == 'y' || command == 'Y' || flag == 1);

	return (0);
}
