/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:15:01 by youjeon           #+#    #+#             */
/*   Updated: 2023/11/12 16:27:28 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*chara;
	void	*generator;
	void	*land;
	void	*portal;
	void	*portal2;
	void	*wall;
}				t_img;

typedef struct s_check
{
	int	y;
	int	x;
	int	collectible;
	int	**visited;
}				t_check;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	int		player_x;
	int		player_y;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
	int		valid_path;
}				t_game;

/*
	utils.c
*/
char	*ft_strdup_without_newline(char *s);
int		ft_strlcpy_without_newline(char *dst, char *src, int len);
char	*ft_strjoin_without_newline(char *s1, char *s2);

/*
	image.c
*/
t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	setting_img(t_game *game);

/*
	map.c
*/
void	map_read(char *filename, t_game *game);
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
void	map_check_position(t_game *game);
void	map_check(t_game *game);
void	free_visited(int **visited);
int		**visited_init(t_game *game);
void	dfs(t_game *game, t_check *check, int y, int x);
void	init_check(t_game *game, t_check *check);
void	check_path(t_game *game);


/*
	key.c
*/
int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);

/*
	so_long.c
*/
void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif
