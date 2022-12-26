/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:02:49 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/24 13:08:59 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char	*ft_strndup(char *str, int len)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char *) * len + 1);	// simple malloc and write a string
	if (!ptr)
		return (0);
	while (len >= 0)	// careful with len >=, len - 1 etc
	{
		ptr[len - 1] = str[len - 1];
		len--;
	}
	ptr[len] = '\0';	// finish the string with nul
	return (ptr);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')	// the subjects says "new lines" too
		return (1);
	return (0);
}

int	ft_wordcount(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (ft_is_space(str[i]) == 0 && (ft_is_space(str[i + 1]) == 1 || str[i + 1] == '\0'))	// as usual, count at the end of the word or string
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**ptr;
	int 	i = 0;
	int		word = 0;
	int 	wordcount;
	int		start = 0;

	if (str == 0)
		return (0);
	wordcount = ft_wordcount(str);
	ptr = (char **)malloc(sizeof(char *) * wordcount + 1);	// 1. count the words
	if (!ptr)
		return (0);
	while (str[i])									// 2. Loop all the words by moving the index. Similar to first_word and last_word
	{
		while (str[i] && ft_is_space(str[i]) == 1)	// loop spaces
			i++;
		start = i;									// save & fix the starting position
		while (str[i] && ft_is_space(str[i]) == 0)	// loop the index while there is a word, get the len of word
			i++;
		if (i > start)	// also (word < wordcount) or if (wordcount) and make it wordcount--;
		{
			ptr[word] = ft_strndup(str + start, i - start);	// 3. Save the words with strndup
			word++;
		}
		// i++ not necessary because I would skip one char
	}
	ptr[word] = '\0';
	return (ptr);
}

#include <stdio.h>
int main ()
{
	char s1[] = " hello	 over\n    		\t there \t";

	printf("\nsplit\n");
	char **s;
	s = ft_split(s1);
	int index = 0;
	while (s[index])
		printf("\n|%s|\n", s[index++]);
	return (0);
}




/* Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
 */