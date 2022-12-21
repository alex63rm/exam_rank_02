#include <stdlib.h>
#include <string.h>

int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

unsigned int	ft_countwords(char *s)
{
	int index = 0;
	int wordcount = 0;

	if (s == NULL)
		return (0);
	while (s[index])
	{
		while (ft_isspace(s[index]) && (s[index]))
			index++;
		if ((!(ft_isspace(s[index]))) && (s[index]))
			wordcount++;
		while ((!(ft_isspace(s[index]))) && (s[index]))
			index++;
	}
	return (wordcount);
}

char	*ft_strndup(char *str, unsigned int n)
{
	unsigned int index = 0;
	char *s;

	if (str == NULL)
		return (NULL);
	s = (char *)malloc((sizeof(char)) * n + 1);
	if (s == NULL)
	   return (NULL);
	while (n)
	{
		s[index] = str[index];
		index++;
		n--;
	}
	s[index] = '\0';
	return (s);
}

char    **ft_split(char *str)
{
	int index = 0;
	int word = 0;
	int start = 0;
	char	**s;

	if (str == NULL)
		return (NULL);
	s = (char **)malloc((sizeof(char *)) * ft_countwords(str) + 1);
	if (s == NULL)
		return (NULL);
	while (str[index])
	{
		while ((ft_isspace(str[index])) && (str[index]))
			index++;
		start = index;
		while ((!(ft_isspace(str[index]))) && (str[index]))
			index++;
		if (index > start)
			s[word++] = ft_strndup(str + start, index - start);
	}
	s[word] = NULL;
	return (s);
}


#include <stdio.h>
int main ()
{
	char s1[] = " hello	 over\n    		\t there \t";
	printf("\ncount words\nnumber: %i \n" , ft_countwords(s1));

	printf("\nstrndup\nstandard : |%s|" , strndup(s1, 10));
	printf("\nmine : |%s|", ft_strndup(s1, 10));

	printf("\nsplit\n");
	char **s;
	s = ft_split(s1);
	int index = 0;
	while (s[index])
		printf("\n|%s|\n", s[index++]);
	return (0);
}
