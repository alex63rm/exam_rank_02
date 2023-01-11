/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:43:35 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/11 20:29:53 by alejarod         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_wdmatch(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int	count = 0;

	while (s1[i])					// a double loop as usual
	{
		while (s2[j])				// the important thing in this one is to keep the position of j in the second string
		{
			if (s1[i] == s2[j])
			{
				count++;			// if they are equal, I count and break. I do not equal j = 0, I want to keep the position of j.
				j++;				// jump to next position, because if the letters are repeated we are staying at the same place
				break;				// !! break to continue with the next i in s1. If I don't break it will continue looping s2...
			}
		j++;
		}
	i++;
	}
	if (count == ft_strlen(s1))		// if it found all the chars (faya), write the string
		ft_putstr(s1);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}

/* Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
 */
