/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:54:25 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/29 20:47:54 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)		// HAS NOTHING TO DO WITH PRIME NUMBERS
{
	int	index = 2;
	if (n == 1)					// special case 1 is 1
	{
		printf("1");
		return ;
	}
	if (n < 1)					// 0 or negative, exit
		return ;
	while (index <= n)			// check all the numbers <= to n (starting index in 2, otherwise we alwayus stay at the same place)
	{
		if(n % index == 0)		// if it is divisible
		{
			printf("%i", index);	// print it
			n = n / index;			// make the number smaller by the divided one
			index = 1;				// restart the index at 1 (same process)

			if (n != 1)				// if we are not at the end, print the *
				printf("*");
			if (n == 1)				// when finished, don't print the *
				return ;
		}
		index++;			// increase the index + 1, making it i = 2 again
	}
	return ;
}

int	main(int argc, char **argv)
{
	int number;

	if (argc == 2)
	{
		number = atoi(argv[1]);		// save the argument string as a number.
		if (number < 0)
			return (0);
		fprime(number);
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