/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:41:25 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 19:52:22 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = 0;				// fix a reference number to 0. Like a temp value for storing the maximum value.
	while (i < len)
	{
		if (tab[i] > max)	// just compare every position to max. If bigger, replace it
			max = tab[i];
		i++;
	}
	return (max);			// return the biggest number found
}

/* int	main(void)
{
	int	ret1;
	int tab[] = {1000, -5, 7, 9, -18, 2, 900};

	ret1 = max(tab, 7);
	printf("max is: %d\n", ret1);
	return (0);
} */

/* Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
 */

// APPROACH: Copy to max if we find a higher number

//			max = |	 0	|

//	   i = 0				  len-1
//	|	7	|	5	|	23	|	10	|
//    tab[i]