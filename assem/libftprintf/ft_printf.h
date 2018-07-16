/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:38:42 by bgres             #+#    #+#             */
/*   Updated: 2018/01/26 21:31:57 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <wchar.h>
# include <locale.h>

typedef	struct		s_param
{
	int				pls;
	int				mns;
	int				nol;
	int				ht;
	int				prbl;
	char			lm;
	char			type;
	int				tchka;
	int				ror;
	int				wdth;
	int				prcsn;
}					t_param;
int					ft_printf(char *fmt, ...);
int					parsing_two(t_param **param, char *txt, va_list vl);
void				parsing_three(t_param **param, char *txt, char *f, int *i);
void				check_p_end(t_param **param, char *txt, int *i, va_list ap);
void				prmssgn(t_param **a);
size_t				ft_get_len(size_t n, int b);
void				getd(t_param **list, char c, long long l, va_list vl);
int					ft_printf(char *fmt, ...);
void				get_decimal(t_param **list, va_list vl);
void				parsing_one(char *txt, va_list ap, t_param *param);
void				itoa_printf(size_t n, t_param *a, int zn);
void				p_printf(size_t n, t_param *a);
size_t				get_p(va_list vl);
void				for_bits(wint_t ch, t_param *a, char **stroka);
void				p_utf(t_param *a, va_list vl);
void				c_print(t_param *a, va_list vl, char t);
void				s_print(t_param *a, va_list vl);
void				s_print_for_unic(t_param *a, char *ch);
void				parsing_one_need(int **i, int *g, int *a, int *j);
void				parsing_one_write(char *txt, int *i, int j);
int					parsing_two_need(int *i, int *j, int flag);
void				check_p_end_need(t_param **param, va_list vl);
int					for_bits_need(wint_t ch);
int					for_bits_check_mcm(int j);
char				*for_bits_check_m(wint_t ch, t_param *a);
char				*for_bits_check_mm(wint_t ch, t_param *a);
char				*for_bits_check_mmm(wint_t ch, t_param *a);
char				*for_bits_check_mmmm(wint_t ch, t_param *a);
void				s_print_for_unic(t_param *a, char *ch);
char				c_print_need(char o, va_list vl, t_param *a);
char				*for_digits(size_t n, t_param *a);
void				p_printf_need(char **str, t_param *a, char *wdth);
void				p_printf_needd(char **str, t_param *a, char *wdth);
void				itoa_printf_need_dva(t_param *a, char **str, char *wdth,
						size_t w);
void				razraz(t_param *a, char **str, char *wdth);
void				razdva(t_param *a, char **str, char *wdth);
void				dvatri(char **str, t_param *a);
void				plz(char **str, t_param *a, int zn);
void				tricheturi(char **str, t_param *a, char *wdth);
void				itoa_printf_need(t_param *a,
						char **str, char *wdth, int zn);
void				dvadva(char **str, t_param *a);
char				*ft_stranew(size_t size, char *aa);
void				sem(char **ch, t_param *a, char *wdth, int r);
void				piatpiat(char **ch, t_param *a, int g, char *wdth);
void				piat(char **ch, t_param *a, int g, char *wdth);
void				shest(char **ch, int *g);
void				shestshrst(char **ch, int *g, t_param *a);
void				dvatri(char **str, t_param *a);
void				tritri(char **str, t_param *a, char *wdth);
void				vosem(char **stroka, wint_t ch, t_param *a, int j);
void				setflag(t_param **param, char f);
void				setflag_dva(t_param **param, char *txt, int j, int flag);
void				for_free_one(char **line, char *buf);
void				for_free_two(char *buf, char **line);
char				*ft_strndup(char *src, int n);
t_param				*prmcrt(void);
int					g_iter;
int					g_rr;
#endif
