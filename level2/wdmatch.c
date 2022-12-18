/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:43:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/17 23:19:51 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_check_char(int c, char *s2, int position)
{

	int i = position;
	printf("initial position: %d\n", position);
	while (s2[i])
	{
		printf("position: %d  %c\n", position, s2[i]); //¿Como guardo la posicion para comprobar solamente desde ahí hasta el final?
		if (s2[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_wdmatch(char *s1, char *s2)
{
	int check = 0;
	int i = 0;

	while (s1[i])
	{
		check += ft_check_char(s1[i], s2, i);	//¿Por que no me coge bien el caso 2?
		printf("%d\n", check);
		i++;
	}
	if (check == ft_strlen(s1))
	{
		i = 0;
		while (s1[i])
		{
			write(1, &s1[i], 1);
			i++;
		}
	}
	return ;
}


int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}