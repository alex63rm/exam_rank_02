/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:41:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/21 21:39:24 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int start, int end)
{
	int	*ptr;
	int	size;
	int	i;
	
	size = (end - start) + 1;
	ptr = (int *)malloc(sizeof(int) * size);
	if (!ptr)
		return (0);
	i = 0;
	while (end >= start)
	{
		ptr[i] = start;
		start++;
		i++;
	}
	return (ptr);
}

/* int	main(void)
{
	int start = 5;
	int end = 7;
	int	*r;
	r = ft_range(start, end);
	printf("%i %i %i\n", r[0], r[1], r[2]);
	free(r);
	
	return (0);
} */