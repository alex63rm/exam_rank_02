/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:46:10 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/03 20:49:17 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

char *ft_write_nbr(char *ptr, int n_len, long nbr)
{

	// a. if == 0 write a 0
	// b. if < 0, write the sign and convert to - to enter the loop
	// c. loop from the end, it is opposite, first write the number, then divid n = n / 10.


	if (nbr == 0)
		ptr[0] = '0';
	if (nbr < 0)
	{
		ptr[0] = '-';		// it has to be the first position
		nbr = nbr * -1;  // convert to + to enter the loop
	}
	while (nbr > 0)	// it is oposite to putnbr because I am writing from the end to 0. Like the write first and then the division
	{
		ptr[n_len - 1] = (nbr % 10) + 48; // start in n_len - 1
		nbr = nbr / 10;
		n_len--;
	}
	return (ptr);
}

int	ft_int_len(long n)    // pass LONG to avoid the special case, to be able to add the '-'.
{
	// a. if n == 0
	// b. if n < 0 advance and convert to enter loop
	// c. loop (n > base) to count the digits

	int n_len = 0;  //**diff
	if (n == 0)
		n_len++;
	if (n < 0)
	{
		n = n * - 1; // important to put this one, to enter the loop and count correctly the n_len
		n_len++;
	}
	while (n > 0)
	{
		n = n / 10;  // count the digits
		n_len++;
	}
	return (n_len);
}

char *ft_itoa(int nbr)
{
	char	*ptr;
	int		n_len;

	n_len = ft_int_len(nbr);		// 1. calculate the len of number
	ptr = (char *)malloc(sizeof(char) * n_len + 1);		// 2. malloc space
	if (!ptr)
		return (0);
	ptr = ft_write_nbr(ptr, n_len, nbr); // 3. write the number in ptr
	ptr[n_len] = '\0'; // end it in null. This cannot go inside because if we put ptr[n_len] = 0, when n_len = 0, it returns no string.
	return (ptr);
}

/* int	main(void)
{
	char *ret;
	int nbr = 21474; //-2147483648

	ret = ft_itoa(nbr);
	printf("char nbr is: %s\n", ret);

	return (0);
} */