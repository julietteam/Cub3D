/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 17:45:27 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	loop_hook(t_data *data)
{
	if (!data->window->running)
	{
		mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
		exit(0);
	}
	read_keys(data);
	update_timing_and_movement(data);
	perform_ray_casting(data);
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = NULL;
	if (check_args(argc, argv, envp))
		return (1);
	data = init_data(argv[1]);
	if (!data)
		return (1);
	//print_data(data);
	if (parsing(data->map))
		return (free_data(&data), 1);
	// start_the_game(data);
	init_player_position(data);
	hooks(data);
	mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
	free_data(&data);
	return (0);
}

//remove height and width from structure window and replace by macros
//ajouter in int a init_data pour le lancer en deux parties
