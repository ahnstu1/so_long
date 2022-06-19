/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 02:35:27 by hahn              #+#    #+#             */
/*   Updated: 2022/06/20 03:00:23 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear(t_info *info)
{
	printf("Clear. Your steps : %d\n", ++info -> move_cnt);
	mlx_destroy_window(info -> mlx, info -> win);
	exit(0);
}

int	game_exit(t_info *info)
{
	mlx_destroy_window(info -> mlx, info -> win);
	exit(0);
}

void	err_handler(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
