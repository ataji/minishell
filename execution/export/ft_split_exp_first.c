/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_exp_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:56:34 by ataji             #+#    #+#             */
/*   Updated: 2022/11/18 10:51:03 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_freeing_exp_first(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	*get_var_name_exp_first(const char *s, int index)
{
	char	*var_name;
	int		i;

	var_name = malloc(index + 1);
	if (!var_name)
		ft_exit(1);
	i = 0;
	while (i < index)
	{
		var_name[i] = s[i];
		i++;
	}
	var_name[i] = '\0';
	return (var_name);
}

char	*get_var_value_exp_first(const char *s, int index)
{
	char	*var_value;
	int		j;

	var_value = malloc(ft_strlen_exp(s) - index + 1);
	if (!var_value)
		ft_exit(1);
	j = 0;
	while (s[index])
	{
		var_value[j] = s[index];
		index++;
		j++;
	}
	var_value[j] = '\0';
	return (var_value);
}

char	**set_words_exp_first(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = malloc(3 * sizeof(char *));
	if (!tab)
		ft_exit(1);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	tab[0] = get_var_name_exp_first(s, i);
	tab[1] = get_var_value_exp_first(s, i + 1);
	tab[2] = NULL;
	return (tab);
}

char	**ft_split_exp_first(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = set_words_exp_first((char *)s, c);
	return (tab);
}
