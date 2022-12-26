/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:36:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/26 16:59:06 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
} */

/* typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
}; */

#include"list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*tmp;		// as usual
	tmp = lst;

	int aux;

	while (lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)	// apply subject function. To this data and next data. If it returns 0, means a >= b and we need to sort
		{
			aux = lst->next->data;					// ft_swap
			lst->next->data = lst->data;
			lst->data = aux;
			lst = tmp;								// update the head or something like this??
		}
		else
			lst = lst->next;				// is like i++. If the numbers are already sorted, update value of lst with the next (in this case lst = lst->next)
	}
	lst = tmp;				// update the head before return
	return (lst);
}



