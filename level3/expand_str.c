/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:17:38 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/05 21:43:03 by alejarod         ###   ########.fr       */
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

int	ft_wordcount(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0 && (ft_isspace(str[i+1]) == 1 || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_expand_str(char *str)
{
	int i = 0;
	int wordcount = ft_wordcount(str);
	while (str[i])				// also possible while wordcount
	{
		while (str[i] && ft_isspace(str[i]) == 1)	// loop spaces
			i++;
		while (str[i] && ft_isspace(str[i]) == 0)	// loop letters and write
		{
			write(1, &str[i], 1);
			i++;
		}
		if (wordcount > 1)			// write 3 spaces after words (except after the last one)
			write(1, "   ", 3);
		wordcount--;				// dont forget to decrerase wordcount
	}
	return ;
}


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_expand_str(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

/* Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
 */