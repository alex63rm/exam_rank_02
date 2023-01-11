/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:41:35 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/08 17:22:13 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	*ft_range(int start, int end)
{
	int	*ptr;						// 1. check if size == 0
	int	size;						// 2. case for start <= end
	int	i;							// 3. case for start >= end

	if (start == end)			// if size == 0, skip and return 0.
		return (0);
	if (end >= start)			// one case if start >= end, other for the other
	{
		size = end - start;
		ptr = (int *)malloc(sizeof(int) * size);	// no need + 1, int arrays don't end in NULL
		if (!ptr)
			return (0);
		i = 0;
		while (end >= start)	// it will return size positions
		{
			ptr[i] = start;
			//printf("%i ", ptr[i]);		// always better to check inside
			start++;
			i++;
		}		// no need to add the nul because it is an INT pointer, it will stop in len
		return (ptr);
	}
	else if (start >= end)				// important ELSE
	{
		size = start - end;
		ptr = (int *)malloc(sizeof(int) * size);
		if (!ptr)
			return (0);
		i = 0;
		while (start >= end)
		{
			ptr[i] = start;
			//printf("%i ", ptr[i]);
			start--;
			i++;
		}
		return (ptr);
	}
	return (0);
}

/* int	main(void)
{
	int start = 0;
	int end = -9;

	ft_range(start, end);

	return (0);
}
 */
/* Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
 */