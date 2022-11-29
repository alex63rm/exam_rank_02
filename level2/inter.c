/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:41:41 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/29 19:04:14 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

// check if the char is found in s2
int	ft_found(int c, char *s2)
{
	unsigned int	i; // counter for s2

	i = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_not_written(int c, char *s1, unsigned int position)
{
	unsigned int	i; // counter for s2

	i = 0;
	// pass the position, otherwise it will always find the letter 
	while (s1[i] && i < position)
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}


void	ft_padinto(char *s1, char *s2)
{
	unsigned int	i; // counter for s1

	i = 0;
	// loop the s1 and in every char check 2 conditions: found and already written
	while (s1[i])
	{
		if (ft_found(s1[i], s2) == 1 && ft_not_written(s1[i], s1, i) == 0)
		{
			write (1, &s1[i], 1);
		}
	i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_padinto(argv[1], argv[2]);
	}
	write (1, "\n", 1);
	return (0);
}