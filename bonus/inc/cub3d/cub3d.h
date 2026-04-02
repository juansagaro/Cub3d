/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:31:47 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 18:18:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* cub3d.h                                                                  */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* --- LIBRERIAS --- */
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>

/* --- DEFINES: ERRORES Y MENSAJES --- */
# define ARGS      "cub3d error: you need two arguments\n"
# define USAGE     "cub3d error: You must use: ./cub3d maps/archive.cub\n"
# define CUB       "cub3d error: You must use a .cub extension\n"
# define NOT_FOUND "cub3d error: file not found\n"
# define NOT_OPEN  "Error opening file"
# define MLX_ERR   "Error in init mlx\n"

/* --- DEFINES: CONFIGURACION VENTANA --- */
# define WIN_W 1800
# define WIN_H 1000

/* --- DEFINES: INPUT (TECLAS) --- */
# define W 119
# define A 97
# define S 115
# define D 100
# define M 77
# define LEFT 65361
# define RIGHT 65363
# define MOUSE_L 1
# define ESC 65307

/* --- DEFINES: MATEMATICAS Y FISICA --- */
# define PI 3.14159265359
# define BLOCK 64
# define PLAYER_SPEED 0.12f
# define ROT_SPEED 0.1f
# define COLLIDE_R 0.2f
# define SENSI 0.0015f
# define GUN_SCALE 5

/* --- DEFINES: MINIMAPA --- */
# define MMAP_RADIUS 80
# define MMAP_CENTER_X 100
# define MMAP_CENTER_Y 100
# define MMAP_ZOOM 10
# define MMAP_COLOR_WALL 0x404040
# define MMAP_COLOR_FLOOR 0xC0C0C0
# define MMAP_COLOR_DOOR 0x0000FF
# define MMAP_COLOR_VOID 0x151515
# define MMAP_COLOR_PL 0xFF0000
# define MAX_MAP_LINES 1000

/* --- ESTRUCTURAS --- */

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_tex
{
	void	*img_ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_textures
{
	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;
	t_tex	floor;
	t_tex	ceiling;
	t_tex	door;
}	t_textures;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	char	orientation;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	key_rot_left;
	bool	key_rot_right;
}	t_player;

typedef struct s_parser
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor;
	char		*ceiling;
	char		*door;
	char		**map;
	char		**padded;
	t_player	*player;
	t_rgb		f;
	t_rgb		c;
	int			rows;
	int			cols;
	bool		no_set;
	bool		so_set;
	bool		we_set;
	bool		ea_set;
	bool		door_set;
	bool		door_in_map;
	bool		f_set;
	bool		c_set;
	bool		map_started;
	bool		map_finished;
	bool		player_set;
}	t_parser;

typedef struct s_weapon
{
	t_tex	frames[7];
	int		curr_frame;
	int		trigger_down;
	int		frame_timer;
}	t_weapon;

typedef struct s_rayfloor
{
	float	ray_x0;
	float	ray_y0;
	float	ray_x1;
	float	ray_y1;
	float	row_dist;
	float	step_x;
	float	step_y;
	float	floor_x;
	float	floor_y;
}	t_rayfloor;

typedef struct s_dda
{
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	float	perp_wall_dist;
	float	line_height;
	float	hit_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		door;
	int		texture_index;
}	t_dda;

typedef struct s_draw
{
	int	x;
	int	y;
	int	size;
	int	color;
}	t_draw;

/* Estructura Principal */
typedef struct s_cub3d
{
	t_parser	*parser;
	void		*mlx;
	void		*window;
	t_img		*canvas;
	char		*data;
	t_weapon	gun;
	t_textures	textures;
	int			minimap_on;
	bool		minimap_down;
}	t_cub3d;

/* --- PROTOTIPOS FUNCIONES --- */

/* 1. PARSING */
// parse_main.c
void			parser(t_cub3d *cub3d, char **av);
int				handle_id(char *line, t_parser *parser);

// parse_read.c
char			**read_map(int fd, t_parser *parser);

// parse_textures.c
int				set_var(char *id, char *var, t_parser *parser);

// parse_colors.c
int				handle_fc_color(char *var, int is_f, bool *flag, t_parser *p);

// parse_map.c
void			copy_map(char **tmp, t_parser *parser);
char			**padded_map(char **map, int rows, int cols);
void			handle_map(char *line, char **tmp_map, t_parser *parser);

// parse_check.c
void			check_map(char **map, t_parser *parser);
void			check_info(t_parser *parser);

// parse_player.c
void			check_player_once(char **map, t_parser *parser);

// parse_utils.c
int				is_cub(char *av);
bool			is_id(char *line);
bool			is_map(char *line);

/* 2. INITIALIZATION */
// init_data.c
void			init_cub3d(t_cub3d *cub3d);
void			init_parser(t_parser *p);
void			init_player(t_player *player);

// init_mlx.c
int				start_mlx(t_cub3d *cub3d);

// init_assets.c
int				load_textures(t_cub3d *c);

/* 3. CORE (Game Loop) */
// game_loop.c
int				draw_loop(t_cub3d *cub3d);

/* 4. INPUTS */
// input_setup.c
void			setup_hooks(t_cub3d *cub3d);

// input_keyboard.c
int				key_press(int k, t_cub3d *c);
int				key_release(int k, t_cub3d *c);

// input_mouse.c
int				mouse_move(int x, int y, void *param);
int				mouse_press(int button, int x, int y, t_cub3d *c);
int				mouse_release(int button, int x, int y, t_cub3d *c);

/* 5. LOGIC */
// player_move.c
void			move_player(t_cub3d *c);
void			rotate_player(t_player *p, float rot);
void			init_player_vectors(t_player *p);

// player_actions.c
void			open_door(t_cub3d *c);

/* 6. RENDER */
// rc_main.c
void			render_3d_view(t_cub3d *c);

// rc_dda.c
void			init_dda(t_cub3d *c, t_dda *dda, float rx, float ry);
void			perform_dda(t_cub3d *c, t_dda *dda);

// draw_walls.c
void			draw_texture_line(t_cub3d *c, t_dda *dda, int x);

// draw_fl_ceil.c
void			render_floor_ceiling(t_cub3d *c);

// draw_minimap.c
void			render_minimap(t_cub3d *cub3d);

// draw_weapon.c
void			render_weapon(t_cub3d *c);

// draw_utils.c
void			our_put_pixel(int x, int y, int color, t_cub3d *c);
void			clear_image(t_cub3d *cub3d);
int				get_texture_color(t_tex *tex, int x, int y);
unsigned int	rgb_to_color(t_rgb rgb);

/* 7. CLEANUP & UTILS */
// clean_data.c
void			free_parser(t_parser **p);

// clean_exit.c
void			free_all(t_cub3d *c);
void			free_and_exit(t_parser *parser, char *str, int code);
void			free_cub3d(t_cub3d *cub3d, char *str, int code);
int				cub3d_esc(t_cub3d *c);

// utils_mem.c
int				ft_error(int code, char *str);
void			*safe_malloc(size_t size);

// utils_debug.c
void			debug_after_parse(const t_cub3d *cub3d);

#endif