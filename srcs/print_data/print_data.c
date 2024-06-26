/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:54:57 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/27 14:57:35 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_list(t_list *list)
{
	while (list)
	{
		if (!ft_strncmp(list->line, "\n", 2))
			printf("%s$", list->line);
		else
			printf("%s$\n", list->line);
		list = list->next;
	}
}

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], "\n", 2))
			printf("%s", tab[i]);
		else
			printf("%s\n", tab[i]);
	}
}

void	print_map(t_map *map)
{
	printf("LISTS :\n\n");
	printf("text_list :\n");
	print_list(map->text_list);
	printf("\n");
	printf("color_list :\n");
	print_list(map->color_list);
	printf("\n");
	printf("map_list :\n");
	print_list(map->map_list);
	printf("\n");
	printf("TABS :\n\n");
	printf("text_tab :\n");
	print_tab(map->text_tab);
	printf("\n");
	printf("color_tab :\n");
	print_tab(map->color_tab);
	printf("\n");
	printf("map_tab :\n");
	print_tab(map->map_tab);
}

void	print_data(t_data *data)
{
	printf("Data :\n\n");
	print_map(data->map);
}
