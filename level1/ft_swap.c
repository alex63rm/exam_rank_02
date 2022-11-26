/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:06:50 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/26 16:22:47 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

void	ft_swap(int *a, int *b)
{
	int	aux;
	
	aux = *b;
	*b = *a;
	*a = aux;
}

/* int	main(void)
{
	int	a = 18;
	int	b = 25;

	printf("before: a is %i b is %i\n", a, b);
	ft_swap(&a, &b);
	printf("after: a is %i b is %i\n", a, b);
	return (0);
} */