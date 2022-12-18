/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:52:09 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/14 23:32:40 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_is_written(char *s1, int c, int position)
{
	int i = 0;
	while(s1 && i < position)
	{
		if(s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s1[i])
	{
		if (ft_is_written(s1, s1[i], i) == 0)	// search if the letter is written in the first string
			write (1, &s1[i], 1);
		i++;
	}
	while(s2[j])
	{
		if ((ft_is_written(s1, s2[j], i) == 0) && (ft_is_written(s2, s2[j], j)) == 0) // search if the letter in s2 was written in the first and in the second string
			write (1, &s2[j], 1);
		j++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}