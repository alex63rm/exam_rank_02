/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:21:35 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/03 22:00:44 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_rot_13(char *str)
{
	unsigned int i;

	i = 0;
	while(str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
			str[i] = str[i] + 13;
		else if ((str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z')) // cuidado con else if!! sino, me entra el anterior en este
			str[i] = str[i] - 13;
		write(1, &str[i], 1);
	i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rot_13(argv[1]);
	}
	write (1, "\n", 1);
	return(0);
}