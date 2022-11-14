/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlendm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:38:23 by yataji            #+#    #+#             */
/*   Updated: 2022/10/18 03:40:18 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strlendm(char **tab)
{
    int i;

    i = 0;
    if (!tab)
        return (0);
    while (tab[i])
        i++;
    return (i);
}