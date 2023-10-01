/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:51:00 by skunert           #+#    #+#             */
/*   Updated: 2023/03/27 15:27:31 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_split_words(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	*get_alloc_word(const char *s, char c)
{
	int		i;
	int		tmp;
	char	*str;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	tmp = i;
	i = 0;
	while (i < tmp)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_next_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] != '\0' && s[i] == c)
			{
				i++;
			}
			break ;
		}
		i++;
	}
	return ((char *)s + i);
}

static void	free_arr(char **arr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != NULL && i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		*curr_pos;
	char		**arr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (s[i] == c)
		curr_pos = get_next_word((char *)s, c);
	else
		curr_pos = (char *)s;
	arr = ft_calloc(check_split_words(s, c) + 1, sizeof(char *));
	if (arr == NULL)
		return (free(arr), NULL);
	while (i < check_split_words(s, c) && curr_pos != NULL)
	{
		arr[i] = get_alloc_word(curr_pos, c);
		if (arr[i] == NULL)
			return (free_arr(arr, i), NULL);
		curr_pos = get_next_word(curr_pos, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
