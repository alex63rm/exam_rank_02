/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:53:18 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 20:06:31 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 7;					// this loop is NOT a string. Numbers are counted from RIGHT TO LEFT.
	unsigned char bit;			// apparently the type does not matter

	while (i >= 0)				// loop the 8 positions (from 7 to 0)
	{
		bit = octet >> i;		// bring the most significant bit to the position of - - - - - - - 0
		bit = bit & 1;			// compare biwise opeator with number 1 (0 0 0 0 0 0 0 1)
		bit = bit + 48;			// convert to char, and start writing the string.
		write (1, &bit, 1);
		i--;
	}
}

int	main(void)
{
	int n = 2;
	print_bits(n);
	return (0);
}

/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
 */

//APPROACH

// number 2:
//	0	0	0	0	0	0	1	0
// [7] [6] [5] [4]............ [0]

// move i times (octet >> i)----> 0
// compare with & and only write if we brought a 1
// number 1
//	0	0	0	0	0	0	0	1
// convert to char with + 48
// write