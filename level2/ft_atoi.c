/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:33:42 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/21 00:41:03 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include<unistd.h>
#include<stdlib.h>
#include<stdio.h> */

int	ft_atoi(const char *str)
{
	unsigned int		i;
	int					sign;
	long unsigned int	number;

	sign = 1;
	i = 0;
	number = 0;

	/// !! order is important
	// 1. loop to remove the spaces or positive (only come at the beggining)
	// 2. if - convert to negative
	// 3. if + or - check the signs and advance (just once)
	// 4. loop to write the number

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')		// check if the char is a number
	{
		number = number * 10 + str[i] - '0'; // number starts in 0, then it increases to the left <---10 + str[i] etc
		i++;
	}
	return (number * sign);
}
/* int	main(void)
{
	char array[] = "-13268!";
	int	ret1;
	int ret2;

	ret1 = ft_atoi(array);
	ret2 = atoi(array);

	printf("my ft is: %d\n", ret1);
	printf("original is: %d\n", ret2);
	return (0);
} */

/* Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
 */