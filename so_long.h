/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 04:03:42 by hahn              #+#    #+#             */
/*   Updated: 2022/06/16 05:23:27 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
int		gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, int c);

typedef struct s_info
{
    void    *mlx;
    void    *win;
    void    *img_ply;
    void    *img_ext;
    void    *img_clt;
    void    *img_wal;
    void    *img_bcg;
    int     map_y;
    int     map_x;

}   t_info;


#endif
