/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:55:41 by ibenmain          #+#    #+#             */
/*   Updated: 2022/11/18 11:01:02 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_count(char *str, char d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != d)
		count = 1;
	else
		count = 0;
	while (str[i])
	{
		if (str[i] && str[i] == d && str[i + 1] != d && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_other_split(char *s, char c, int i, int j)
{
	char	**tab;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	tab = ft_malloc((ft_count(s, c) + 1) * sizeof(char *));
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > 0 && s[end -1] != c)
		{
			if (!tab[j - 1])
				return (NULL);
		}
	}
	return (tab[j] = NULL, tab);
}

char	**ft_splitnew(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = ft_other_split(s, c, i, j);
	return (tab);
}
