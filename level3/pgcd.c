/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 01:33:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/18 01:48:00 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

// highest common denominator.
void	ft_pgcd(unsigned int number1, unsigned int number2)
{
	unsigned int index;

	if (number1 > number2)
		index = number2;
	else if (number2 > number1)		// set index as the lowest number
		index = number1;
	while (index > 0)				// loop decresing until the index remainder is 0 for both numbers
	{
		if (number1 % index == 0 && number2 % index == 0)
		{
			printf("%d", index);
			return ;
		}
		index--;
	}
	return ;

}

int	main(int argc, char **argv)
{
	unsigned int number1, number2;
	if (argc == 3)
	{
		number1 = atoi(argv[1]);
		number2 = atoi(argv[2]);
		ft_pgcd(number1, number2);
	}
	printf("\n");
	return (0);
}