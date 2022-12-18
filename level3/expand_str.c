/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:54:36 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/17 21:34:55 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_wordcount(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) == 0 && (ft_is_space(str[i + 1]) == 1 || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_expand_str(char *str)
{
	int wordcount;
	int i = 0;
	wordcount = ft_wordcount(str);
	if (wordcount == 0)		// control special case: if no words, write \n
	{
		write(1, "\n", 1);
		return ;
	}
	while (wordcount)
	{
		// loop spaces
		while (str[i] && ft_is_space(str[i]) == 1)
			i++;
		// loop letters to write
		while (str[i] && ft_is_space(str[i]) == 0)
		{
			write(1, &str[i], 1);
			i++;
		}
		// write spaces after words (except last one). In this case, 3 spaces
		if (wordcount > 1)
		{
			write (1, "   ", 3);
		}
	wordcount--;
	}
	write (1, "\n", 1);		// write it at the end
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_expand_str(argv[1]);
	}
	else
		write(1, "\n", 1);
	return (0);
}