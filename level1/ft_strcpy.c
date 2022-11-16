/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:59:53 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/16 20:59:54 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

// check man strcpy

char	*ft_strcpy(char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/*int	main (void)
{
	char s2[] = "Hello";
	char s1[] = "";
	ft_strcpy(s1, s2);
	printf("s1 is %s\n", s1);
	return (0);
}*/
