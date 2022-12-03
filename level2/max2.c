/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:13:07 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/03 10:47:04 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	max(int* tab, unsigned int len)
{
	int max;
	unsigned int i;

	i = 0;
	max = 0;
	while (i < len)
	{
		// compare one to another && if the number is bigger than the last found number
		if (tab[i] > tab[i + 1] && tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/* int	main(void)
{
	int tab[5] = {100, 17, 2, 9, 600};
	int len = 5;
	int ret1 = max(tab, len);

	printf("max is: %d\n", ret1);
	return (0);
} */