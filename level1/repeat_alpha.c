/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:58:25 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/05 20:55:22 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_repeat_alpha(char *str)
{
	int	i = 0;
	int j = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')	// one loop for upper
		{
			j = str[i] - 'A' + 1;	// set j. Algorithm to calculate the number of reps. +1 to avoid 'a' - 'a' = 0
			while (j > 0)
			{
				write (1, &str[i], 1);
				j--;
			}
		}
		else if (str[i] >= 'a' && str[i] <= 'z')	// one loop for lower. Careful with else
		{
			j = str[i] - 'a' + 1;
			while (j > 0)
			{
				write (1, &str[i], 1);
				j--;
			}
		}
		else
			write(1, &str[i], 1);	// if no letters just write the char
	i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_repeat_alpha(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}

/* Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
 */