/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:40:03 by hahn              #+#    #+#             */
/*   Updated: 2022/06/20 03:04:06 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 13)
		mov_ply(info, info -> cur_ply - info -> map_x - 1);
	else if (keycode == 0)
		mov_ply(info, info -> cur_ply - 1);
	else if (keycode == 1)
		mov_ply(info, info -> cur_ply + info -> map_x + 1);
	else if (keycode == 2)
		mov_ply(info, info -> cur_ply + 1);
	else if (keycode == 53)
		game_exit(info);
	return (0);
}

void	img_init(t_info *info)
{
	int		map_x;
	int		map_y;
	void	*mlx;
	int		x;
	int		y;

	map_x = info -> map_x * 64;
	map_y = info -> map_y * 64;
	mlx = info -> mlx;
	info -> win = mlx_new_window(info -> mlx, map_x, map_y, "so_long");
	info -> img_ply = mlx_xpm_file_to_image(mlx, "./image/ply", &x, &y);
	info -> img_ext = mlx_xpm_file_to_image(mlx, "./image/ext", &x, &y);
	info -> img_clt = mlx_xpm_file_to_image(mlx, "./image/clt", &x, &y);
	info -> img_wal = mlx_xpm_file_to_image(mlx, "./image/wal", &x, &y);
	info -> img_bcg = mlx_xpm_file_to_image(mlx, "./image/bcg", &x, &y);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		err_handler("incorrect input\n");
	info = calloc(1, sizeof(t_info));
	info -> mlx = mlx_init();
	map_init(info, argv[1]);
	img_init(info);
	map_draw(info, info -> mlx, info -> win, info -> map_info);
	mlx_hook(info -> win, 2, 0, &key_hook, info);
	mlx_hook(info -> win, 17, 0, &game_exit, info);
	mlx_loop(info -> mlx);
}
