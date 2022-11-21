/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:34:47 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/21 21:30:10 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				//argv[1][i] = ('m' + 'n') - argv[1][i];
				argv[1][i] = 'a' - argv[1][i] + 'z';
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = ('M' + 'N') - argv[1][i];
			write (1, &argv[1][i], 1);
		i++; 
		}
	}
	write (1, "\n", 1);
	return (0);
}