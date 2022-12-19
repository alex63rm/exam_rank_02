/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:38:53 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/20 00:36:13 by alejarod         ###   ########.fr       */
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
		n = n * -1;		// don't forget to make it positive!!
	}
	while(n > 0)
	{
		ptr[n_len - 1] = "01234567890ABCDEF"[n % base];	// itoa base es lo mismo que itoa salvo esto!!!
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

	n_len = ft_int_len(value, base);
 	ptr = (char *)malloc(sizeof(char) * n_len + 1);
	if (!ptr)
		return (0);
	ptr = ft_save_nbr(value, ptr, base, n_len);
	ptr[n_len] = '\0';
	return (ptr);

	return("hello");
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