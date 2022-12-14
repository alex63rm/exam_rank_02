/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:48:27 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/11 21:28:16 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
	return ;
}

int ft_atoi(char *str)
{
	int number = 0;
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

void	ft_putnbr_hex(unsigned int num)
{
	if (num >= 16)			// NO LOOP WITH RECURSIVE
		ft_putnbr_hex(num / 16);
	ft_putchar("0123456789abcdef"[num % 16]);
	/* ft_putchar is a function that outputs a single character to the standard output (usually the terminal).
	The argument passed to the function is a character contained in the string "0123456789abcdef".
	The expression "num % 16" is the modulo operator, which returns the remainder of the division of "num" by 16.
	For example, if "num" is 17, the expression "num % 16" will evaluate to 1. If "num" is 32, the expression "num % 16" will evaluate to 0.
	The brackets around "num % 16" are used to access the character at the corresponding index in the string "0123456789abcdef".
	So, for example, if "num % 16" evaluates to 1, the character at index 1 in the string will be accessed, which is the character '1'. If "num % 16" evaluates to 10, the character at index 10 in the string will be accessed, which is the character 'a'.
	Therefore, the function ft_putchar will output the character at the index specified by the expression "num % 16" in the string "0123456789abcdef". */
	return ;
}

int	main(int argc, char **argv)
{
	unsigned int	number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		if (number < 0)
			return (0);			// subject: only takes positive numbers
		ft_putnbr_hex(number);
	}
	write (1, "\n", 1);
	return (0);
}

/* Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
 */