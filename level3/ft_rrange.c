/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:56:59 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/08 17:26:00 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	*ft_rrange(int start, int end)			// Same logic as ft_range
{
	int	*ptr;
	int	size;
	int	i;

	if (start == end)	// if 0, skip and return 0
		return (0);
	if (end >= start)
	{
		size = end - start;
		ptr = (int *)malloc(sizeof(int) * size);
		if (!ptr)
			return (0);
		i = 0;
		while (end >= start)	// it will return size positions
		{
			ptr[i] = end;
			//printf("%i ", ptr[i]);
			end--;
			i++;
		}		// no need to add teh nul because it is an INT pointer, it will stop in len
		return (ptr);
	}
	else if (start >= end)
	{
		size = start - end;
		ptr = (int *)malloc(sizeof(int) * size);
		if (!ptr)
			return (0);
		i = 0;
		while (start >= end)	// it will return size positions
		{
			ptr[i] = end;
			//printf("%i ", ptr[i]);
			end++;
			i++;
		}
		return (ptr);
	}
	return (0);
}

int	main(void)
{
	int start = 1;
	int end = 3;

	ft_rrange(start, end);

	return (0);
}

/* Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
 */