/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:14:53 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/24 16:12:49 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(*list))
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
	}
	*list = NULL;
}

void	free_lists(t_map *map)
{
	free_list(&(map->map_list));
	free_list(&(map->text_list));
	free_list(&(map->color_list));
}

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	if (!(*tab))
		return ;
	free(*tab);
	*tab = NULL;
}

void	free_tabs(t_map *map)
{
	free_tab(&map->color_tab);
	free_tab(&map->text_tab);
	free_tab(&map->map_tab);
}

void	free_map(t_map **map)
{
	if (!(*map))
		return ;
	free_lists(*map);
	free_tabs((*map));
	if ((*map)->north_texture)
		free((*map)->north_texture);
	if ((*map)->south_texture)
		free((*map)->south_texture);
	if ((*map)->west_texture)
		free((*map)->west_texture);
	if ((*map)->east_texture)
		free((*map)->east_texture);
	free(*map);
	*map = NULL;
}
