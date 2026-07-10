/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:03:46 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/10 17:58:58 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "LIBFT/libft.h"
# include "ft_printf/ft_printf.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;
typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}		t_flags;
typedef struct s_bench
{
	int	disorder;
	int	total_ops;
	char	*strategy;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_bench;
typedef struct s_pointer_bench_flag
{
	t_flags	*flags;
	t_bench	*bench;
}			t_ptr_b_f;

t_bench		*ini_bench(void);
t_ptr_b_f	bench_flags(t_bench *bench, t_flags *flags);

double		compute_disorder(t_stack *stack);

int			error_syntax(char **a);
int			error_repitition(t_node *a, int nbr);
void		ft_error(t_stacks *data, t_ptr_b_f ptr, char **splitted);
void		free_data(t_stacks *data, t_bench *bench, t_flags *flags);
void		free_split(char **splitted);
void		stack_free(t_stack *stack);
void		free_memory(t_bench *bench, t_flags *flag);

int			compare_flags(char *argv, t_flags *flag_value);
t_flags		*check_flags(char **argv);
t_flags		*check_flag(char **argv);
int			flags_total(t_flags *flags);

t_stacks	*parse_args(char **argv, t_ptr_b_f ptr_b_f);
long		ft_atol(const char *str);
int			is_sorted(t_stack *stack);
t_stack		*new_stack(void);
t_node		*node_new(int value, t_stacks *data, t_ptr_b_f ptr);
void		stack_addback(t_stack *stack, t_node *node);
int			find_min_index(t_stack *stack);
int			find_max_index(t_stack *stack);
void 		assign_indexes(t_stacks *data);
void		print_stack(t_stack *stack);
void 		print_bench(t_bench *bench);


void		rra(t_stacks *data, t_bench *bench, int print);
void		rrb(t_stacks *data, t_bench *bench, int print);
void		rrr(t_stacks *data, t_bench *bench, int print);
void		ra(t_stacks *data, t_bench *bench, int print);
void		rb(t_stacks *data, t_bench *bench, int print);
void		rr(t_stacks *data, t_bench *bench, int print);
void		sa(t_stacks *data, t_bench *bench, int print);
void		sb(t_stacks *data, t_bench *bench, int print);
void		ss(t_stacks *data, t_bench *bench, int print);
void		pa(t_stacks *data, t_bench *bench, int print);
void		pb(t_stacks *data, t_bench *bench, int print);

void		selection_sort(t_stacks *data, t_bench *bench, int print);
void		sort_medium(t_stacks *data, t_bench *bench, int print);
void		min_to_top(t_stacks *data, int pos, t_bench *bench, int print);
void		radix_sort(t_stacks *data, t_bench *bench, int print);
void		implement_algo(t_stacks *data, t_bench *bench, t_flags *flag);
void		adaptive_sort(t_stacks *data, t_bench *bench, int print);

#endif