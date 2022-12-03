/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:49:46 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/03 17:46:37 by alejarod         ###   ########.fr       */
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
		// first case in case no spaces
		if (i == 0)
			str[i] = ft_toupper(str[i]);
		// check if first letter of word & convert
		if (ft_isspace(str[i - 1]) == 1)
			str[i] = ft_toupper(str[i]);
		// convert the rest to lower. Except in the first case!!
		else if (i != 0)
			str[i] = ft_tolower(str[i]);
		write(1, &str[i], 1);
	i++;
	}
	// it has to write a "\n" after each argument
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		// pass the arguments 1 by 1.
		while (i < argc)
		{
			ft_str_capitalizer(argv[i]);
			i++;
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}