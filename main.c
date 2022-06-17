/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:40:03 by hahn              #+#    #+#             */
/*   Updated: 2022/06/18 00:07:38 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int game_exit(t_info *info)
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
	perror("Error\n");
	perror(msg);
	exit(1);
}

int		map_format_check(char *map)
{
	return (ft_strlen(map) > 4 && ft_strlen(ft_strnstr(map, ".ber", ft_strlen(map))) == 4);
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
		if(!line)
			break;
		info -> map_y++;
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
	}
	info -> map_x = (ft_strlen(map) + 1) / info -> map_y - 1;
	printf("\nmap_x : %d map_y : %d\n", info -> map_x, info -> map_y);
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
	while(map[idx])
	{
		if (map[idx] == 'P')
			info -> map_ply++;
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

void	map_init(t_info *info, char *map)
{
	int		fd;

	if (!map_format_check(map))
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

int main(int argc, char **argv)
{
    t_info *info;
	
   if (argc != 2)
        err_handler("incorrect input\n");
	info = calloc(1, sizeof(t_info));
    info -> mlx = mlx_init();
	map_init(info, argv[1]);
    info -> win = mlx_new_window(info -> mlx, 500, 500, "mlx 42");
	mlx_hook(info -> win, 2, 0, &key_hook, info);
	mlx_hook(info -> win, 17, 0, &game_exit, info);
	mlx_loop(info -> mlx);
}

//gcc -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit main.c get_next_line.c get_next_line_utils.c