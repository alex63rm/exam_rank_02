/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:26:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/22 00:39:51 by alejarod         ###   ########.fr       */
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

void	ft_rev_wstr(char *str, int len)						// DRAW THE EXAMPLE. try a small example = le temps du
{
	int start;
	//printf("\nlen at start %d\n", len);

	while (len > 0)											// Similar to last word. I will stop at len 0 (sanitize and test for errors)
	{
		while (str[len - 1] != ' ' && len > 0)				// think. Loop while no spaces. && len > 0 is for the first word (to avoid ovewrflow to the left <<<<)
			len--;
		start = len;										// fix the position from where to start writing
		while (str[start] != '\0' && str[start] != ' ')		// loop until we find a space or end of string (subject says no spaces in the start or end, and just one space b2in words)
		{
			write (1, &str[start], 1);
			start++;
		}
		// printf("\nlen before space %d\n", len);
		if (len > 0)										// "flag" in all the cases except for the first word, write spaces
			write (1, " ", 1);
		len = len - 1;										// decrease one position to the space (when restarting the loop again we - 1 and we skip the space)
		// printf("\nlen at end %d\n", len);
	}
}

int	main(int argc, char **argv)
{
	int len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		ft_rev_wstr(argv[1], len);
	}
	write (1, "\n", 1);
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