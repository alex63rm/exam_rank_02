/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:16:11 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/29 21:18:44 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_rostring(char *str)				// use the logic and DRAW
{
	int i = 0;
	int	start;
	int	end;
	int first_time_space;

	while (str[i] && ft_isspace(str[i]) == 1)	// loop initial spaces
		i++;
	start = i;			// save the start of the word
	while (str[i] && ft_isspace(str[i]) == 0)
		i++;
	end = i;				// save the end of first word
	// loop through all the words write the string as usual (remove and leave just one space)
	first_time_space = 1;			// I need to create this flag to avoid putting a space at the beggining of the string
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]) == 1)
			i++;
		if (first_time_space == 0)		// the first time I want to avoid writing the space
			write (1, " ", 1);			// write spaces after the words (except in the first one)
		while (str[i] && ft_isspace(str[i]) == 0)
		{
			write(1, &str[i], 1);
			i++;
		}
		first_time_space = 0;			// inside the loop set the "flag" to zero to start writing spaces after the words
	}									// no need to write i++ at the end, they are already inside
	write (1, " ", 1);
	while (end > start)					// write the first_word
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rostring(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$> */