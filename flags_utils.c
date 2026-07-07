#include "push_swap.h"
int ft_strcmp(char *str1, char *str2)
{
	while(*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char) *str1 - (unsigned char)*str2);
}
int compare_flags(char *argv, t_flags *flag_value)
{
	
	if(ft_strcmp(argv, "--simple") == 0)
		flag_value->simple += 1;
	else if(ft_strcmp(argv, "--complex") == 0)
		flag_value->complex += 1;
	else if(ft_strcmp(argv, "--medium") == 0)
		flag_value->medium += 1;
	else if(ft_strcmp(argv, "--adaptive") == 0)
		flag_value->adaptive += 1;
	else if(ft_strcmp(argv, "--bench") == 0)
		flag_value->bench += 1;	
	else
		return (-1);
	return (0);
}
static void ini_flags(t_flags *flag_value)
{
	flag_value->simple = 0;
	flag_value->medium = 0;
	flag_value->complex = 0;
	flag_value->adaptive = 0;
	flag_value->bench = 0;
}
t_flags *check_flag(char **argv)
{
	t_flags *flag_value;

	flag_value = malloc(sizeof(t_flags));
	if(!flag_value)
		return(NULL);
	ini_flags(flag_value);
	while(*argv && ((*argv)[0] == '-' && (*argv)[1] == '-'))
	{
		if(compare_flags(*argv++, flag_value) == -1)
		{
			ft_printf("Error\n");
			free(flag_value);
			return(NULL);
		}
	}
	return (flag_value);

}
int flags_total(t_flags *flags)
{
	if(!flags)
		return (0);
	if(((flags->simple + flags->complex + flags->medium + flags->adaptive) > 1)
		|| flags->bench > 1)
	{
		free(flags);
		exit (1);
	}
	return (flags->simple + flags->complex + flags->medium
			 + flags->adaptive + flags->bench );
}
