/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:52:23 by ataji             #+#    #+#             */
/*   Updated: 2022/11/16 09:17:57 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pwd_cmd(t_execlst *el)
{
	int		j;
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("error in pwd");
		return (1);
	}
	if (el->red && el->red->fd)
	{
		j = 0;
		while (cwd[j])
		{
			write (el->red->fd, &cwd[j], 1);
			j++;
		}
		write (el->red->fd, "\n", 1);
	}
	else
		printf("%s\n", cwd);
	return (1);
}
