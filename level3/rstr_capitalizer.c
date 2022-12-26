/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:17:07 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 18:53:15 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

/* int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))	// careful with && and ||
		return (1);
	return (0);
} */

int	ft_isspace(int c)
{
	if (c == '\t' || c == 32)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

void	ft_rstr_capitalizer(char *str)
{
	// printf("%s\n", str); check if we are receiving the parameters in order and all of them
	int i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0 && (ft_isspace(str[i + 1]) == 1 || str[i + 1] == '\0'))	// same as wordcount
			str[i] = ft_toupper(str[i]);
		else
			str[i] = ft_tolower(str[i]);	// else. turn it to lower
		write(1, &str[i], 1);	// write the str[i] converted
		i++;
	}
	write(1, "\n", 1);	// \n after each argument
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		while (i < argc)
		{
			ft_rstr_capitalizer(argv[i]);	// loop arguments from the beginning
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

/* Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character of each word (if it's a letter) in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
premieR petiT tesT$
$> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
deuxiemE tesT uN peU moinS  facilE$
   attentioN c'esT paS duR quanD memE$
alleR uN dernieR 0123456789pouR lA routE    E $
$>
 */