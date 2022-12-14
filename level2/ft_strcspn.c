/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:29:56 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/31 18:26:39 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)	// compare with MAN function
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;						// every round searches reject from the beginning of reject
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);			// return the position of s where it found the letter
			j++;
		}
	i++;
	}
	return (i);		// if no chars are found, returns the len of *s
}

// this function will return 2, because 'l' in World is found in position 2 of the original string
// MAKE A MAIN AND COMPARE WITH ORIGINAL FUNCTION

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