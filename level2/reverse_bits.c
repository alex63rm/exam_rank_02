/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:13:34 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/23 17:14:07 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int		count;

	res = 0;
	count = 8;
	while (count)
	{
		res = res * 2 + (unsigned char)(octet % 2);		// similar to itoa_base
		octet = octet / 2;
		count--;
	}
	printf("%d\n", res);
	return (res);
}

int	main(void)
{
	int n = 2;
	reverse_bits(n);
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
