/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:26:05 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/11/10 19:06:57 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	skipquotes(char *line)
{
	int	i;

	i = 0;
	if (line[i] == CHR_S_QT)
		while (line[++i] && line[i] != CHR_S_QT)
			;
	else
		while (line[++i] && line[i] != CHR_D_QT)
			;
	if (line[i] == CHR_D_QT || line[i] == CHR_S_QT)
		i++;
	while (line[i] && !ft_strchr(STR_TKN_VALS, line[i]))
		i++;
	if (line[i] == CHR_S_QT || line[i] == CHR_D_QT)
		return (i + skipquotes(line + i));
	return (i);
}

int	skipword(char *line)
{
	int	i;

	i = 0;
	while (!ft_strchr(STR_TKN_VALS, line[i]))
		i++;
	if (line[i] == CHR_D_QT || line[i] == CHR_S_QT)
		i += skipquotes(line + i);
	return (i);
}

int	skiptkn(char *line)
{
	int	i;

	i = 0;
	if (line)
	{
		while (line[i] == CHR_SPC)
			i++;
		if (line[i] == CHR_D_QT || line[i] == CHR_S_QT)
			i += skipquotes(line + i);
		else if (line[i] == CHR_PIPE)
			return (++i);
		else if (line[i] == CHR_OUTR || line[i] == CHR_INR)
		{
			i++;
			if (line[i] == line[i - 1])
				return (++i);
			return (i);
		}
		else
			i += skipword(line + i);
	}
	return (i);
}

t_tok	*tokenizer(char *l)
{
	int		i;
	t_tok	*tkn;
	int		v;
	char	*t;

	tkn = NULL;
	i = 0;
	t = l;
	while (l[i])
	{
		while (t[i] == CHR_SPC)
			i++;
		if (t[i] == CHR_OUTR || t[i] == CHR_INR)
			v = add_tkn(&tkn, lstnew(getval(t + i, 0, skiptkn(t + i)), RED));
		else if (l[i] == CHR_PIPE)
			v = add_tkn(&tkn, lstnew(getval(t + i, 0, skiptkn(t + i)), PIPE));
		else if (l[i] == CHR_S_QT)
			v = add_tkn(&tkn, lstnew(getval(t + i, 0, skiptkn(t + i)), S_QTE));
		else if (l[i] == CHR_D_QT)
			v = add_tkn(&tkn, lstnew(getval(t + i, 0, skiptkn(t + i)), D_QTE));
		else
			v = add_tkn(&tkn, lstnew(getval(t + i, 0, skiptkn(t + i)), WORD));
		if (v)
			return (NULL);
		i += skiptkn(t + i);
	}
	return (tkn);
}

int	check_str(char *l)
{
	int	d_qte;
	int	s_qte;
	int	i;

	i = -1;
	d_qte = 0;
	s_qte = 0;
	while (l[++i])
	{
		if (l[i] == CHR_S_QT)
		{
			if (d_qte % 2 == 0)
				s_qte++;
		}
		else if (l[i] == CHR_D_QT)
			if (s_qte % 2 == 0)
				d_qte++;
	}
	return (!(d_qte % 2 == 0 && s_qte % 2 == 0));
}
