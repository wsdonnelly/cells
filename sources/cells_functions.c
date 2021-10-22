#include "cells.h"

char		change_char(void)
{
	char	c;

	fflush(0);
	printf("Enter a new char: ");
	c = getchar();
	fflush(0);
	return c;
}

void		get_size(term_size *t_size)
{
	struct winsize	w;

	ioctl(1 , TIOCGWINSZ, &w);
	t_size->rows = w.ws_row;
	t_size->cols = w.ws_col;
}

int			get_rule(int *rule_arr)
{
	int		val;
	int		num;
	int		i;

	num = rand() % 256;
	val = num;
	i = 0;
	while (val > 0)
	{
		rule_arr[i] = val % 2;
		val /= 2;
		i++;
	}
	return num;
}

void		print_line(int *arr, int cols, char c)
{
	for (int i = 0; i < cols; ++i)
	{
		if(arr[i] == 1)
			printf("%c", c);
		else
			printf("%c", ' ');
	}
	printf("\n");
}

void		use_rule(int *rule_arr, int *arr, int i, int num)
{
	if (rule_arr[num] == 1)
		arr[i + 1] = 1;
		else
		arr[i+1] = 0;
}
