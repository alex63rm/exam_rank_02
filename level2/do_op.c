/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:02:34 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/20 18:42:08 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	main(int argc, char **argv)
{
	int	number1;
	int	number2;
	
	if (argc == 4)
	{
		number1 = atoi(argv[1]);
		number2 = atoi(argv[3]);
		if(argv[2][0] == '+')
			printf("%i\n", number1 + number2);
		if(argv[2][0] == '-')
			printf("%i\n", number1 - number2);
		if(argv[2][0] == '*')
			printf("%i\n", number1 * number2);
		if(argv[2][0] == '/')
			printf("%i\n", number1 / number2);
		if(argv[2][0] == '%')
			printf("%i\n", number1 % number2);
	}
	else
		write(1, "\n", 1);
	return (0);
}