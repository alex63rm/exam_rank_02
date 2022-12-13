/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:07:02 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/13 22:41:57 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_rev_print(char *str)
{
	int	len;

	len = ft_strlen(str);
	len = len - 1;		// start in - 1 strlen = 2 is str[0] and str[1]
	while (len >= 0)	// start printing from the end
	{
		write(1, &str[len], 1);
		len--;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev_print(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}