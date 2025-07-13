/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:04:27 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 22:44:11 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 640
# define WIN_NAME "And thanks for all the fish !"
# define ON_DESTROY 17

typedef struct s_psprites
{
	void	*idle_east;
	void	*idle_west;
	void	*idle_north;
	void	*idle_south;
	void	*walk_easta;
	void	*walk_eastb;
	void	*walk_westa;
	void	*walk_westb;
	void	*walk_northa;
	void	*walk_northb;
	void	*walk_southa;
	void	*walk_southb;
}				t_psprites;

typedef struct s_esprites
{
	void	*close;
	void	*open;
}				t_esprites;

typedef enum e_dir
{
	N,
	S,
	W,
	E
}				t_dir;

typedef enum e_exit_state
{
	CLOSE,
	OPEN
}				t_exit_state;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	int				moves;
	int				width;
	int				height;
	int				player;
	t_dir			player_dir;
	int				player_x;
	int				player_y;
	int				collectibles;
	int				exit;
	t_exit_state	exit_state;
	t_bool			finish;
	t_bool			big;
	void			*c_sprite;
	void			*g_sprite;
	void			*w_sprite;
	void			*v_sprite;
	t_esprites		*e_sprites;
	t_psprites		*p_sprites;
}				t_game;

// Check arguments
t_bool	valid_arguments(int argc, char **argv);
// Map Parsing
t_game	*load_game(char *file);
t_bool	check_map_content(t_game *game);
t_bool	is_map_closed(t_game *game);
t_bool	collectible_reachables(t_game *game);
t_bool	exit_reachable(t_game *game);
// Map Utils
void	reset_map(t_game *game);
void	free_map(t_game *game);
// Mlx initialization
t_bool	load_mlx_data(t_game *game);
// Sprites Loading
t_bool	load_player_sprites(t_game *game);
t_bool	load_exit_sprite(t_game *game);
t_bool	load_collec_sprite(t_game *game);
t_bool	load_ground_sprite(t_game *game);
t_bool	load_wall_sprite(t_game *game);
t_bool	load_void_sprite(t_game *game);
// Graphics
void	draw_map(t_game *game);
void	draw_big_map(t_game *game);

// Hooks
int		key_handler(int key, t_game *game);
int		on_destroy(t_game *game);
// Move
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
// Process Move
void	process_move_right(t_game *game, char tile);
void	process_move_left(t_game *game, char tile);
void	process_move_up(t_game *game, char tile);
void	process_move_down(t_game *game, char tile);
// Free
void	ft_clean(t_game *game);
void	exit_game(char *message, t_game *game);
// Victory
void	victory(t_game *game);

// Debugging
void	display_map(t_game *game);

#endif