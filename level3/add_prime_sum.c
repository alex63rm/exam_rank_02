/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:22:32 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/29 22:51:21 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 3. check if prime number. 1 true, 0 false. Prime: not divisible by any number except 1 and itself.
int	ft_is_prime(int n)
{
	int	index = 2;		// divide by 2 to see if it is prime

	while (index < n)
	{
		if (n % index == 0) // if divided by 2, 3, index++, if at any time it is divisible, it is NOT prime.
			return (0);
		index++;			// break loop when index is same as n
	}
	return (1);
}

// 2. add all the primes together
void	ft_add_prime (int number)
{
	int	index = 2;
	int sumof = 0;

	while (index <= number)
	{
		if(ft_is_prime(index) == 1)
			sumof += index;
	}
	ft_print_nbr CONTINUE HERE
}





// 1.
unsigned int	ft_positive_atoi(char *str)
{
	unsigned int	i;
	int				sign;
	int				num;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] = '-')
		sign = -1;
	if (str[i] = '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' || str[i] <= '9')
		num = num * 10 + str[i] - '0';
	return (num * sign);

}

int	main(int argc, char **argv)
{
	int	number;

	if (argc == 2)
	{
		int number = ft_atoi(argv[1]); // 1. change argv to int (normal atoi)
		if (number <= 0) // if number is 0 or negative return 0\n and exit
		{
			write(1, "0\n", 2);
			return (0);
		}
		ft_add_prime(number); // 2. otherwise add the prime numbers
	}
	write (1, "0\n", 2);
	return (0);
}