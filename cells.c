#include "cells.h"

int main(void)
{
	char		command;
	char		c = 'X';
	int			rule_arr[8] = {0};
	int			flag;
	term_size	t_size;

	srand(time(0));

	do {
		flag = 0;
		get_size(&t_size);
		get_rule(rule_arr);
		generate(rule_arr, &t_size, c);
		printf("Run again? (y/n)  or change char? (c): ");
		scanf(" %c", &command);
		
		if (command == 'c' || command == 'C')
		{
			c = change_char();
			flag = 1;
		}
		printf("\n");
	} while (command == 'y' || command == 'Y' || flag == 1);

	return 0;
}

char change_char(void)
{
	char c;
	fflush(0);
	printf("Enter a new char: ");
	c = getchar();
	fflush(0);
	return c;
}

void get_size(term_size *t_size)
{
	
	struct winsize w;
	ioctl(1 , TIOCGWINSZ, &w);
	t_size->rows = w.ws_row;
	t_size->cols = w.ws_col;

}

void	generate(int *rule_arr, term_size *t_size, char c)
{

	int cols = (t_size->cols / 3) * 3;
	int rows = t_size->rows;
	int	current_line [cols];
	int	next_line [cols];
	int	count;

	count = 0;
	while (count < rows)
	{
		print_line(current_line, cols, c);
		//checker zone then LOGIC
		for (int i = 0; i <= cols - 3; ++i)
		{
			if (current_line[i] == 1)
			{
				if (current_line[i+1] == 1)
				{
					if (current_line[i+2] == 1)
					{
						use_rule(rule_arr, next_line, i, 0);
						continue;
					}
					use_rule(rule_arr, next_line, i, 1);
					continue;
				}
				else if (current_line[i+2] == 1)
				{
					use_rule(rule_arr, next_line, i, 2);
					continue;
				}
				else
				{
					use_rule(rule_arr, next_line, i, 3);
					continue;
				}
			}
			if (current_line[i+1]==1)
			{
				if (current_line[i+2] == 1)
				{
					use_rule(rule_arr, next_line, i, 4);
					continue;
				}
				use_rule(rule_arr, next_line, i, 5);
				continue;;
			}
			else if (current_line[i+2] == 1)
			{
				use_rule(rule_arr, next_line, i, 6);
				continue;;
			}
			use_rule(rule_arr, next_line, i, 7);
			continue;
		}
        //copy and replace next_line to current_line
		for (int i = 0; i < cols; ++i)
			current_line[i] = next_line[i];
		++count;
	}
}

int		get_rule(int *rule_arr)
{
	int	val;
	int	num;
	int	i;

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

void	print_line(int *arr, int cols, char c)
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

void	use_rule(int *rule_arr,int *arr, int i, int num)
{
	if (rule_arr[num] == 1)
		arr[i + 1] = 1;
		else
		arr[i+1] = 0;
}