/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:04:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/26 15:17:36 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	
	if (argc == 2)
	{
		i = 0;
		// ft_strlen
		while (argv[1][i])
			i++;
		// start 1 before to avoid the null
		i = i - 1;
		// start printing from the end
		while (i >= 0)
		{
			write(1, &argv[1][i], 1);
			i--;
		}
	}
	write (1, "\n", 1);
	return (0);
}