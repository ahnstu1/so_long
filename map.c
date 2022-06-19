/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 02:31:32 by hahn              #+#    #+#             */
/*   Updated: 2022/06/20 02:54:37 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_read(t_info *info, int fd)
{
	char	*map;
	char	*line;
	char	*tmp;
	int		y;

	map = (char *)malloc(sizeof(char) * 1);
	map[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		info -> map_y++;
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
	}
	info -> map_x = (ft_strlen(map) + 1) / info -> map_y - 1;
	return (map);
}

void	map_wall_valid(char	*map, int map_x, int map_y)
{
	int	idx;
	int	y;

	idx = 0;
	y = 0;
	while (map[idx])
	{
		while (map[idx] != '\n' && map[idx])
		{
			if ((y == 0 || y == map_y - 1) && map[idx] != '1')
				err_handler("incorrect map format");
			idx++;
		}
		if ((idx - y) % map_x != 0)
			err_handler("incorrect map format");
		if (map[idx] == '\n')
		{
			if (!(map[idx + 1] == '1' || map[idx + 1] == '\0')
				|| map[idx - 1] != '1')
				err_handler("incorrect map format");
			idx++;
		}
		y++;
	}
}

void	map_valid(t_info *info)
{
	int		idx;
	int		ext;
	char	*map;

	idx = 0;
	ext = 0;
	map = info -> map_info;
	while (map[idx])
	{
		if (map[idx] == 'P')
		{
			info -> map_ply++;
			info -> cur_ply = idx;
		}
		if (map[idx] == 'C')
			info -> map_clt++;
		if (map[idx] == 'E')
			ext++;
		idx++;
	}
	map_wall_valid(map, info -> map_x, info -> map_y);
	if (info -> map_ply != 1 || info -> map_clt == 0 || ext == 0)
		err_handler("incorrect map format");
}

void	map_draw(t_info *info, void *mlx, void *win, char *map)
{
	int		x;
	int		y;
	int		idx;

	y = 0;
	idx = -1;
	while (map[++idx])
	{
		x = 0;
		while (map[idx] != '\n' && map[idx])
		{
			if (map[idx] == '1')
				mlx_put_image_to_window(mlx, win, info -> img_wal, x, y);
			if (map[idx] == 'C')
				mlx_put_image_to_window(mlx, win, info -> img_clt, x, y);
			if (map[idx] == 'P')
				mlx_put_image_to_window(mlx, win, info -> img_ply, x, y);
			if (map[idx] == 'E')
				mlx_put_image_to_window(mlx, win, info -> img_ext, x, y);
			if (map[idx++] == '0')
				mlx_put_image_to_window(mlx, win, info -> img_bcg, x, y);
			x += 64;
		}
		y += 64;
	}
}

void	map_init(t_info *info, char *map)
{
	int		fd;

	if (ft_strlen(map) < 5
		|| ft_strlen(ft_strnstr(map, ".ber", ft_strlen(map))) != 4)
		err_handler("file extension is not .ber\n");
	fd = open(map, O_RDONLY);
	info -> map_x = 0;
	info -> map_y = 0;
	if (fd == -1)
		err_handler("open fail\n");
	info -> map_info = map_read(info, fd);
	map_valid(info);
	close(fd);
}