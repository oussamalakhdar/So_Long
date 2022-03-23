/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:31:51 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/22 21:38:06 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tableallocation(t_data *ptr)
{
	ptr->xtable = malloc(sizeof(int) * ptr->nbcollectible);
	if (!ptr->xtable)
	{
		perror("Allocation Failed!\n");
		exit(1);
	}
	ptr->ytable = malloc(sizeof(int) * ptr->nbcollectible);
	if (!ptr->ytable)
	{
		perror("Allocation Failed!\n");
		exit(1);
	}
}

void	checkxpm(t_data *ptr)
{
	if (!ptr->img1 || !ptr->img2 || !ptr->img3 || !ptr->img4 || !ptr->img5)
	{
		perror("Allocation Failed!\n");
		exit(1);
	}	
}
