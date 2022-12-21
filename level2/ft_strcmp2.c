/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:24:48 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/21 00:47:56 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	// always check until the null, otherwise it will overflow
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);

}

/* int	main(void)
{
	char s1[] = "Hell";
	char s2[] = "Hello";
	int ret1 = ft_strcmp(s1, s2);
	printf("my is: %d\n", ret1);
	int ret2 = strcmp(s1, s2);
	printf("or is: %d\n", ret2);
	return (0);
} */

/* Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
 */