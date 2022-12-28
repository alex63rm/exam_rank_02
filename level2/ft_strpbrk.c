/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:50:17 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 19:35:12 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>


char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j;

	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return ((char *)s1 + i); // cast it to (char *) and add i
			j++;
		}
		i++;
	}
	return (0);
}

int	main (void)
{
	char s1[] = "Hello";
	char accept[] = "ekp";

	printf("my result: %s\n", ft_strpbrk(s1, accept));
	printf("original : %s\n", strpbrk(s1, accept));

	return (0);
}

/* Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

// same as strcspn, this one returns a pointer instead of the position
