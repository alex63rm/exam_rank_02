/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:30:06 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/24 10:41:05 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(unsigned int c)	// careful!! if we don't put the functions in the correct order we may get gcc errors
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + 48;
	ft_putchar(nbr);
}

void	ft_tab_mult(int number)
{
	unsigned int i = 1;
	unsigned int result;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putchar('x');
		ft_putchar(' ');
		ft_putnbr(number);
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');
		result = i * number;
		ft_putnbr(result);
		ft_putchar('\n');
		i++;
	}
}

unsigned int	ft_atoi(char *str)
{
	unsigned int i = 0;
	int sign = 1;
	unsigned int num = 0;
	// loop spaces
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	// convert to negative
/* 	if (str[i] == '-')
		sign = sign * -1; */
	// skip signs
	if (str[i] == '-' || str[i] == '+')
		i++;
	// loop numbers
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}

int	main(int argc, char **argv)
{
	unsigned int number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);	// in this case positive atoi
		ft_tab_mult(number);
	}
	else
		write(1, "\n", 1);
	return (0);
}

/* Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
 */