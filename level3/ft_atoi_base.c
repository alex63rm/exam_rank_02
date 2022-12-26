/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:21:31 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 11:48:44 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_base(int c, int str_base)
{
	// create the required bases
	char	low_base[] = "0123456789abcdef";
	char	up_base[] = "0123456789ABCDEF";
	int		i;

	i = 0;
	while (i < str_base)		// loop teh string while it is in the base
	{
		if (c == low_base[i] || c == up_base[i])
			return (i);			// return the position
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	unsigned int	i;
	int				num;
	int				sign;

	i = 0;
	num = 0;
	sign = 1;
	// loop spaces
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	// if -, convert
	if (str[i] == '-')
		sign = -1;
	// if advance + or -
	if (str[i] == '-' || str[i] == '+')
		i++;
	// loop: while the number is inside the base (in normal atoi it was between 0 to 9)
	while (ft_base(str[i], str_base) != 0)
	{
		//same as atoi, but no - 48, it has its own base
		num = num * str_base + ft_base(str[i], str_base);
		i++;
	}
	return (num * sign);
}

/* #include<stdio.h>
#include<limits.h>

int	main(void)
{
	int	ret1;
	ret1 = ft_atoi_base("-3000", 16);
	printf("%d\n", ret1);
	return (0);
} */

/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
 */