/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:40:56 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 13:42:03 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

char *ft_strrev(char *str)	// DRAW AND IMAGINE
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)	// no need for (if % 2 == 0), in the middle it gets replaced by itself
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

/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
 */