/*
** asm.h for asm_corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar/asm
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Mar 30 09:34:18 2015 Boulay Arnaud
** Last update Sat Apr 11 14:17:05 2015 Boulay Arnaud
*/

#ifndef	ASM_H_
# define ASM_H_

# include "op.h"

# define BUFFER_SIZE	4096
# define BASE10		"0123456789"
# define BASE16		"0123456789abcdef"

typedef struct		s_label
{
  int			role;
  char			*name;
  int			bytes;
  struct s_label	*next;
  struct s_label	*back;
}			t_label;

int			my_tablen(char **tab);
int			my_atoi_base(char *str, char *base);
int			add_bytes(char type, char b_param, int i, char *name);
int			open_files(int *src, int *dest, char *file_name);
int			set_label(t_label *label_list, int *total, int tmp);
int			check_label(char *label, t_label *label_list, int role, int bytes);
int			check_syntax(int fd, int *total, t_label *label_list);
int			check_params(char *name, char **param, op_t code, t_label *label_list);
int			create_header(int src, int dest, t_label *label_list);
int			is_inside(char *str, char c);
int			my_strlen(char *str);
int			check_no_label(t_label *label_list);
int			add_chain(t_label *label_list, char *name, int role, int bytes);
int			my_strcmp(char *str1, char *str2);
int			get_params(char *param, t_label *label_list);
char			*get_next_line(const int fd);
char			*my_cattab(char **tab, int i);
char			*my_strcat(char *dest, char *src);
char			*my_strdup(char *str);
char			*my_strncpy(char *dest, char *src, int n);
char			**my_strtowordtab(char **tab, char *str, char sep);
char			**sort_params(char **tab, char *str);
void			my_putchar(char c, int fd);
void			my_putstr(char *str, int fd);
void			free_tab(char **tab);
void			my_putnbr(int nb, int fd);
void			rm_list(t_label *label_list);
t_label			*create_list(void);

#endif /* !ASM_H_ */
