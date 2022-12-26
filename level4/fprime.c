/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:54:25 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 11:57:18 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int	index = 2;
	if (n == 1)					// special case 1 is 1
	{
		printf("1");
		return ;
	}
	if (n < 1)					// 0 or negative, exit
		return ;
	while (index <= n)			// check all the numbers <= to n
	{
		if(n % index == 0)		// if it is divisible
		{
			printf("%i", index);	// print it
			n = n / index;			// make the number smaller by the divided one
			index = 1;				// once the number has been made small, restart the index (same process)

			if (n != 1)
				printf("*");		// if we are not at the end, print the *
			if (n == 1)				// don't print the * after the last number
				return ;
		}
		index++;			// increase the index + 1
	}
	return ;
}


int	main(int argc, char **argv)
{
	int number;

	if (argc == 2)
	{
		number = atoi(argv[1]);		// save the argument string as a number.
		fprime(number);
	}
	printf("\n");
	return (0);
}