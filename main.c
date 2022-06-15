/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:40:03 by hahn              #+#    #+#             */
/*   Updated: 2022/06/16 05:56:13 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	err_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

void move_north()
{
	printf("\ntest move_north\n");
}

void move_east()
{
	printf("\ntest move_east\n");
}

void move_south()
{
	printf("\ntest move_south\n");
}

void move_west()
{
	printf("\ntest move_west\n");
}

void game_exit(t_info *info)
{
	mlx_destroy_window(info -> mlx, info -> win);
	printf("\ntest game_exit\n");
	exit(0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 13)
		move_north();
	else if (keycode == 0)
		move_east();
	else if (keycode == 1)
		move_south();
	else if (keycode == 2)
		move_west();
	else if (keycode == 53)
		game_exit(info);
	return (0);
}

void	err_handler(char *msg)
{
	perror(msg);
	exit(1);
}

void	map_init(t_info *info, char *map)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		err_handler("fd Error\n");
	

	close(fd);
}

int main(int argc, char **argv)
{
    t_info *info;

    if (argc != 2)
        err_handler("Incorrect input Error\n");
	info = malloc(sizeof(t_info) * 1);
    info -> mlx = mlx_init();
	map_init(info, argv[1]);
    info -> win = mlx_new_window(info -> mlx, 500, 500, "mlx 42");
	mlx_hook(info -> win, 2, 0, &key_hook, info);
	mlx_loop(info -> mlx);
}
