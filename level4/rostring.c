/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:23:04 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/12 15:15:06 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_rostring(char *str)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int written = 0;

	while (str[i] && ft_isspace(str[i]) == 1)		// 1. Advance through the FIRST WORD and save the start and end positions
		i++;
	start = i;
	while (str[i] && ft_isspace(str[i]) == 0)		// DRAW for easier assignment of start and end
		i++;
	end = i;									
	int flag = 0;
	while (str[i])									// 2. Continue writing in a loop after the first word
	{
		while (str[i] && ft_isspace(str[i]) == 1)		// Skip ALL the spaces and leave just one
			i++;
		if (str[i] && flag == 1)			// 4. Flag to skip the space after the FIRST WORD && the spaces at the end of the last word
			write(1, " ", 1);						// 3. Write a " " after skipping all the spaces (subject: just one space)
		while (str[i] && ft_isspace(str[i]) == 0)
		{
			write(1, &str[i], 1);
			written++;								// This is a flag to check if we wrote something. In this case, we need a space before FIRST WORD
			i++;
		}
		flag = 1;				// reset the flag
	}
	if (written >= 1)			// 6. Flag. We only need a space if we wrote something before "abc", not "_abc". If "le temps" we need space: "temps_le"
		write(1, " ", 1);
	while (start < end)			// 5. Write the first word at the end of the string
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	int i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			ft_rostring(argv[i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

//APPROACH:

/*
| a | b | c |  |  |  |
the problem is that I am always writing a space + first word, which is good if there are words BEFORE
So I need a flag, only I will write the space if there were words before.
I create a written flag. Inside the place where it writes. If it is 0, it did not enter the loop and it means
we don't need a space before the first word, since it is the only word

| NULL  |   | a | b | c |  |  |  |

 */

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