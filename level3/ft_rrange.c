/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:56:59 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/19 14:44:34 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*ptr;
	int size;
	int	i;
	
	//ver dibujo
	size = end - start + 1;

	//creo que + 1 es opcional.....
	ptr = (int *)malloc(sizeof(int) * (size + 1));
	if(!ptr)
		return (0);
	i = 0;
	while(size > 0)
	{
		ptr[i] = end;
		end--;
		i++;
		size--;
	}
	return (ptr);
}