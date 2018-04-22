/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:25:27 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/07 16:52:47 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define STR_CONV	"sS%dDicCxXoOuUpy"

typedef struct	s_conv
{
	char		type;
	int			left_align;
	int			posit_show;
	int			zero;
	int			space;
	int			special;
	int			width;
	int			width_given;
	int			precision;
	int			precise;
	int			fd;
	char		size;
}				t_conv;

int				ft_printf(const char *restrict format, ...);
int				pcft_c(va_list ap, t_conv *cd);
int				pcft_lc(va_list ap, t_conv *cd);
int				pcft_s(va_list ap, t_conv *convdata);
int				pcft_sl(va_list ap, t_conv *convdata);
int				pcft_d(va_list ap, t_conv *convdata);
int				pcft_hhd(va_list ap, t_conv *cd);
int				pcft_hd(va_list ap, t_conv *cd);
int				pcft_ld(va_list ap, t_conv *cd);
int				pcft_lld(va_list ap, t_conv *cd);
int				pcft_jd(va_list ap, t_conv *cd);
int				pcft_zd(va_list ap, t_conv *cd);
int				pcft_u(va_list ap, t_conv *convdata);
int				pcft_hhu(va_list ap, t_conv *convdata);
int				pcft_hu(va_list ap, t_conv *convdata);
int				pcft_lu(va_list ap, t_conv *convdata);
int				pcft_llu(va_list ap, t_conv *convdata);
int				pcft_ju(va_list ap, t_conv *convdata);
int				pcft_zu(va_list ap, t_conv *convdata);
int				pcft_x(va_list ap, t_conv *convdata);
int				pcft_hhx(va_list ap, t_conv *convdata);
int				pcft_hx(va_list ap, t_conv *convdata);
int				pcft_lx(va_list ap, t_conv *convdata);
int				pcft_llx(va_list ap, t_conv *convdata);
int				pcft_jx(va_list ap, t_conv *convdata);
int				pcft_zx(va_list ap, t_conv *convdata);
int				pcft_p(va_list ap, t_conv *convdata);
int				pcft_o(va_list ap, t_conv *convdata);
int				pcft_hho(va_list ap, t_conv *convdata);
int				pcft_ho(va_list ap, t_conv *convdata);
int				pcft_lo(va_list ap, t_conv *convdata);
int				pcft_llo(va_list ap, t_conv *convdata);
int				pcft_jo(va_list ap, t_conv *convdata);
int				pcft_zo(va_list ap, t_conv *convdata);
int				pcft_y(va_list ap, t_conv *convdata);
int				pcft_percent(t_conv *cd);
int				pft_isconv(char c);
int				pft_parse_conv(
char *format, size_t se[3], va_list ap, t_conv *cd);
char			*pft_padsign(int value, t_conv *cd, char *str);
int				pft_switchd(va_list ap, t_conv *cd);
int				pft_switchx(va_list ap, t_conv *cd);
int				pft_switcho(va_list ap, t_conv *cd);
int				pft_switchu(va_list ap, t_conv *cd);
void			spft_convdata_init(t_conv *convdata);
void			pft_mod_conv(t_conv *cd);
int				pft_fconv(va_list ap, t_conv *convdata, int ret);

#endif
