/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:32:58 by frajaona          #+#    #+#             */
/*   Updated: 2024/03/02 14:31:53 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_allocation(const char *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (--len >= 0)
		word[len] = s[len];
	return (word);
}

static void	ft_free(char **result, int count)
{
	int	i;

	if (result)
	{
		i = 0;
		while (i < count)
		{
			if (result[i])
			{
				free(result[i]);
				result[i] = NULL;
			}
			i++;
		}
		free(result);
	}
}

static void	ft_processus(char const *s, char c, char **result, int *i)
{
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[*i] = ft_allocation(s, c);
			if (!result[*i])
			{
				ft_free(result, *i);
				return ;
			}
			(*i)++;
			while (*s && *s != c)
				s++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_processus(s, c, result, &i);
	result[i] = NULL;
	return (result);
}
