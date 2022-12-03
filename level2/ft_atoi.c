/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:33:42 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/03 19:39:40 by alejarod         ###   ########.fr       */
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
	// check if the char is a number
	while (str[i] >= 48 && str[i] <= 57)
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