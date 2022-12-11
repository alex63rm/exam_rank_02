/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:21:31 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/11 19:56:24 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_base(int c, int str_base)
{
	// create the required base
	char	low_base[] = "0123456789abcdef";
	char	up_base[] = "0123456789ABCDEF";
	int		i;

	i = 0;
	// loop the string permanently
	while (i < str_base)
	{
		if (c == low_base[i] || c == up_base[i])
			// return the position
			return (i);
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

/* int	main(void)
{
	int	ret1;
	ret1 = ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.", 16);
	printf("%d\n", ret1);
	return (0);
} */