/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:03:54 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/05 00:00:11 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void sort_int_tab(int *tab, unsigned int size)	// SEE DRAWING and DRAW to see the logic
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int temp;

	while (i < size)			// we don't need to check the last position, the value will be saved there
	{
		j = i;						// j will start from i (keeps the position), not from the beggining of j
		while (j < size)
		{
			if (tab[j] < tab[i])	// this is a ft_swap.
			{
				temp = tab[i];		// save the value before replacing
				tab[i] = tab[j];	// replace the value found
				tab[j] = temp;		// use the other place in the tab to save the number
			}
			j++;
		}
		printf("%d\n", tab[i]);
		i++;
	}
	return ;
}

/* int	main(void)
{
	int tab[] = {1, 2, 4, -4, 1};
	int size = 5;

	sort_int_tab(tab, size);
	return (0);
} */

/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
 */

/* LOGICAL APPROACH

It is a double loop. I need to check the number vs every position

| 3 | 1 | 6 | 2 | 0 |
i = 0
j = 0, 1, 2, ... , len


*/