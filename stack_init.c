#include "push_swap.h"

long ft_atol(const char *str)
{
	long result;
	int i ;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] && (str[i] >= 9 || str[i] <= 13))
		i++;
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
			return (LONG_MAX);
	}
	return (result * sign);
}
/*  Create the stack with the command line value
	Checks are embedded in the creation itself
		INT MIN/MAX check	
		Duplicate check */
int	stack_init(t_stack_node **a, char **argv)
{
	long nbr;
	int i;

	i = 0;
	while(argv[i])
	{
		nbr = ft_atol(argv[i]);
		if(nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		if(error_syntax(argv[i]) || error_repition(*a, (int)nbr))
			return (1);
		append_node(a, (int)nbr);
		i++;
	}
}