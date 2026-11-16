

int is_valid_number(char *s)
{
	int	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i])
		return (0);
	return (1);
}

/* #include <stdio.h>
int main()
{
	printf("%d", is_valid_number("-244s2"));
	return 0;
} */