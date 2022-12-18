/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:32:43 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/18 01:51:59 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

// lcm is the lowest number in which both of the numbers are divisible: i.e.
// 10 and 20, min is 20 // 6 and 8 is 24 (24 % 6 == 0, 24 % 8 == 0)
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int index;

	if (a == 0 || b == 0)	//if one of them is 0, return 0
		return (0);
	if (a > b)		// set the index from the highest number (it is not necessary, we can start indexing from 1 and go up)
		index = a;
	else
		index = b;
	while (1)		// loop without a specific condition
	{
		if(index % a == 0 && index % b == 0)	// when there is no remainder for both, it is the lcm;
			return (index);
		index++;			// increase the index until we find a highest number
	}
	return (index);
}

int main(void)
{
	int a = 26;
	int b = 100;

	printf("lcm is: %d\n", lcm(a,b));
	return (0);
}