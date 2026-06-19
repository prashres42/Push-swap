#include "push_swap.h"

double compute_disorder(t_stack *stack)
{
	t_node *i;
	t_node *j;
	int mistakes;
	int total_pairs;

	if(!stack || stack->size < 2)
		return(0);
	mistakes = 0;
	total_pairs = (stack->size * ((stack->size - 1) / 2));
	i = stack->top;
	while (i)
	{
		j = i->next;
		while(j)
		{
			if(i->value > j->value)
			{
				mistakes++;
				j = j->next;;
			}
		}
		i = i->next;
	}
	return((double)mistakes/total_pairs);
}
