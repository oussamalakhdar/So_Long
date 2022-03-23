/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:47:22 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 10:16:57 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	taballocation(t_data *ptr)
{
	ptr->xtab = 0;
	ptr->ytab = 0;
	ptr->xtable = malloc(sizeof(int) * ptr->nbcollectible);
	if (!ptr->xtable)
	{
		perror("Table Allocation Failed!\n");
		exit(0);
	}
	ptr->ytable = malloc(sizeof(int) * ptr->nbcollectible);
	if (!ptr->ytable)
	{
		perror("Table Allocation Failed!\n");
		exit(0);
	}
}

void	checkxpm(t_data *ptr)
{
	if (!ptr->img1 || !ptr->img2 || !ptr->img3
		|| !ptr->img4 || !ptr->img5 || !ptr->img6)
	{
		perror("Allocation Failed!\n");
		exit(1);
	}	
}
