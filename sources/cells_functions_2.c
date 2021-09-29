#include "cells.h"

void	generate(int *rule_arr, term_size *t_size, char c)
{
	int cols = (t_size->cols / 3) * 3;
	//int rows = t_size->rows;
	int	*current_line;
	int	*next_line;
	int	count;
	//char buf;

	current_line = (int*)malloc(sizeof(int) * cols);
	next_line = (int*)malloc(sizeof(int) * cols);
	count = 0;
	
	//while (count < rows)
	while(count >= 0)
	{
		print_line(current_line, cols, c);
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
		for (int i = 0; i < cols; ++i)
			current_line[i] = next_line[i];
		++count;
		usleep(20000);
	}
	free(current_line);
	free(next_line);
	fflush(stdin);
}