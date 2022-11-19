/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:54:25 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/19 16:31:10 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int	index = 2;	
	if (n == 1)
	{
		printf("1");
		return ;
	}
	if (n < 1)
		return ;
	while (index <= n)
	{
	// we print if it is divisible (== 0)
		if(n % index == 0)
		{
			printf("%i", index);
			// update the number
			n = n / index;
			// restart the index to 1
			index = 1;
			if (n == 1)
				return ;
			else
				printf("*");
		}
		// increase the index + 1
		index++;
	}
	return ;
}


int	main(int argc, char **argv)
{
	int number;
	
	if (argc == 2)
	{
		number = atoi(argv[1]);
		fprime(number);
	}
	// save the argument string as a number.
	printf("\n");
	return (0);
}