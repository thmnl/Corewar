/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_proto.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:25:36 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 13:55:57 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PROTO_H
# define VM_PROTO_H

void		print_arena(t_vm vm, t_champ *champ);
void		ini_arena(t_vm *vm, t_champ *champ);
t_champ		*ini_champ_id(t_options *opt);
char		check_cycle(t_vm *vm, t_champ *champ);
int			nb_champs_of(int ac, char **av);
void		read_analyze(t_champ *champ, t_options *opt);
void		first_process(t_champ *champ, int pc);
t_op		*ini_op_tab(void);
char		fill_type(t_vm *vm, t_prc *prc, t_op *op_tab);
void		fill_param(t_vm *vm, t_prc *prc, t_op *op_tab);
void		inst_live(t_vm *vm, t_champ *champ, t_prc *prc, t_op *op_tab);
void		inst_ld(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_st(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_add(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_sub(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_and(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_or(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_xor(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_zjmp(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_ldi(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_sti(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_fork(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_lld(t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_lldi(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_lfork(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab);
void		inst_aff(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab);
void		set_reg_zero(t_prc *prc, int id);
void		put_in_reg(t_prc *prc, int id, int nb);
int			get_from_reg(t_prc *prc, int id);
void		move_pc(t_prc *prc, t_op *op_tab);
void		begin_war(t_vm *vm, t_champ *champ);
void		dump_memory(t_vm vm);
void		put_in_arena(t_vm *vm, int pos, char c);
void		put_in_color(t_vm *vm, int pos, char c);
void		put_in_highlight(t_vm *vm, int pos, char c);
void		usage(void);
t_options	*init_options(void);
void		del_options(t_options *options);
void		options_add_player(char *str, int p_nbr, t_options *opt);
void		load_options(int argc, char **argv, t_options *options);
void		de_print_options(t_options *options);
void		get_from_arena(t_vm *vm, t_prc *prc, int id, int loc);
int			count_process(t_vm *vm, t_champ *champ);
char		lao_inner_loop(char *line, t_options *opt, char mode, int *p_nbr);
char		lao_switch(char *str, t_options *options);
void		modify_carry(t_prc *prc, int res);
char		check_inst(char *mem, int op, t_op *op_tab);
char		check_reg_nb(t_inst *inst);
void		rini_inst(t_prc *prc);
void		rini_prc(t_prc *prc);
void		exe_cycle(t_vm *vm, t_champ *champ, t_op *op_tab);
void		ini_vm(t_vm *vm, t_options *opt);
void		fill_useful(t_op *op, int cycle, char encoding, char size);
void		fill_text(t_op *op, char *name, char *comment);
void		fill_other(t_op *op_tab, char nb_param, char op);
void		fill_type_u(t_op *op_tab, char t0, char t1, char t2);
int			ft_free_maillon(t_champ *champ, int ord, t_prc *p);

#endif
