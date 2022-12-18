/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:22:32 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/17 20:40:33 by alejarod         ###   ########.fr       */
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

// 3. check if prime number. 1 true, 0 false. Prime: not divisible by any number except 1 and itself.
int	ft_is_prime(int small_num)
{
	int	index = 2;		// start the index in 2 because by 1 it will be divisible

	while (index < small_num)	// just < n. because divided by itself it will return 1 and we don't want this
	{
		if (small_num % index == 0) // if divided by 2, 3, index++, if at any time the % is 0, it is divisible, NOT prime.
			return (0);		// 6 % 2 (result 3, % 0, not prime) 7 % 2 (result 3, % 1, prime)
		index++;			// break loop when index is same as n. It means it did not exit and the number is prime
	}
	return (1);
}

// 2. add all the primes together
void	ft_add_prime (int number)
{
	int	index = 2;	// loop from 2 until the number
	int sumof = 0;

	while (index <= number) // loop an index of all the numbers lower than the input number
	{						//<= because we need to add the number itself also
		if(ft_is_prime(index) == 1) // check if the current index is prime
			sumof += index; // if it is, add it (we are adding all the primes)
		index++;
	}
	ft_putnbr(sumof);
}

// 1. Regular atoi to convert number
int	ft_atoi(char *str)
{
	unsigned int	i;
	int				sign;
	int				num;

	sign = 1;
	num = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' || str[i] <= '9'))
	{
		num = num * 10 + str[i] - '0';
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
		if (number <= 0) // if number is 0 or negative return 0\n and exit
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