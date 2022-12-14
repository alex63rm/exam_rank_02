/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:38:53 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 11:35:12 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char	*ft_save_nbr(long n, char *ptr, int base, int n_len)	// receive a LONG
{
	if (n == 0)
		ptr[0] = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * -1;		// don't forget to make it positive to enter next loop!!
	}
	while(n > 0)
	{
		ptr[n_len - 1] = "01234567890ABCDEF"[n % base];	// itoa base is the same except for this.
		n = n / base;									// itoa: n % 10 + 48, ahora en vez de + 48 xq no conozco la base hago eso
		n_len--;
	}
	return (ptr);
}

int	ft_int_len(long n, int base)	// receive a LONG
{
	int	n_len = 0;

	if (n == 0)
		n_len++;
	if (n < 0)
	{
		n_len++;
		n = n * -1; // to enter in the next section
	}
	while (n > 0)	// it is 0, not the base. In itoa it is == 0, < 0, > 0.
	{
		n = n / base;
		n_len++;
	}
	return (n_len);
}

char	*ft_itoa_base(int value, int base)	// better to write first this logic and then go to the secondary functions
{
	int	n_len;
	char *ptr;

	n_len = ft_int_len(value, base);	// calculate len of int
 	ptr = (char *)malloc(sizeof(char) * n_len + 1);		// allocate memory + 1
	if (!ptr)
		return (0);
	ptr = ft_save_nbr(value, ptr, base, n_len);		// start saving the string after converting
	ptr[n_len] = '\0';
	return (ptr);

	return(ptr);
}

int	main(void)
{
	int number = -2147483648;	//-2147483648
	int base = 2;
	char *ret1;

	ret1 = ft_itoa_base(number, base);
	printf("%s\n", ret1);
	return (0);
}

/* Assignment name  : ft_itoa_base
Expected files   : ft_itoa_base.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that converts an integer value to a null-terminated string
using the specified base and stores the result in a char array that you must
allocate.

The base is expressed as an integer, from 2 to 16. The characters comprising
the base are the digits from 0 to 9, followed by uppercase letter from A to F.

For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".

If base is 10 and value is negative, the resulting string is preceded with a
minus sign (-). With any other base, value is always considered unsigned.

Your function must be declared as follows:

char	*ft_itoa_base(int value, int base);
 */