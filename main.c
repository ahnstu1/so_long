/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:40:03 by hahn              #+#    #+#             */
/*   Updated: 2022/06/18 04:55:31 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	move_pos(t_info *info ,int idx)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = info -> mlx;
	win = info -> win;
	info -> move_cnt++;
	printf("\n cnt : %d", info -> move_cnt);
	info -> map_info[info -> cur_ply] = '0';
	info -> cur_ply = idx;
	x = info -> cur_ply % (info -> map_x + 1);
	y = info -> cur_ply / (info -> map_x + 1);
	printf("\n m_p idx : %d x : %d y : %d tile : %c\n", idx, x, y, info -> map_info[idx]);
	if (info -> map_info[idx] == 'C')
	{
		info -> map_clt--;
		mlx_put_image_to_window(mlx, win, info -> img_ply, x * 64,  y * 64);
	}
	else if (info -> map_info[idx] == '0')
		mlx_put_image_to_window(mlx, win, info -> img_ply, x * 64,  y * 64);
	info -> map_info[info -> cur_ply] = 'P';
}
void	clear(t_info *info)
{
	printf("Clear. Your steps : %d\n",  ++info -> move_cnt);
	exit(0);
}
void	move_north(t_info *info)
{
	char	north;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		idx;

	mlx = info -> mlx;
	win = info -> win;
	idx = info -> cur_ply - info -> map_x - 1;
	north = info -> map_info[idx];
	printf("\n north : %c idx : %d\n", north, info -> cur_ply - info -> map_x - 1);
	x = info -> cur_ply % (info -> map_x + 1);
	y = info -> cur_ply / (info -> map_x + 1);
	printf("\n cur_ply : %d x : %d y : %d\n",info -> cur_ply, x, y);
	if (north == 'E' && !info -> map_clt)
		clear(info);
	else if (north == '0' || north == 'C')
	{
		move_pos(info, idx);
		mlx_put_image_to_window(mlx, win, info -> img_bcg, x * 64,  y * 64);	
	}
}

void	move_east(t_info *info)
{
	char	east;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		idx;

	mlx = info -> mlx;
	win = info -> win;
	idx = info -> cur_ply + 1;
	east = info -> map_info[idx];
	printf("\n east : %c idx : %d\n", east, idx);
	x = info -> cur_ply % (info -> map_x + 1);
	y = info -> cur_ply / (info -> map_x + 1);
	printf("\n cur_ply : %d x : %d y : %d\n",info -> cur_ply, x, y);
	if (east == 'E' && !info -> map_clt)
		clear(info);
	else if (east == '0' || east == 'C')
	{
		move_pos(info, idx);
		mlx_put_image_to_window(mlx, win, info -> img_bcg, x * 64,  y * 64);	
	}
}

void	move_south(t_info *info)
{
	char	south;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		idx;

	mlx = info -> mlx;
	win = info -> win;
	idx = info -> cur_ply + info -> map_x + 1;
	south = info -> map_info[idx];
	printf("\n south : %c idx : %d\n", south, idx);
	x = info -> cur_ply % (info -> map_x + 1);
	y = info -> cur_ply / (info -> map_x + 1);
	printf("\n cur_ply : %d x : %d y : %d\n",info -> cur_ply, x, y);
	if (south == 'E' && !info -> map_clt)
		clear(info);
	else if (south == '0' || south == 'C')
	{
		move_pos(info, idx);
		mlx_put_image_to_window(mlx, win, info -> img_bcg, x * 64,  y * 64);	
	}
}

void	move_west(t_info *info)
{
	char	west;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		idx;

	mlx = info -> mlx;
	win = info -> win;
	idx = info -> cur_ply - 1;
	west = info -> map_info[idx];
	printf("\n west : %c idx : %d\n", west, idx);
	x = info -> cur_ply % (info -> map_x + 1);
	y = info -> cur_ply / (info -> map_x + 1);
	printf("\n cur_ply : %d x : %d y : %d\n",info -> cur_ply, x, y);
	if (west == 'E' && !info -> map_clt)
		clear(info);
	else if (west == '0' || west == 'C')
	{
		move_pos(info, idx);
		mlx_put_image_to_window(mlx, win, info -> img_bcg, x * 64,  y * 64);	
	}
}

int	game_exit(t_info *info)
{
	mlx_destroy_window(info -> mlx, info -> win);
	printf("\ntest game_exit\n");
	exit(0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 13)
		move_north(info);
	else if (keycode == 0)
		move_west(info);
	else if (keycode == 1)
		move_south(info);
	else if (keycode == 2)
		move_east(info);
	else if (keycode == 53)
		game_exit(info);
	return (0);
}

void	err_handler(char *msg)
{
	perror("Error\n");
	perror(msg);
	exit(1);
}

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
			if (map[idx + 1] != '1' || map[idx - 1] != '1')
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
	printf("ply : %d clt : %d ext : %d", info -> map_ply, info -> map_clt, ext);
	if (info -> map_ply != 1 || info -> map_clt == 0 || ext == 0)
		err_handler("incorrect map format");
}

void	map_draw(t_info *info)
{
	int		x;
	int		y;
	int		idx;
	char	*map;

	y = -1;
	idx = -1;
	map = info -> map_info;
	while (map[++idx] && ++y > -1)
	{
		x = -1;
		while (map[idx] != '\n' && map[idx] && ++x > -1)
		{
			if (map[idx] == '1')
				mlx_put_image_to_window(info -> mlx, info -> win, info -> img_wal, x * 64,  y * 64);
			if (map[idx] == 'C')
				mlx_put_image_to_window(info -> mlx, info -> win, info -> img_clt, x * 64,  y * 64);
			if (map[idx] == 'P')
				mlx_put_image_to_window(info -> mlx, info -> win, info -> img_ply, x * 64,  y * 64);
			if (map[idx] == 'E')
				mlx_put_image_to_window(info -> mlx, info -> win, info -> img_ext, x * 64,  y * 64);
			if (map[idx++] == '0')
				mlx_put_image_to_window(info -> mlx, info -> win, info -> img_bcg, x * 64,  y * 64);
		}
	}
}

void	map_init(t_info *info, char *map)
{
	int		fd;

	if (ft_strlen(map) < 5 || ft_strlen(ft_strnstr(map, ".ber", ft_strlen(map))) != 4)
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

void	img_load(t_info * info)
{
	void	*mlx;
	int		x;
	int		y;

	mlx = info -> mlx;
	info -> img_ply = mlx_xpm_file_to_image(mlx, "./image/ply", &x, &y);
	info -> img_ext = mlx_xpm_file_to_image(mlx, "./image/ext", &x, &y);
	info -> img_clt = mlx_xpm_file_to_image(mlx, "./image/clt", &x, &y);
	info -> img_wal = mlx_xpm_file_to_image(mlx, "./image/wal", &x, &y);
	info -> img_bcg = mlx_xpm_file_to_image(mlx, "./image/bcg", &x, &y);	
}

void	img_init(t_info *info)
{
	int	map_x;
	int	map_y;

	map_x = info -> map_x * 64;
	map_y = info -> map_y * 64;
	info -> win = mlx_new_window(info -> mlx, map_x, map_y, "so_long");
	img_load(info);
}

int main(int argc, char **argv)
{
    t_info *info;
	
   if (argc != 2)
        err_handler("incorrect input\n");
	info = calloc(1, sizeof(t_info));
    info -> mlx = mlx_init();
	map_init(info, argv[1]);
	img_init(info);
	map_draw(info);
	mlx_hook(info -> win, 2, 0, &key_hook, info);
	mlx_hook(info -> win, 17, 0, &game_exit, info);
	mlx_loop(info -> mlx);
}

//gcc -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit main.c get_next_line.c get_next_line_utils.c
