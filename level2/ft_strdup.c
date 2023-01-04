/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:23:33 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/04 20:32:36 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int i = 0;
	char *ptr;
	int len = ft_strlen(src);

	ptr = (char *)malloc(sizeof(char) * len + 1);	// don't forget + 1 for the null
	if (!ptr)
		return (0);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';				// end in '\0'
	return (ptr);
}

/*
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	array_src[] = "hello";

	char	*ret1;
	char	*ret2;

	ret1 = ft_strdup(array_src);
	ret2 = strdup(array_src);

	printf("my result: %s\n", ret1);
	printf("or result: %s\n", ret2);

} */

/* Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
 */