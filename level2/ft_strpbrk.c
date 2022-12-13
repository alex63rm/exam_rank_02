/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:50:17 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/13 23:12:10 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>

// same as strcspn, this one returns a pointer instead of the position

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i])
	{
		int j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return ((char *)s1 + i); // cast it to (char *) and ad i
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