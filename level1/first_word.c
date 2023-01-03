/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:47:29 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/02 21:04:00 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);

}

void	ft_first_word(char *str)
{
	int i = 0;
	int start;
	int end;

	while (str[i] && ft_isspace(str[i]) == 1)	// loop initial spaces
		i++;
	start = i;									// save start of word position
	while (str[i] && ft_isspace(str[i]) == 0)	// loop chars
		i++;
	end = i;									// save end of word position
	while (start < end)							// loop writing the letters
	{
		write(1, &str[start], 1);
		start++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_first_word(argv[1]);
	}
	write(1, "\n", 1);
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