/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:29:56 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 13:35:14 by alejarod         ###   ########.fr       */
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
		j = 0;							//ever round searches reject from the beggining
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);				// return the position of s where it found the letter
			j++;
		}
	i++;
	}
return (i);
}

//this function will return 2, because 'l' in World is found in position 2 of the original string
int main (void)
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
}

/* Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
 */

// searches for a char of reject in s and return the position of s where it was found