/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:45:08 by bgres             #+#    #+#             */
/*   Updated: 2018/05/09 12:45:09 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libftprintf/ft_printf.h"

int							g_line;
int							g_error;
int							g_cmnd_i;
int							g_cmnd_len;
char						*g_fs;
# define LIVE				"live"
# define LD					"ld"
# define ST					"st"
# define ADD				"add"
# define SUB				"sub"
# define AND				"and"
# define OR					"or"
# define XOR				"xor"
# define ZJMP				"zjmp"
# define LDI				"ldi"
# define STI				"sti"
# define FORK				"fork"
# define LLD				"lld"
# define LLDI				"lldi"
# define LFORK				"lfork"
# define AFF				"aff"
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3
# define MEM_SIZE			(4*1024)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"
# define CCS				".comment"
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define ERROR_1			"Oops, something wrong afte .name/.comment on line"
# define ERROR_2			"Oops, you're label have bad character in line"
# define ERROR_3			"Oops, pleas use the available functions in line"

typedef	struct				s_main
{
	unsigned char			flag;
	char					*name;
	char					*comment;
}							t_main;

typedef struct				s_comand
{
	char					*name;
	unsigned char			op;
	unsigned char			op_est;
	char					lz;
	char					count;
	int						cmnd_l;
	unsigned int			args;
}							t_comand;

typedef struct				s_to_code
{
	char					*lbl;
	char					*f_name;
	unsigned char			first_b;
	unsigned char			op;
	char					lz;
	unsigned char			count;
	char					*ar[4];
	unsigned int			args[3];
	unsigned char			op_est;
	unsigned int			op_f;
	unsigned char			cmnd_len;
	unsigned int			cmnd_i;
	int						cmnd_l;
	struct s_to_code		*next;
}							t_to_code;

t_to_code					*g_cmndlist;

int							skip_space(char *line);
void						need_need(char **line, char **tmp, char **tmp2);
void						need_3(char **line, char **tmp,
							char **tmp2, int *i);
char						*read_read(char *line, int fd);
void						need_4(int *i, int *j);
char						*write_n_c(char *line, int fd);
void						need_5(t_main *main_asm, int fd, char *line, int i);
void						check_name_comment(char *line,
							t_main *main_asm, int fd);
int							check_sp(char *line);
void						do_whot_need(char *line);
void						need_6(t_main *main_asm);
t_main						*start_pars(int fd);
void						need_7(t_to_code *tmp, t_comand **f, char a[4],
							unsigned char mask);
void						count_cmnd_len(t_comand **f);
int							ft_strequ_cw(char const *s1, char const *s2);
unsigned int				magic_with_link(t_to_code *tmp, char *a);
unsigned int				magic_with_link2(t_to_code *tmp, char *a);
unsigned int				convert_t_reg(char *a);
unsigned int				convert_t_dir(t_to_code *tmp, char *a);
unsigned int				convert_t_ind(t_to_code *tmp, char *a);
void						zaebali_nazv(t_to_code *tmp, int i, char flag);
void						convert_args(void);
char						*make_name(char *a);
void						need(t_to_code *tmp, char *a);
void						check_double_lbl(void);
void						need2(char **av, t_main *main_asm,
							char *name);
void						free_list(void);
void						nado_1(void);
void						nado_2(t_main *main_asm, char *name);
void						nado_3(int fd, t_main **main_asm);
void						free_2(t_main *main_asm, char *name);
int							pzdc1(t_main *main_asm);
int							pzdc2(int fd, int i, char **av);
void						pzdc(char *line);
void						last_f(void);
void						add_to_cmndlist(t_to_code *a);
char						*ft_copy_n(char *src, int n);
void						mfl1(t_comand **a);
void						mfl2(t_comand **a);
void						mfl3(t_comand **a);
void						mfl4(t_comand **a);
void						mfl5(t_comand **a);
t_comand					**make_f_list(void);
int							check_all_isdigit(char *param);
char						*check_t_reg(char *param, t_to_code *f,
							unsigned char *op, char position);
char						*check_t_ind(char *param, t_to_code *f,
							unsigned char *op, char position);
char						*check_t_dir(char *param, t_to_code *f,
							unsigned char *op, int position);
char						*check_t_dir_ind(char *param, t_to_code *f,
							unsigned char *op, int position);
char						*check_t_dir_reg(char *param, t_to_code *f,
							unsigned char *op, int position);
char						*check_t_ind_reg(char *param, t_to_code *f,
							unsigned char *op, int position);
char						*check_t_ind_reg_dir(char *param, t_to_code *f,
							unsigned char *op, int position);
void						hvatit_1(int a, int *sdvig, unsigned int *mask,
							int *flag);
int							get_need_f(char *param, int a, t_comand *f,
							t_to_code *tmp);
void						f_full_check(char *line, t_comand *f,
							t_to_code *tmp);
void						hvatit_4(t_to_code **tmp,
							t_comand **f_list, int i);
void						hvatit_5(t_comand ***f_list, unsigned char *i,
							int *j);
void						check_f(t_to_code *tmp, char *line);
void						check_label(char *name);
void						hvatit_6(int *i, char *flag, t_to_code **tmp,
							int *j);
void						hvatit_7(t_to_code **tmp, char *line, int i, int j);
void						pars_two(char *line);
void						write_int(int fd, unsigned int m);
void						write_short(int fd, unsigned int mm);
void						write_name(int fd, t_main *main_asm);
void						write_t_dir(t_to_code *tmp, int fd, int i);
void						write_t_reg(t_to_code *tmp, int fd, int i);
void						write_comand(int fd);
void						start_write(char *name, t_main *main_asm);

#endif
