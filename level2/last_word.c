/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:34:36 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/20 16:58:12 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include<stdio.h>

int	ft_isblank(char c)
{
	if (c == 32 || c == 9)
		return (1);
	return (0);
}

void	ft_last_word(char *str)
{
	unsigned int	len;

	len = 0;
	// 1.count the length of the string
	while (str[len])
		len++;
	// remove the '\0' to start from the last letter of the index
	len = len - 1;
	// 2.remove the final spaces or tabs
	while (ft_isblank(str[len]) == 1)
		len--;
	// 3.count the lenght of the word
	while (ft_isblank(str[len]) == 0)
		len--;
	// len stopped in the space.
	// I want to start printing after the space
	len = len + 1;
	// print the word
	while(ft_isblank(str[len]) == 0 && str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
}


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_last_word(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}