/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:34:18 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/11 19:21:36 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ft_ulstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')	// if lower, convert to upper
			str[i] = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')	// important ELSE IF to avoid entering again
			str[i] = str[i] + 32;
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	unsigned int	i;

	i = 0;
	if (argc == 2)
	{
		ft_ulstr(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}

/* Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka dni KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
 */