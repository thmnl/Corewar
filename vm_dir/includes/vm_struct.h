/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:25:42 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:25:44 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCT_H
# define VM_STRUCT_H

# include "op.h"
# include "libft.h"

typedef struct		s_player
{
	char			*path;
	int				p_nbr;
}					t_player;

typedef struct		s_options
{
	int				dump;
	int				dump_cycles;
	int				graphic;
	t_list			*p_list;
	int				nbr_champs;
	int				debug;
	int				debug_nbr;
	int				mute;
	int				save;
	int				save_nbr;
}					t_options;

typedef struct		s_vm
{
	int				nb_champs_org;
	int				nb_champs;
	long int		nb_cycles;
	int				*live;
	int				*id;
	t_options		*option;
	int				nb_process;
	int				cycle_to_die;
	int				cycle_new;
	int				check_new;
	int				winner_id;
	long int		nb_cycle_max;
	char			arn[MEM_SIZE];
	char			color[MEM_SIZE];
	char			highlight[MEM_SIZE];
}					t_vm;

typedef struct		s_inst
{
	int				prm[3];
	char			type[3];
}					t_inst;

typedef struct		s_prc
{
	int				pc;
	char			op;
	char			reg[REG_NUMBER * REG_SIZE];
	char			carry;
	int				wait;
	char			live;
	t_inst			inst;
	struct s_prc	*next;
}					t_prc;

typedef struct		s_champ
{
	int				id;
	char			live[2];
	char			color;
	char			*name;
	char			*comment;
	unsigned char	*inst;
	int				size;
	t_prc			*prc;
}					t_champ;

typedef struct		s_op
{
	char			*name;
	char			nb_param;
	char			type[3];
	char			op;
	int				cycle;
	char			*comment;
	char			encoding;
	char			size;
}					t_op;

#endif
