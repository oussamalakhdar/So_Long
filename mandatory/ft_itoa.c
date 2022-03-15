/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:55:14 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/15 10:05:18 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_cmpt(long long n)
{
	long long	cmpt;

	cmpt = 0;
	while (n > 0)
	{
		n /= 10;
		cmpt++;
	}
	return (cmpt);
}

char	*ft_convert(char *str, long long nbr, int i, int j)
{
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		str = malloc (sizeof(char) * (1 + 1 + ft_cmpt(nbr)));
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		i++;
	}
	else
	{
		str = malloc (sizeof(char) * (1 + ft_cmpt(nbr)));
		if (str == NULL)
			return (NULL);
	}
	i = i + ft_cmpt(nbr);
	str[i] = '\0';
	j = i - 1;
	while (nbr > 0)
	{
		str[j] = (nbr % 10) + '0';
		nbr /= 10;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	int			j;
	char		*str;
	long long	nbr;

	nbr = n;
	i = 0;
	j = 0;
	str = NULL;
	if (nbr == 0)
	{
		str = malloc (sizeof(char) * (1 + 1));
		str[i] = 0 + '0';
		str [i + 1] = '\0';
		return (str);
	}
	str = ft_convert(str, nbr, i, j);
	return (str);
}
