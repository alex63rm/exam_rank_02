/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:16:53 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/25 23:07:00 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

// number:
// 0 1 0 0 | 0 0 0 1

// octet >> 4
// 0 0 0 0 | 0 1 0 0
// octet << 4
// 0 0 0 1 | 0 0 0 0

// (octet >> 4 | octet << 4)
// v v v v | v v v v
// 0 0 0 1 | 0 1 0 0


/* Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 */