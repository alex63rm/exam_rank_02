/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:16:55 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/30 01:12:23 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_last_word(char *str)
{
	int len = ft_strlen(str);	// 1.calculate len
	int start = 0;
	int end = 0;

	len = len - 1;				// Before the LOOP. len = 7  --> len[0] to len[6]. So start from len - 1
	while (len >= 0 && ft_isspace(str[len]) == 1)	// 2.loop-remove the final spaces or tabs   <--- avoid overflow (len >= 0)
		len--;
	end = len;				// fix the end position of the word
	while (len >= 0 && ft_isspace(str[len]) == 0)
		len--;
	start = len + 1;	// len stopped in the next space (beginning of the word). I want to start printing after the space
	while (start <= end)	// // print the word
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
		ft_last_word(argv[1]);	// no need to check "if there are no words" the function will not print anything if there are no letters
	}
	write (1, "\n", 1);
	return (0);
}

// GRADEME OK!

/* Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
 */