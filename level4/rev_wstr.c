/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:04:15 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/11 22:01:36 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rev_wstr(char *str, int first)
{
	int	start;
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))	// loop to the start of the word (this is to avoid the space)
			i++;
		if (!str[i])	// if there is nothing, return
			return ;
		start = i;	// save the position where we will start writing
		while (str[i] && str[i] != ' ' && str[i] != '\t')	// loop to the end of the word (move i to the end)
			i++;
		rev_wstr(&str[i], 0);		// call the function recursively from the end of the word
		write(1, &str[start], i - start);		// write (recursion is opposite, from end to beggining), from start to end of word (i)
		if (!first)				// except for the first case, we will write a space
			write(1, " ", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		rev_wstr(argv[1], 1);   // special case for the first word (the last does not have a space at the end)
	}
	write(1, "\n", 1);
	return (0);
}