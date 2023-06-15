/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:06:16 by Leo               #+#    #+#             */
/*   Updated: 2023/06/15 14:08:29 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_texture
{
	char	*xpm_path;
	void	*texture;
	char	*texture_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width_img;
	int		height_img;
	int		texture_id;
	double	texture_x;
	double	texture_y;
	double	ratio;
}	t_texture;

typedef struct s_texture_info
{
	t_texture	*north_texture;
	t_texture	*south_texture;
	t_texture	*east_texture;
	t_texture	*west_texture;
}	t_texture_info;

typedef struct s_ray
{
	t_texture	*texture;
	float		a_tan;
	float		x;
	float		y;
	float		x_offset;
	float		y_offset;
	int			map_x;
	int			map_y;
	int			depth_of_field;
	float		traveled_distance;
}	t_ray;

typedef struct s_raycast
{
	int			ray_count;
	double		ray_angle;
	int			map_x;
	int			map_y;
	int			map_position;
	t_ray		horizontal_ray;
	t_ray		vertical_ray;
	t_ray		*winning_ray;
}	t_raycast;

typedef struct s_game
{
	int				fd;
	char			*fd_str;
	void			*img;
	char			*addr;
	void			*mlx;
	void			*mlx_win;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				window_width;
	int				window_height;
	float			x;
	float			y;
	double			player_delta_x;
	double			player_delta_y;
	double			player_angle;
	int				**game_tab;
	int				game_tab_width;
	int				game_tab_height;
	int				game_tab_max_encountred_cell;
	int				game_cell_size;
	int				speed;
	int				movement_tab[6];
	int				floor_color[3];
	int				ceiling_color[3];
	t_raycast		*raycast;
	t_texture_info	*all_textures;
}	t_game;

typedef struct s_vector2d
{
	int	x;
	int	y;
}	t_vector2d;

//EXECUTION
void				main_execution(char *map);
void				game_init(char *map_path, t_game *game);
t_texture_info		*init_all_textures(void);
int					handler_key_press(int keycode, t_game *game);
int					handler_key_release(int keycode, t_game *game);
int					handler_close_mlx(t_game *game);
void				player_movements(t_game *game);
int					is_wall(t_game *game, float x, float y);
void				print_floor_and_ceiling(t_game *game);
unsigned long		rgb_to_hexa(int color[3]);
void				raycasting(t_game *game);
double				assure_360_deg_angle(double a);
void				player_rotate_right(t_game *game);
void				player_rotate_left(t_game *game);
void				draw_walls(t_game *game, t_raycast *raycast, t_ray *ray, int x);
void				set_texture_x_coordonates(t_ray *ray);
int					get_texture_pixel(t_texture *texture, int x, int y);
double				get_traveled_ray_distance(float ax, float ay, float bx, float by);
void				raycasting_horizontal_looking_up(t_game *game, t_ray *ray);
void				raycasting_horizontal_looking_down(t_game *game, t_ray *ray);
void				raycasting_looking_straight(t_game *game, t_ray *ray);
void				raycasting_vertical_looking_right(t_game *game, t_ray *ray);
void				raycasting_vertical_looking_left(t_game *game, t_ray *ray);

//UTILS
int					clear_textures(t_game *game);
int					free_map(int **map, int n);
void				free_game(t_game *game);
void				ft_err_map(char *str, void *ptr, t_game *game);
void				stop_mlx(t_game *game);
void				free_and_exit_game(t_game *game, int exit_ret);
char				*ft_free_strjoin(char *s1, char *s2);
void				my_mlx_pixel_put(t_game *game, int x, int y, int color);
int					is_in_map_limits(t_game *game, int x, int y);
int					ft_intlen(int n);

#endif