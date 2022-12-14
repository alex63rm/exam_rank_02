/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:40:47 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/28 21:22:17 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this one is given and we don't need to submit it

#ifndef LIST_H
# define LIST_H

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

#endif