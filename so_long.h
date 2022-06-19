/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 04:03:42 by hahn              #+#    #+#             */
/*   Updated: 2022/06/20 02:40:37 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_info
{
    void    *mlx;
    void    *win;
    void    *img_ply;
    void    *img_ext;
    void    *img_clt;
    void    *img_wal;
    void    *img_bcg;
    int     map_ply;
    int     map_clt;
    int     map_y;
    int     map_x;
    int     cur_ply;
    int     move_cnt;
    char    *map_info;

}   t_info;

char	*get_next_line(int fd);
int		gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, int c);
int 	game_exit(t_info *info);
void	mov_ply(t_info *info, int idx);
void	clear(t_info *info);
void	err_handler(char *msg);
void	map_init(t_info *info, char *map);
void	map_draw(t_info *info, void *mlx, void *win, char *map);

#endif
