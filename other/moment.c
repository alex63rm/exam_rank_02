/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:26:55 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/24 17:14:07 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void			ft_strcat(char *str_pointer, char *str_number, char *str_letters)
{
	int i;	// counter for the numbers && the pointer
	int j;	// counter for the letters

	i = 0;
	while (str_number[i])	// write the number
	{
		str_pointer[i] = str_number[i];
		i++;
	}
	j = 0;
	while (str_letters[j])
	{
		str_pointer[i] = str_letters[j];	//continue from the position of i
		i++;
		j++;
	}
	str_pointer[i] = '\0';		// end the pointer in null (it does not get copied)
}

int				ft_intlen(int i)
{
	int j;

	j = 0;
	while (i)
	{
		j++;
		i /= 10;
	}
	return (j);
}

char			*ft_itoa(int i)
{
	long	num;
	int		container;
	char	*str;

	num = i;
	container = ft_intlen(i);
	str = (char *)malloc(sizeof(char) * container + 1);
	if (i == 0)
	{
		free(str);
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[container - 1] = '\0';
	container--;
	while(num)
	{
		str[container] = (num % 10 + '0');
		container--;
		num = num / 10;
	}
	return (str);
}

char			*moment(unsigned int duration)
{
	char	*number;
	int		i;
	char	*str;

	i = 0;
	if (duration >= 2592000)	//MONTHS. Max, months, no more fit in an int (60sec * 60min * 24 hours * 30days = 2592000)
	{
		if (duration / 2592000 == 1)	// special case is 1 (no plural)
		{
			str = (char *)malloc(sizeof(char) * 13);
			str = "1 month ago.\0";		// !! end the string in NUL so that it knows where to stop when strcat.
			return (str);
		}
		else
		{
			number = ft_itoa(duration / 2592000);	// convert the number to a char string
			str = (char *)malloc(sizeof(char) * 13 + ft_intlen(duration));	// make space for the string
			ft_strcat(str, number, " months ago.\0");		// concatenate the 2 strings (pass str to save it there)
		}
	}
	else if (duration >= 86400)
	{
		if (duration / 86400 == 1)
		{
			str = (char *)malloc(sizeof(char) * 11);
			str = "1 day ago.\0";
			return (str);
		}
		else
		{
			number = ft_itoa(duration / 86400);
			str = (char *)malloc(sizeof(char) * 11 + ft_intlen(duration));
			ft_strcat(str, number, " days ago.\0");
		}
	}
	else if (duration >= 3600)
	{
		if (duration / 3600 == 1)
		{
			str = (char *)malloc(sizeof(char) * 12);
			str = "1 hour ago.\0";
			return (str);
		}
		else
		{
			number = ft_itoa(duration / 3600);
			str = (char *)malloc(sizeof(char) * 12 + ft_intlen(duration));
			ft_strcat(str, number, " hours ago.\0");
		}
	}
	else if (duration >= 60)
	{
		if (duration / 60 == 1)
		{
			str = (char *)malloc(sizeof(char) * 14);
			str = "1 minute ago.\0";
			return (str);
		}
		else
		{
			number = ft_itoa(duration / 60);
			str = (char *)malloc(sizeof(char) * 14 + ft_intlen(duration));
			ft_strcat(str, number, " minutes ago.\0");
		}
	}
	else
	{
		if (duration == 1)
		{
			str = (char *)malloc(sizeof(char) * 14);
			str = "1 second ago.\0";
			return (str);
		}
		else
		{
			number = ft_itoa(duration);
			str = (char *)malloc(sizeof(char) * 14 + ft_intlen(duration));
			ft_strcat(str, number, " seconds ago.\0");
		}
	}
	return (str);
}

int	main(void)
{
	int seconds = 70;
	printf("%s\n", moment(seconds));
	return (0);
}