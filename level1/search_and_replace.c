/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:20:59 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/13 22:37:11 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_search_and_replace(char *str, int search, int replace)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == search)
			str[i] = replace;
		write (1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if(ft_strlen(argv[2]) != 1 || ft_strlen(argv[3]) != 1) // check that the 2 and 3 arguments are just 1 char
		{
			write(1, "\n", 1);
			return (0);
		}
		ft_search_and_replace(argv[1], argv[2][0], argv[3][0]);
	}
	write(1, "\n", 1);
	return (0);
}