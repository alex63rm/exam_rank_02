/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:54:36 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 11:18:32 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_wordcount(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) == 0 && (ft_is_space(str[i + 1]) == 1 || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_expand_str(char *str)
{
	int wordcount;
	int i = 0;
	wordcount = ft_wordcount(str);
	if (wordcount == 0)		// control special case: if no words, write \n
	{
		write(1, "\n", 1);
		return ;
	}
	while (wordcount)
	{
		// loop spaces
		while (str[i] && ft_is_space(str[i]) == 1)
			i++;
		// loop letters to write
		while (str[i] && ft_is_space(str[i]) == 0)
		{
			write(1, &str[i], 1);
			i++;
		}
		// write spaces after words (except last one). In this case, 3 spaces
		if (wordcount > 1)
		{
			write (1, "   ", 3);
		}
	wordcount--;
	}
	write (1, "\n", 1);		// write it at the end
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_expand_str(argv[1]);
	}
	else
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