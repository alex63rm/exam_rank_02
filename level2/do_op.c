/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:43:44 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/01 12:04:27 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// atoi, printf, write
#include<stdio.h>
#include<stdlib.h>

void	ft_do_op(int n1, int c, int n3)
{
	int result;
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
	printf("%i", result);	// do not use putnbr (gives problems with negatives)
	return ;
}

int main(int argc, char **argv)
{
	int n1;
	int n3;
	if (argc == 4)
	{
		n1 = atoi(argv[1]);
		n3 = atoi(argv[3]);
		ft_do_op(n1, argv[2][0], n3);
	}
	printf("\n");
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