/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:41:25 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/23 20:17:47 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = 0;
	if (len <= 0)
		return (0);
	while (i <= len)
	{
		if (tab[i] > max)
				max = tab[i];
		i++;
	}
	return (max);
}

/* int	main(void)
{
	int	ret1;
	int tab[] = {1, -5, 7, 9, -18, 2, 9};
	
	ret1 = max(tab, 7);
	printf("max is: %d\n", ret1);
	return (0);
} */