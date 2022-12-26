/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:59:58 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 13:30:03 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	// forgot the last s1[i] == s2[i]
	while (s1[i] && s2[i] && s1[i] == s2[i])	// while both (otherwise overflow) && equal advance
		i++;
	return (s1[i] - s2[i]);						//return the difference

}
/* int	main (void)
{
	int ret1;
	int ret2;

	char s1[] = "hello";
	char s2[] = "hello333";

	ret1 = ft_strcmp(s1, s2);
	printf("my function is %i\n", ret1);

	ret2 = strcmp(s1, s2);
	printf("original is %i\n", ret2);
} */

/* Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
 */