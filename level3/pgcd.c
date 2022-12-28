/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 01:33:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/28 22:31:22 by alejarod         ###   ########.fr       */
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
	else if (number2 > number1)		// set index as the lowest number (for efficiency to avoid timeout?). It could also be the hiughest of both
		index = number1;
	while (index > 0)				// loop decresing until the index remainder is 0 for both numbers
	{
		if (number1 % index == 0 && number2 % index == 0)	// here opposite to LCM, it is number % index
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

/* Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
 */