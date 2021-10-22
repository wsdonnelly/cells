#include "cells.h"

//if next line is same as previous and count is greater than number of rows stop.

void	generate(int *rule_arr, term_size *t_size, char c)
{
	int cols = (t_size->cols / 3) * 3;
	//int rows = t_size->rows;
	int	*current_line;
	int	*next_line;
	int	count;
	int check;
	

	current_line = (int*)malloc(sizeof(int) * cols);
	next_line = (int*)malloc(sizeof(int) * cols);
	count = 0;
	check = 0;
	//while (count < rows) fill screen
	while (check != cols && count < 800)
	//while(count >= 0) infinite loop
	{
		print_line(current_line, cols, c);
		for (int i = 0; i <= cols - 3; i++)
		{
			if (current_line[i] == 1)
			{
				if (current_line[i + 1] == 1)
				{
					if (current_line[i + 2] == 1)
					{
						use_rule(rule_arr, next_line, i, 0);
						continue;
					}
					use_rule(rule_arr, next_line, i, 1);
					continue;
				}
				else if (current_line[i + 2] == 1)
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
			if (current_line[i + 1]==1)
			{
				if (current_line[i + 2] == 1)
				{
					use_rule(rule_arr, next_line, i, 4);
					continue;
				}
				use_rule(rule_arr, next_line, i, 5);
				continue;
			}
			else if (current_line[i + 2] == 1)
			{
				use_rule(rule_arr, next_line, i, 6);
				continue;
			}
			use_rule(rule_arr, next_line, i, 7);
			continue;
		}
		check = 0;
		for (int i = 0; i < cols; i++)
		{
			if (current_line[i] == next_line[i]) //check if theyre the same
				check++;
			current_line[i] = next_line[i]; //next line becomes current line
		}
		count++;
		usleep(30000);
	}
	free(current_line);
	free(next_line);
	fflush(stdin);
}