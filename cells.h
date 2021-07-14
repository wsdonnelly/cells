#ifndef CELLS_H
# define CELLS_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/ioctl.h>
//# include <unistd.h> //??

typedef struct	s_term_size
{
	int			rows;
	int			cols;
}				term_size;

int				get_rule(int *rule_arr);
char			change_char(void);
void			generate(int *rule_arr, term_size *t_size, char c);
void			print_line(int *arr, int cols, char c);
void			use_rule(int *rule_arr, int *arr, int i, int num);
void			get_size(term_size *t_size);

#endif