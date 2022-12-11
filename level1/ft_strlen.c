/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:03:58 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/11 16:20:41 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* int	main(void)
{
	char array[] = "hello";
	int i;
	int j;

	i = ft_strlen(array);
	printf("my result: %i\n", i);
	j = strlen(array);
	printf("or result: %i\n", j);
	return (0);

} */