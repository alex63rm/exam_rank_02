#include <stdio.h> /*printf(3) for testing*/

void ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strrev(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)	//no matter if % 2 == 0, in the middle it gets replaced by itself
	{
		ft_swap(&str[i], &str[len - 1]); // send the addresses for swap
		i++;
		len--;
	}
	return (str);
}

/* int	main(void)
{
	char array[] = "hello";

	printf("%s\n", ft_strrev(array));
	return (0);
} */