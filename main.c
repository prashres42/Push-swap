#include "push_swap.h"
int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	int i;

	i = 0;
	a = NULL;
	b = NULL;

	if(argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if(argc == 2)
	{
		while(argv[i])
		{
			argv = (ft_split(argv[i], ' '));
			i++;
		}
	}
	stack_init(&a, argv + 1);
	
}