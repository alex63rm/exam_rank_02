/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:03:54 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/23 19:16:27 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void sort_int_tab(int *tab, unsigned int size)	// SEE DRAWING and DRAW to see the logic
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int temp;

	while (i < size - 1)			// we don't need to check the last position, the value will be saved there
	{
		j = i;						// j will start from i, not from the beggining
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
	i++;
	}
	return ;
}

int	main(void)
{
	int array[] = {3, 1, 5, 0};
	unsigned int size = 4;
	unsigned int i = 0;

	while (i < size)
	{
		printf("array before: %d\n", array[i]);
		i++;
	}
	
	i = 0;
	while (i < size)
	{
		sort_int_tab(array, size);
		printf("array after: %d\n", array[i]);
		i++;
	}
	return (0);
}

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