#include "push_swap.h"

long ft_atol(const char *str)
{
	long result;
	int i ;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
			i++; 
		}
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (result > INT_MAX || result < INT_MIN)
			return (0);
	}
	return (result * sign);
}

static int pars_args_helper(char **splitted, char **argv, t_stacks *data, t_ptr_b_f ptr)
{
	t_node *new;
	int i;
	long nbr;

	while(*argv)
	{
		i = 0;
		splitted = ft_split(*argv++, ' ');
		if(!splitted || !*splitted)
			ft_error(data, ptr, splitted);
		if(error_syntax(splitted))
			ft_error(data, ptr, splitted);
		while(splitted[i])
		{
			nbr = ft_atol(splitted[i]);
			new = node_new(nbr, data, ptr);
			stack_addback(data->a, new);
			i++;
		}
		if(error_repitition(new, (int)nbr))
			ft_error(data, ptr, splitted);
		free_split(splitted);
	}
	return (0);
} 
t_stacks *parse_args(char **argv, t_ptr_b_f ptr_b_f)
{
	t_stacks *data;
	char **splitted;
	
	splitted = NULL;
	data = malloc(sizeof(t_stacks));
	if(!data)
		return (NULL);
	data->a = new_stack();
	data->b = new_stack();
	if (!data->a || !data->b)
		return (ft_error(data, ptr_b_f, splitted), NULL);
	pars_args_helper(splitted, argv, data, ptr_b_f);
	return(data);
}