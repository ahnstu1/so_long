/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 02:33:25 by hahn              #+#    #+#             */
/*   Updated: 2022/06/20 03:00:11 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_pos(t_info *info, int idx)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = info -> mlx;
	win = info -> win;
	info -> move_cnt++;
	info -> cur_ply = idx;
	x = info -> cur_ply % (info -> map_x + 1);
	y = info -> cur_ply / (info -> map_x + 1);
	if (info -> map_info[idx] == 'C')
		info -> map_clt--;
	if (info -> map_info[idx] == 'E')
		info -> map_info[idx] = 'E';
	else
		info -> map_info[idx] = '0';
	mlx_put_image_to_window(mlx, win, info -> img_ply, x * 64, y * 64);
}

void	mov_ply(t_info *info, int idx)
{
	char	pos;
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = info -> mlx;
	win = info -> win;
	pos = info -> map_info[idx];
	x = info -> cur_ply % (info -> map_x + 1);
	y = info -> cur_ply / (info -> map_x + 1);
	if (pos == 'E' && !info -> map_clt)
		clear(info);
	else if (pos != '1')
	{
		if (info -> map_info[info -> cur_ply] == 'E')
			mlx_put_image_to_window(mlx, win, info -> img_ext, x * 64, y * 64);
		else
			mlx_put_image_to_window(mlx, win, info -> img_bcg, x * 64, y * 64);
		mov_pos(info, idx);
	}
}
