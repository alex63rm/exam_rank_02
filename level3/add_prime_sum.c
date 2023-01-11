/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:22:32 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/11 20:43:57 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + 48;
	ft_putchar(nbr);
}

// #1 is NOT A PRIME NUMBER. #2 IS.
// 3. check if prime number. 1 true, 0 false. Prime: not divisible by any number except 1 and itself.
int	ft_is_prime(int small)
{
	int	index = 2;		// start the index in 2 because by 1 it will be divisible

	while (index < small)	// just < small. because divided by itself it will return 1 and we don't want this
	{
		if (small % index == 0) // if divided by 2, 3, index++, if at any time the % is 0, it is divisible, NOT prime.
			return (0);		// 6 % 2 (result 3, % 0, not prime) 7 % 2 (result 3, % 1, prime)
		index++;			// break loop before index is same as n. It means it did not exit and the number is prime
	}
	return (1);
}

// 2. add all the primes together
void	ft_add_prime (int number)
{
	int	index = 2;	// loop from 2 until the number (included)
	int sumof = 0;

	if (number == 0)	// Special case: exit if 0 (not prime, so no sum)
		return ;
	if (number == 1)	// Spceial case: exit if 1 (not prime, so no sum)
		return ;
	while (index <= number) // loop an index of all the numbers lower or equal (number must be added too) than the input number
	{						//<= because we need to add the number itself also
		if (ft_is_prime(index) == 1) // check if the current index is prime
			sumof = sumof + index; // if it is, add it (we are adding all the primes)
		index++;
	}
	ft_putnbr(sumof);
}

// 1. Regular atoi to convert number
int	ft_atoi(char *str)
{
	int	i = 0;
	int	sign = 1;
	int	num = 0;

	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' || str[i] <= '9'))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]); // 1. change argv to int (normal atoi) and save it
		if (number < 0) // if number is 0 or negative return 0\n and exit
		{
			write(1, "0\n", 2);
			return (0);
		}
		else	// 2. otherwise add the prime numbers + $
		{
			ft_add_prime(number);
			write (1, "\n", 1);
		}
	}
	else
		write (1, "0\n", 2); // if not 2 arguments write a 0
	return (0);
}

//<<<*** 1 is not a prime number ***>>>

/* Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
 */