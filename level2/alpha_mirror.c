/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:07:05 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/03 22:23:49 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_alpha_mirror(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'a' + 'z' - str[i];
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'A' + 'Z' - str[i];
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_alpha_mirror(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}