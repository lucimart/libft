/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:31 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/08 16:21:13 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c, size_t len)
{
	size_t	words;
	size_t	i;

	if (len == 0)
		return (0);
	words = 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

int	end_handler(int len, int end)
{
	int	ret;

	if ((end + 1) == len)
		ret = len;
	else
		ret = end;
	return (ret);
}

static void	split_aux(char **result, char *s, char c, size_t len)
{
	int		i;
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	i = 0;
	while (end < len)
	{
		if (s[end] == c || (end + 1) == len)
		{
			end = end_handler(len, end);
			result[i] = ft_substr(s, start, (end - start));
			if (!result[i])
				return ;
			i++;
			while (s[end] == c)
				end++;
			start = end;
		}
		else
			end++;
	}
	result[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	size_t	wcount;
	char	**result;
	char	tmp[1];
	char	*str;

	tmp[0] = c;
	str = ft_strtrim(s, tmp);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	wcount = count_words(str, c, len);
	result = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!result)
		return (NULL);
	split_aux(result, str, c, len);
	free(str);
	return (result);
}
