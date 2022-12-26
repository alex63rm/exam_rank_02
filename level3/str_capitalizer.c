/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:49:46 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 18:49:23 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

void	ft_str_capitalizer(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (i == 0)	// !!! special case for first position. Convert it, write it, advance, restart loop
		{
			str[i] = ft_toupper(str[i]);
			write(1, &str[i], 1);
			i++;
			//continue ;
		}
		if (ft_isspace(str[i]) == 0 && (ft_isspace(str[i - 1]) == 1))	// check if first letter of word. i is the char and I check if i-1 was space. Another way is
																		// if i is space and i+1 is not, in this case I should change str[i+1]
			str[i] = ft_toupper(str[i]);								// numbers and strange chars are already checked in toupper & tolower.
		else
			str[i] = ft_tolower(str[i]);	//else turn to lower
		write(1, &str[i], 1);	// write the str[i] converted
		i++;
	}
	write(1, "\n", 1);
}


int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		while (i < argc)	// pass the arguments 1 by 1. Check with printf
		{
			ft_str_capitalizer(argv[i]);
			i++;
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}

/* Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$> */