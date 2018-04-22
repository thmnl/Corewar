/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:17:33 by allallem          #+#    #+#             */
/*   Updated: 2018/04/20 15:07:12 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define B_PF_SIZE 1024

# include "libft.h"

typedef	struct		s_pfspe
{
	va_list			ap;
	char			contenu[B_PF_SIZE];
	int				i;
	int				h;
	int				l;
	int				j;
	int				z;
	int				diese;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				point;
	int				value;
	int				result;
	int				cursor;
	int				fd;
	long long int	size_content;
	long long int	field;
	long long int	precision;
}					t_pfspe;

void				ft_flag_plus_space(t_pfspe *point, long long int content);
void				ft_putstr_printf(char const *str, t_pfspe *point);
int					ft_printf(char const *str, ...);
int					ft_verification_last(char const *str, t_pfspe *point);
int					ft_printfdi(char c, t_pfspe *point, long long int content);
void				ft_put_precision(t_pfspe *point);
void				ft_put_field(t_pfspe *point, char c, long long int content);
void				ft_flag_zero(t_pfspe *point, char *c);
void				ft_putaddress_printf(void *add, char c, t_pfspe *p, int b);
void				ft_printfs(t_pfspe *point, char *content);
void				ft_check_buffer(t_pfspe *point, char c);
void				ft_pull_all(t_pfspe *point);
void				ft_bufnbr_printf(long long int n, t_pfspe *point);
void				ft_putnbr_printf(long long int n, t_pfspe *point);
void				ft_flags_zero(char *c, t_pfspe *point);
int					ft_fillstruct_printf(t_pfspe *point, char const *str);
int					ft_printf_spe(char const *s, t_pfspe *p);
void				ft_putpercent(t_pfspe *point);
void				ft_typefor_address(t_pfspe *p, void *ad,
						unsigned long long int *n, char c);
void				ft_init_pfspe(t_pfspe *point);
void				ft_adjustaddress(t_pfspe *p, char c, char *str);
void				ft_calculate_address(t_pfspe *p, char *s, char c);
int					ft_special_address(unsigned long long int n,
					char c, t_pfspe *p);
void				ft_printf_c(t_pfspe *point, unsigned char c);
void				ft_printfcmaj(t_pfspe *point, int32_t ca);
void				ft_printfsmaj(t_pfspe *point, void *address);
void				ft_puts_field(t_pfspe *p, char c);
void				ft_flagscmaj(t_pfspe *p, int32_t address);
void				ft_flagssmaj(t_pfspe *p, void *address);
void				reset_if_l(t_pfspe *p);
void				reset_if_j(t_pfspe *p);
void				reset_if_z(t_pfspe *p);
int					ft_starflag(t_pfspe *p, char const *str, int *i);

#endif
