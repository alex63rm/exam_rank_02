/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:48 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/21 19:32:34 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_isblank(char c)
{
	if (c == 9 || c == 32)
		return (1);
	return (0);
}

void	ft_first_word(char *str)
{
	unsigned int	i;

	i = 0;
	// 1. remove inital spaces
	while (ft_isblank(str[i]) == 1)
		i++;
	// while writing stop at end of str, otherwise overflow if no spaces at the end
	while (ft_isblank(str[i]) == 0 && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if(argc == 2)
	{
		ft_first_word(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}