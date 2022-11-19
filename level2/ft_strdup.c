/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:14:56 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/19 13:36:03 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
//#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if(!src)
		return (0);
	// don't forget + 1 for the null
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	// control the malloc
	if (!ptr)
		return (0);
	while (src[i])
		{
			ptr[i] = src[i];
			i++;
		}
	// finalize in '\0'
	ptr[i] = '\0';
	return (ptr);
}

/* int	main(void)
{
	char	array_src[] = "hello 1";

	char	*ret1;
	char	*ret2;

	ret1 = ft_strdup(array_src);
	ret2 = strdup(array_src);

	printf("my result: %s\n", ret1);
	printf("or result: %s\n", ret2);
	
} */