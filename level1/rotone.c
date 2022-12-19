/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:33:20 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/19 23:05:41 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_rotone(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
			// if they are not letters, leave c as it is
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			if (str[i] == 'Z')	// special case is Z and z, manually we turn it into A or a
				str[i] = 'A';
			else if (str[i] == 'z')	// important else if to avoid entering againt
				str[i] = 'a';
			else
				str[i] = str[i] + 1;
		write (1, &str[i], 1);
		i++;
		}
	}
	return ;
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rotone(argv[1]);
	}
	write (1, "\n", 1);
}