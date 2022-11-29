/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:38 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/29 21:19:37 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


void	ft_do_op(char *s1, char c, char *s3)
{
	int	n1;
	int	n3;
	int result;

	n1 = atoi(s1);
	n3 = atoi(s3);

	if (c == '+')
		result = n1 + n3;
	else if (c == '-')
		result = n1 - n3;
	else if (c == '*')
		result = n1 * n3;
	else if (c == '/')
		result = n1 / n3;
	else if (c == '%')
		result = n1 % n3;
	printf("%i\n", result);
	return ;
}

// FOR SOME REASON IT DOES NOT DETECT THE ARGS WITHOUT QUOTES, but we don't have to control it
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		ft_do_op(argv[1], argv[2][0], argv[3]);
		// return to exit so that the the write is not executed
		return (0);
	}
	// for some reason it does not work with an else here
	write (1, "\n", 1);
	return (0);
}