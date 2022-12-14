/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:41:41 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/30 14:14:09 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_found(int c, char *s2)		// check if the char is found in s2
{
	int i = 0;		// counter for s2
	while (s2[i])
	{
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_not_written(int c, char *s1, unsigned int position)	// check if the letter is in s1 (means, was written)
{
	int i = 0;
	while (s1[i] && i < position)	// check only up to the current position, (otherwise it will always find the letter)
	{
		if (s1[i] == c)		// if it finds the letter, it means it has already been written
			return (1);
		i++;
	}
	return (0);
}

void	ft_padinto(char *s1, char *s2)
{
	int i = 0;			// counter for s1
	while (s1[i])		// loop the s1 and in every char check 2 conditions: found and already written
	{
		if (ft_found(s1[i], s2) == 1 && ft_not_written(s1[i], s1, i) == 0)
			write (1, &s1[i], 1);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_padinto(argv[1], argv[2]);
	}
	write (1, "\n", 1);
	return (0);
}

/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
 */