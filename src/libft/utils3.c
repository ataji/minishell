/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:06:22 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/11/18 11:02:35 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_isalpha(int c)
{
	return ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_nbrlen(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	else if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	put_miness(long int *v, char *_case)
{
	if (*v < 0)
	{
		*_case = '-';
		*v *= -1;
	}
}

char	*ft_itoa(int n)
{
	char		*itoa;
	long int	tmp;
	int			size;

	tmp = n;
	size = ft_nbrlen(tmp);
	itoa = ft_malloc(size + 1);
	itoa[size--] = '\0';
	if (n == 0)
		itoa[size] = '0';
	else
	{
		put_miness(&tmp, &itoa[0]);
		while (tmp != 0)
		{
			itoa[size--] = tmp % 10 + '0';
			tmp /= 10;
		}
	}
	return (itoa);
}
