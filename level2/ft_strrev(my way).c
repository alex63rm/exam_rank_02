/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:18:23 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/13 23:53:40 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void ft_swap(char *a, char *b)
{
	char temp;

	temp = *b;
	*b = *a;
	*a = temp;
	return ;
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strrev(char *str)
{
	int len;
	int half;
	int i = 0;

	len = ft_strlen(str);
	half = len / 2;			// I need
	if (half % 2 == 0)
	{
		while (i <= half)
		{
			ft_swap((str + i), (str + (len - 1)));
			i++;
			len--;
		}
	}
	if (half % 2 != 0)
	{
		while (i < half - 1)
		{
			ft_swap((str + i), (str + (len - 1)));
			i++;
			len--;
		}
	}
	return (str);
}

int	main(void)
{
	char array[] = "hello1";

	printf("%s\n", ft_strrev(array));
	return (0);
}