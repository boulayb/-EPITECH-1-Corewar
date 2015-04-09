/*
** check.c for corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar/asm
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Wed Apr  8 12:53:31 2015 Boulay Arnaud
** Last update Thu Apr  9 15:15:06 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int	is_indirect(char *param, t_label *label_list)
{
  char	**tab;
  int	i;

  i = -1;
  tab = NULL;
  if ((tab = sort_params(tab, param + 1)) == NULL)
    {
      my_putstr("Error: Malloc failed in my_strtowordtab.\n", 1);
      return (-1);
    }
  while (tab[++i] != NULL)
    if (get_params(tab[i], label_list) == -1)
      return (-1);
  free_tab(tab);
  return (1);
}

int	is_direct(char *param, t_label *label_list)
{
  char	**tab;
  int	i;

  i = -1;
  tab = NULL;
  if (param[0] == DIRECT_CHAR)
    {
      if ((tab = sort_params(tab, param + 1)) == NULL)
	{
	  my_putstr("Error: Malloc failed in my_strtowordtab.\n", 1);
	  return (-1);
	}
      while (tab[++i] != NULL)
	if (get_params(tab[i], label_list) == -1)
	  return (-1);
      free_tab(tab);
      return (1);
    }
  return (0);
}

int	is_register(char *param)
{
  int	reg;

  if (param[0] == 'r')
    {
      reg = my_atoi_base(param + 1, BASE10);
      if (reg >= 1 && reg <= REG_NUMBER)
	return (1);
      my_putstr("Syntax Error: Invalid register", 1);
    }
  return (0);
}

int	check_params(char *name, char **param, op_t code, t_label *label_list)
{
  int	b_param;
  int	i;
  int	b_tmp;

  (void)code;
  (void)name;
  b_tmp = 0;
  i = 0;
  while (param[i] != NULL && i < MAX_ARGS_NUMBER)
    {
      my_putstr(param[i], 1);
      my_putchar('\n', 1);
      if (is_register(param[i]) == 1)
	b_param = 1;
      else if (is_direct(param[i], label_list) == 1)
	b_param = 2;
      else if (is_indirect(param[i], label_list) == 1)
	b_param = 4;
      else
	return (-1);
      b_tmp = b_tmp + b_param;
      ++i;
    }
  return (b_tmp);
}
