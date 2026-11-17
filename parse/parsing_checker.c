
#include <limits.h>
#include "push_swap.h"

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	to_int(char *s, int *out)
{
	int sign = 1;
	long result = 0;
	int i = 0;
	if (s[i] == '-' || s[i] == '+'){
		if (s[i] == '-')
			sign = -1;
		i++;}
	while (ft_isdigit(s[i])){
		result = (result * 10) + (s[i] - '0');
		if (((result * sign > INT_MAX) || (result * sign) < INT_MIN))
			return (0);
		i++;}
	*out = (int)(result * sign);
	return (1);
}

int is_valid_number(char *s)
{
	int	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i])
		return (0);
	return (1);
}
