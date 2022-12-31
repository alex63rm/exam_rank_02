/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:51:58 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/31 18:12:36 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_rotone(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'z')		// special case: 'z' to 'a'
			str[i] = 'a';
		else if (str[i] == 'Z')		// special case 'Z' to 'A'
			str[i] = 'A';
		else if (str[i] >= 'a' && str[i] <= 'y')		// ELSE if to avoid entering again
			str[i] = str[i] + 1;
		else if (str[i] >= 'A' && str[i] <= 'Y')
			str[i] = str[i] + 1;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rotone(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

/* Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$> */