/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:46:10 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/01 21:38:56 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void	ft_save_nbr(char *ptr, int n_len, long n)	// LONG n (to fit INT_MIN)
{
	// a. if == 0 save 0
	// b. if < 0, save the sign and convert to - to enter the loop
	// c. loop from the end, it is opposite, first write the number, then divid n = n / 10.

	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';		// it has to be the first position
		n = n * -1;  // convert to + to enter the loop
	}
	while (n > 0)	// it is oposite to putnbr because I am writing from the end to 0. Draw Larrain formula
	{
		ptr[n_len - 1] = (n % 10) + 48; // start in n_len - 1, correct order. If itoa_base: "01234567890ABCDEF"[n % base]
		n = n / 10;
		n_len--;
	}
}

int	ft_int_len(long n)    // // LONG n (to fit INT_MIN)
{
	// a. if n == 0 advance 1
	// b. if n < 0 advance 1 and convert to enter loop
	// c. loop (n > base) to count the digits

	int n_len = 0;
	if (n == 0)
		n_len++;
	if (n < 0)
	{
		n_len++;		// space for the '-' sign
		n = n * - 1; 	// to enter the next loop and count correctly the n_len
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
	ptr = (char *)malloc(sizeof(char) * n_len + 1);		// 2. malloc space + 1 for '\0'
	if (!ptr)
		return (0);
	ft_save_nbr(ptr, n_len, nbr); 	// 3. write the number in ptr
	ptr[n_len] = '\0'; 				// end it in null.
	return (ptr);
}

/* int	main(void)
{
	char *ret;
	int nbr = 500; //-2147483648	// check the INT_MAX and INT_MIN with the library <limits.h>

	ret = ft_itoa(nbr);
	printf("char nbr is: %s\n", ret);

	return (0);
} */

/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
 */