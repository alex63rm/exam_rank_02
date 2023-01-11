/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:08:03 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/11 22:21:23 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//printf & atoi
#include<stdio.h>
#include<stdlib.h>

void	ft_fprime(int number)		// HAS NOTHING TO DO WITH PRIME NUMBERS (example 42)
{
	int index = 2;				// start in 2, in 1 we would be at the same place all the time

	if (number == 1)			// special case, 1 is 1
		printf("1");
	while (number >= 2)
	{
		if (number % index == 0)		// if we found a divisible number
		{
			printf("%d", index);			// print it
			number = number / index;		// continue from that number
			index = 1;						// reset index to 1 (it will become 2 again after index++)

			if (number != 1)		// if the number is not one, print the * for the next
				printf("*");
			if (number == 1)		// exit condition: don't print the * and return;
				return ;
		}
		index++;
	}
}

int	main(int argc, char **argv)
{
	int number;
	if (argc == 2)
	{
		number = atoi(argv[1]);
		if (number < 0)		// subject: strictly positive numbers
		{
			printf("\n");
			return (0);
		}
		ft_fprime(number);
	}
	printf("\n");
	return (0);
}

// SEE LOGICAL APPROACH BELOW

/* Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
 */

//APPROACH
/* number 42

					  |
					  v
n = 42 i = 2 and loop 2, 3, 4, 5, 6...... (divisible by 2)

print, divide and restart the loop at index = 1, because then we will have an i++ that makes it 2 again

			  |
			  v
n = 21 i = 2, 3, 4 ...... (divisible by 3)

						  |
						  v
n = 7  i = 2, 3, 4, 5, 6, 7, 8 ....... (divisible by 7)

n = 1 now return (don't print the *)
*/