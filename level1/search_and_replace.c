/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:45:41 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/20 17:57:08 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	
	i = 0;
	if (argc == 4)
	{
		// check that the 2 and 3 arguments are just 1 char
		if(ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		{		
			while (argv[1][i])
			{
				if (argv[1][i] == argv[2][0])
					argv[1][i] = argv[3][0];
				write(1, &argv[1][i], 1);
			i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}