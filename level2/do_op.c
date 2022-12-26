/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:38 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 13:19:51 by alejarod         ###   ########.fr       */
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
	printf("%i\n", result);		// take care with the \n in printf, to avoid duplicating it
	return ;
}

// FOR SOME REASON IT DOES NOT DETECT THE ARGS WITHOUT QUOTES, but we don't have to control it
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		ft_do_op(argv[1], argv[2][0], argv[3]);			// return to exit so that the the write is not executed
		return (0);
	}
	// for some reason it does not work with an else here
	write (1, "\n", 1);
	return (0);
}

/* Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
 */