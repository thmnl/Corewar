/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:25:28 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:25:30 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <curses.h>
# include "errors.h"
# include "vm_struct.h"
# include "vm_proto.h"

# define HIGHLIGHT	10

typedef struct		s_visu
{
	WINDOW			*memory;
	WINDOW			*info;
	int				*last_live;
	int				*last_cycle;
	int				term_wid;
	int				term_hei;
	int				color_mode;
	int				mem_line_size;
	int				mode_pause;
	int				pause_time;
	int				time_sequence;
}					t_visu;

t_visu				*visu_init(t_champ *champ, int nb);
void				process_names(t_champ *champ, int nb, int i, int j);
int					*init_last_live(void);
int					handle_ncurses(t_vm *vm, t_champ *champ, t_visu *visu);
int					wait_for_input(t_visu *visu, int key);
void				draw_windows(t_vm *vm, t_champ *champ, t_visu *visu);
void				draw_info(t_vm *vm, t_champ *champ, t_visu *visu);
void				clean_heart_space(t_visu *visu);
void				set_color_again(t_vm *vm, t_champ *champ, t_visu *visu);
void				print_the_heart_1(t_visu *visu, int phase);
void				print_the_heart_2(t_visu *visu, int phase);
void				print_the_heart_3(t_visu *visu, int phase);
void				print_the_heart_4(t_visu *visu, int phase);

#endif
