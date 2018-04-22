/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:25:08 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 17:58:30 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H

# include "op.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_dc
{
	char	*name;
	char	*comment;
	char	*ist;
}				t_dc;

void			ft_dc_inst(int fd, t_dc *f);

void			ft_dir4(int fd, t_dc *f);
void			ft_dir2(int fd, t_dc *f);
void			ft_ind(int fd, t_dc *f);
void			ft_reg(int fd, t_dc *f);

void			ft_live(int fd, t_dc *f);
void			ft_st(int fd, t_dc *f);
void			ft_ld(int fd, t_dc *f);
void			ft_add(int fd, t_dc *f);
void			ft_sub(int fd, t_dc *f);
void			ft_and(int fd, t_dc *f);
void			ft_or(int fd, t_dc *f);
void			ft_xor(int fd, t_dc *f);
void			ft_zjmp(int fd, t_dc *f);
void			ft_ldi(int fd, t_dc *f);
void			ft_sti(int fd, t_dc *f);
void			ft_fork(int fd, t_dc *f);
void			ft_lld(int fd, t_dc *f);
void			ft_lldi(int fd, t_dc *f);
void			ft_lfork(int fd, t_dc *f);
void			ft_aff(int fd, t_dc *f);

void			ft_decrypt(char *path, t_dc *f);
void			ft_exit(char *s);

#endif
