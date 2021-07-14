#include "cells.h"

int main(void)
{
	char	command;
	int		rule_arr[8] = {0};

	do{
		get_rule(rule_arr);
		generate(rule_arr);
		printf("Run again? (y/n): ");
		scanf(" %c", &command);
		printf("\n");
	} while (command == 'y' || command == 'Y');

	return 0;
}

void	generate(int rule_arr[8]){

	int	current_line[WIDTH] = { [WIDTH / 2] = 1};
	int	next_line[WIDTH] = {0};
	int	count;

	count = 0;
	while (count < END)
	{
		print_line(current_line, WIDTH);
		//checker zone then LOGIC
		for (int i = 0; i <= WIDTH - 3; ++i)
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
		for (int i = 0; i < WIDTH; ++i)
			current_line[i] = next_line[i];
		++count;
	}
}

int		get_rule(int *rule_arr)
{
	int	val;
	int	num;
	int	i;

	srand(time(0));
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

void	print_line(int arr[], int width)
{
	char	c;

	c = '@'; //user input this char
	for (int i = 0; i < width; ++i)
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