/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:48 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/19 20:16:46 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_isblank(int c)	// better int than char
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

void	ft_first_word(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && ft_isblank(str[i]) == 1) // loop initial spaces
		i++;
	while (str[i] && ft_isblank(str[i]) == 0) // loop and write letters. Stop at end of str, otherwise overflow if no spaces at the end
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

/* Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
 */