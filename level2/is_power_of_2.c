/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:15:47 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 21:15:19 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	is_power_of_2(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	if (n >= 2)
	{
		if ((n & (n - 1)) == 0)	// bitwise
			return (1);
	}
	return (0);
}

/* int	main(void)
{
	int n = 20;
	while (n > 0)
	{
		is_power_of_2(n);
		printf ("n is %d ", n);
		printf ("result is %d\n", is_power_of_2(n));
		n--;
	}
	return (0);
} */

/* Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
 */