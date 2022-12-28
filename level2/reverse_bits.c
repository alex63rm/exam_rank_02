/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:13:34 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 20:14:42 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 7;
	char	bit;

	bit = 0;				// start it in 0
	while (i >= 0)
	{										// MIXTURE
		bit = bit * 2 + (octet % 2);		// similar to itoa. Instead of str[i],, octet % 2
		octet = octet / 2;					// similar to atoi.
		i--;
	}
	return (bit);
}

int	main(void)
{
	int n = 2;
	printf("%d\n", reverse_bits(n));
	return (0);
}

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
