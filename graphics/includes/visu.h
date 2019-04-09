/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:07:26 by mmcclure          #+#    #+#             */
/*   Updated: 2019/04/09 13:10:22 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 900

# include "../../libft/includes/libft.h"
# include <SDL2_gfxPrimitives.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>

typedef struct		s_window
{
	SDL_Window		*window;
	SDL_Renderer	*window_render;
	SDL_Texture		*background;
	SDL_Texture		*back_pause;
	TTF_Font		*f_pause;
	TTF_Font		*f_status;
	SDL_Color		color;
	Sint32			width;
	Sint32			height;
	char			quit;
	char			status;
}					t_window;

# define WIN_WIN	(window->window)
# define WIN_REND	(window->window_render)
# define WIN_BACK	(window->background)
# define BACK_PAUSE	(window->back_pause)
# define FONT_PAUSE	(window->f_pause)
# define FONT_STAT	(window->f_status)
# define FONT_COLOR	(window->color)
# define WIN_WID	(window->width)
# define WIN_HEIG	(window->height)
# define WIN_QUIT	(window->quit)
# define WIN_STATUS	(window->status)

typedef struct		s_run
{
	int				cycle;
	int				tmp;
	int				speed;
	int				processes;
	int				cyc_die;
	int				cyc_delta;
	int				nbr_live;
	int				max_checks;
}					t_run;

# define RUN_CYCLE	(running->cycle)
# define RUN_TMP	(running->tmp)
# define RUN_SPEED	(running->speed)
# define RUN_PROC	(running->processes)
# define CYC_DIE	(running->cyc_die)
# define CYC_DELTA	(running->cyc_delta)
# define NBR_LIVE	(running->nbr_live)
# define MAX_CHECKS	(running->max_checks)

t_window		*init_win(void);
void			win_events(t_window *window);
int				load_files(t_window *window);
void			print_str(t_window *window, char *str, int x, int y);
#endif
