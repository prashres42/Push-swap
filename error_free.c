#include "push_swap.h"

int error_syntax(char **a)
{
	int i;
	int j;

	i = 0;
	j = 0; 
	while(a[i])
	{
		while(a[i][j])
		{
			if(!ft_isdigit(a[i][j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error_repitition(t_stack_node *a, int nbr)
{
	if(a = NULL)
		return (0);
	while(a)
	{
		if(a->value == nbr)
			return(1);
		a = a->next;
	}
	return (0);
}