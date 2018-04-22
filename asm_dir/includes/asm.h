/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:25:08 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/20 11:51:49 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

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

typedef struct s_optab	t_optab;
typedef struct s_champ	t_champ;
typedef struct s_label	t_label;

struct					s_label
{
	char	*name;
	int		address;
};

struct					s_optab
{
	char	*ope;
	void	(*fct)(t_champ*, char*);
};

struct					s_champ
{
	char	**tchamp;
	char	**champ;
	char	**ist;
	char	*name;
	char	*comment;
	char	*labels;
	char	*path;
	char	*inst;
	char	*file;
	int		error;
	int		ligne;
	int		fd;
	int		size;
	int		oct;
	t_label	**label;
	t_optab	optab[17];
};

int						ft_tab_len(char **t);
int						ft_find_line(char *s, char *path);

t_champ					*ft_live(char *s, t_champ *f, int l);
t_champ					*ft_ld(char *s, t_champ *f, int l);
t_champ					*ft_st(char *s, t_champ *f, int l);
t_champ					*ft_add(char *s, t_champ *f, int l);
t_champ					*ft_sub(char *s, t_champ *f, int l);
t_champ					*ft_and(char *s, t_champ *f, int l);
t_champ					*ft_or(char *s, t_champ *f, int l);
t_champ					*ft_xor(char *s, t_champ *f, int l);
t_champ					*ft_zjmp(char *s, t_champ *f, int l);
t_champ					*ft_ldi(char *s, t_champ *f, int l);
t_champ					*ft_sti(char *s, t_champ *f, int l);
t_champ					*ft_fork(char *s, t_champ *f, int l);
t_champ					*ft_lld(char *s, t_champ *f, int l);
t_champ					*ft_lldi(char *s, t_champ *f, int l);
t_champ					*ft_lfork(char *s, t_champ *f, int l);
t_champ					*ft_aff(char *s, t_champ *f, int l);
t_champ					*ft_free_ret(t_champ *s, char **tmp);

t_champ					*ft_reg_size(t_champ *f);
t_champ					*ft_ind_size(t_champ *f);
t_champ					*ft_dir_size(t_champ *f, char *s);

int						ft_count_sep(char *s);
int						ft_isind(char c);
int						ft_check_label(char *s, t_champ *f, int check);
t_champ					*ft_dir_check(char *s, t_champ *f, int l, char *inst);
t_champ					*ft_ind_check(char *s, t_champ *f, int l, char *inst);
t_champ					*ft_reg_check(char *s, t_champ *f, int l, char *inst);

char					*ft_remove_com_from_cmd(char *s, char c);

void					ft_exit(char *s);
t_champ					*ft_error(char *s, t_champ *f);
t_champ					*ft_bad_label(char *s, t_champ *f, int l);
t_champ					*ft_inst_error(char *s, t_champ *f, int l);
t_champ					*ft_lexic_error(char *s, t_champ *f, int l, int i);
t_champ					*ft_token_error(char *s, t_champ *f, int l);
t_champ					*ft_check_error(char *path, t_champ *f);
t_champ					*ft_check_error3(t_champ *f);
t_champ					*ft_check_error4(t_champ *f);
t_champ					*ft_check_error5(t_champ *f);
t_champ					*ft_check_error6(char *s, t_champ *f, int l);

int						ft_recup_label(t_champ *p);
int						ft_count_label_char(char *str, int order);
int						ft_get_label_address(t_champ *p, int i, int j);
int						ft_check_ist(char *str);
int						ft_jump_pattern(char *str);
char					**ft_trim(char **tab);
void					ft_free_label(t_champ *p);

void					ft_trad(t_champ *f);
void					ft_ope(t_champ *f);
int						ft_get_next_symbol(char *str, int pos, char sbl,
																int skip_space);
void					ft_opocd(t_champ *f, char *line);
int						ft_get_label_value(t_champ *f, char *line);
void					ft_get_d_val(int *d, int *val, char *line, t_champ *f);
void					ft_get_d_val2(int *d, int *val, char *line, t_champ *f);
void					ft_oplive(t_champ *f, char *line);
void					ft_opld(t_champ *f, char *line);
void					ft_opst(t_champ *f, char *line);
void					ft_opadd(t_champ *f, char *line);
void					ft_opsub(t_champ *f, char *line);
void					ft_opand(t_champ *f, char *line);
void					ft_opor(t_champ *f, char *line);
void					ft_opxor(t_champ *f, char *line);
void					ft_opzjmp(t_champ *f, char *line);
void					ft_opldi(t_champ *f, char *line);
void					ft_opsti(t_champ *f, char *line);
void					ft_opfork(t_champ *f, char *line);
void					ft_oplld(t_champ *f, char *line);
void					ft_oplldi(t_champ *f, char *line);
void					ft_oplfork(t_champ *f, char *line);
void					ft_opaff(t_champ *f, char *line);
char					*ft_remove_double_sp(char *str);

#endif
