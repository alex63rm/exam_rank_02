/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:48:27 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/20 00:32:06 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
	return ;
}

unsigned int ft_atoi(char *str)
{
	unsigned int number = 0;
	int sign = 1;
	unsigned int i = 0;

	// loop spaces
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	// check negative
	if (str[i] == '-')
		sign = sign * -1;
	// advance sign
	if (str[i] == '-' || str[i] == '+')
		i++;
	// loop numbers
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * sign);

}

void	ft_print_hex(unsigned int num)
{
	if (num >= 16)
		ft_print_hex(num / 16);
	ft_putchar("0123456789abcdef"[num % 16]);
	return ;
}

int	main(int argc, char **argv)
{
	unsigned int	number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		ft_print_hex(number);
	}
	write (1, "\n", 1);
	return (0);
}