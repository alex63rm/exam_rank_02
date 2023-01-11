/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:40:22 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/11 23:56:20 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_rev_wstr(char *str)			// DRAW THE EXAMPLE. It is a "las word" inside a loop
{
	int len = ft_strlen(str);
	int end;
	int start;

	len = len - 1;					// Special case. Before entering the loop, skip the NUL. Set the starting position in the last char of the string
	while (len >= 0)
	{
		while (len >= 0 && ft_isspace(str[len] == 1))	// skip the NUL (it is the special case)
			len--;
		end = len;
		while (len >= 0 && ft_isspace(str[len]) == 0)
			len--;
		start = len + 1;						// Draw (skip the only space)

		while (start <= end)					// Draw
		{
			write (1, &str[start], 1);
			start++;
		}
		if (len > 0)				// "flag", when we are not in the first postion, write a space after the word
			write(1, " ", 1);
		len--;
	}
	return ;

}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev_wstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

/* Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$> */