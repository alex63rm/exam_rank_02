/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:27:41 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/31 19:06:24 by alejarod         ###   ########.fr       */
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

void	ft_hidenp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int count = 0;

	if (ft_strlen(s1) == 0)	// subject: an empty s1 is always hidden
	{
		write(1, "1", 1);	// subject: empty s1 is always hidden in s2
		return ;
	}
	while (s1[i])	// loop s1
	{
		while (s2[j])		// loop s2 with its own counter. We do not reset j to 0 because we want to keep the pòsition
		{
			if (s1[i] == s2[j])
			{
				count++;	// if we find the letter, increase flag
				j++;		// jump to next position, because if the letters are repeated we are staying at the same place
				break;		// break the loop to continue with the next i.
			}
		j++;
		}
	i++;
	}
	if (count == ft_strlen(s1))	// condition to return 1, all the chars where found
		write(1, "1", 1);
	else
		write(1, "0", 1);
}


int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_hidenp(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}

// same as wdmatch. but return 1 or 0 instead of s1

/* Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$> */