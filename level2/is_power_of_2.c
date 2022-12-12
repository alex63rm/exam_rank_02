/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:53:36 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/12 23:22:52 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);		// 2⁰ == 1
	while (n >= 2)
	{
		if (n % 2 == 1)	// loop, if at some point it is 1, return 0
			return (0);
		if (n % 2 == 0)	// if it is divisible by 2, keep looping. If it does not return here, it returns 1 in the end
			n = n / 2;
	}
	return (1);
}

/* int	main(void)
{
	int n = 10;
	while (n > 0)
	{
		is_power_of_2(n);
		printf ("n is %d ", n);
		printf ("result is %d\n", is_power_of_2(n));
		n--;
	}
	return (0);
} */