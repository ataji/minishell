/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:20:25 by ataji             #+#    #+#             */
/*   Updated: 2022/11/18 21:20:54 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

static char	**my_freeing(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	**set_words(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = ft_malloc((count_words(s, c) + 1) * sizeof(char *));
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j != 0)
			tab[k++] = my_substr(s, i, j);
		if (j != 0 && !tab[k - 1])
			return (my_freeing(tab));
		i = i + j;
	}
	tab[k] = NULL;
	return (tab);
}

char	**my_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = set_words((char *)s, c);
	return (tab);
}
