/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:07:02 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/11 19:10:58 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_rev_print(char *str)
{
	int	len;

	len = ft_strlen(str);	// compute to start from the end
	len = len - 1;		// len - 1 before entering the loop. If start str[len-1], errors at len[0]
	while (len >= 0)	// start printing from the end
	{
		write(1, &str[len], 1);
		len--;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev_print(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}

/* Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
 */