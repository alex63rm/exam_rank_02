/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:32:43 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 12:49:22 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

// lcm is the lowest number in which both of the numbers are divisible: i.e.
// 10 and 20, min is 20 // 6 and 8 is 24 (24 % 6 == 0, 24 % 8 == 0)
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int index = 1;

	if (a == 0 || b == 0)	//if one of them is 0, return 0
		return (0);
	while (1)		// loop without a specific condition
	{
		if(index % a == 0 && index % b == 0)	// INDEX % NUMBER, when there is no remainder for both, it is the lcm;
			return (index);
		index++;			// increase the index until we find a highest number
	}
	return (index);
}

int main(void)
{
	int a = 2;
	int b = 1;

	printf("lcm is: %d\n", lcm(a,b));
	return (0);
}

/* Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
 */