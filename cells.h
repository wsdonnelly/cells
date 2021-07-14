#ifndef CELLS_H
# define CELLS_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/ioctl.h>
# include <unistd.h>

//# define WIDTH 291/*some multiple of three*///user input size
//# define END 35
typedef struct s_term_size
{
	int			cols;
	int			rows;
}				term_size;


int		get_rule(int *rule_arr);
void	generate(int *rule_arr, term_size *t_size);
void	print_line(int *arr, int width);
void	use_rule(int *rule_arr, int *arr, int i, int num);
void	get_size(term_size *t_size);

#endif