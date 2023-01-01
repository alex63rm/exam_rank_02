/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:13:34 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/01 12:26:08 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned char	reverse_bits(unsigned char octet)	
{
	int		i = 7;
	char	num;

	num = 0;				// start it in 0
	while (i >= 0)
	{										// MIXTURE
		num = num * 2 + (octet % 2);		// similar to atoi (Instead of remainder str[i],remainder is octet % 2)
		octet = octet / 2;					// similar to itoa (make the number smaller by moving one position)
		i--;
	}
	return (num);
}

int	main(void)
{
	int n = 2;
	printf("%d\n", reverse_bits(n));
	return (0);
}

/*

0 0 0 0 0 0 1 0  == 2 and I need 0 1 0 0 0 0 0 0 = 64

num * 2, to move <----- through the powers of 2 to the left + (octet % 2), which is either 0 or 1

*/

/* Assignment name  : reverse_bits (reverse like a string)
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
 */
