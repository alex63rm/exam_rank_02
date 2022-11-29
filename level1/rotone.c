/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:33:20 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/29 20:41:59 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	ft_convert_letter(char c)
{
	// if they are not letters, leave c as it is
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		// exit the function, otherwise A and a will get 1 more and be converted to B or b
		if (c == 'Z')
		{
			c = 'A';
			return (c);
		}
		if (c == 'z')
		{
			c = 'a';
			return (c);
		}
		else
			c = c + 1;
	}
	return (c);
}


void	ft_rotone(char *s1)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
	{
		s1[i] = ft_convert_letter(s1[i]);
		write (1, &s1[i], 1);
	i++;
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