/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:32:56 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:51 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_repeat_alpha(char *str)
{
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			j = str[i] - 'a' + 1;
			while (j > 0)
			{
				write(1, &str[i], 1);
				j--;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			j = str[i] - 'A' + 1;
			while (j > 0)
			{
				write(1, &str[i], 1);
				j--;
			}
		}
		else
			write(1, &str[i], 1);
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
	write(1, "\n", 1);
	return (0);
}