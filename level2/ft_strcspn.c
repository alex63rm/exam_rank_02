/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:29:56 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/11 16:43:44 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
	i++;
	}
return (i);
}

//this function will return 2, because 'l' in World is found in position 2 of the original string
/* int main (void)
{
	char s[] = "Hello";
	char reject[] = "World";

	size_t ret1;
	size_t ret2;

	ret1 = ft_strcspn(s, reject);
	ret2 = strcspn(s, reject);

	printf("my: %lu\n", ret1);
	printf("or: %lu\n", ret2);
	return (0);
} */