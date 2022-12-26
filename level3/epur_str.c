/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:52:14 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 11:17:45 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return(0);
}

int	ft_wordcount(char *str)
{
	int i = 0;
	int nb_words = 0;

	while (str[i])
	{
		// count a word at the end of the word (next one is space or '\0')
		if ((ft_isspace(str[i])) == 0 && (ft_isspace(str[i + 1]) == 1 || str[i + 1] == '\0'))
			nb_words++;
		i++;
	}
	return (nb_words);
}

void	ft_epur_str(char *str)
{
	int	i;
	int wordcount;

	i = 0;
	wordcount = ft_wordcount(str);	//count the words to use it as a counter
	while (wordcount)
	{
		// loop spaces
		while (str[i] && ft_isspace(str[i]) == 1)	// in all the loops put str[i] != '\0' otherwise we get overflow
			i++;
		// loop writing while no spaces
		while (str[i] && ft_isspace(str[i]) == 0)
		{
			write(1, &str[i], 1);
			i++;
		}
		// write spaces after writing the word (except in the last one)
		if (wordcount > 1)	// when there is only one word (last word), don't write a space after it
			write(1, " ", 1);
		wordcount--;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_epur_str(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

/* Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$> */