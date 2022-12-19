/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:34:18 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/19 23:14:42 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ft_ulstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')	// if lower, convert to upper
			str[i] = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')	// important ELSE IF to avoid entering again
			str[i] = str[i] + 32;
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	unsigned int	i;

	i = 0;
	if (argc == 2)
	{
		ft_ulstr(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}