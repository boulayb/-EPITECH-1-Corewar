/*
** check_tools.c for corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar/asm
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Thu Apr  9 12:34:36 2015 Boulay Arnaud
** Last update Sat Apr 11 14:25:08 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int	param_execption(char *name, int i)
{
  if (my_strcmp(name, "zjmp") == 1)
    return (1);
  else if ((my_strcmp(name, "ldi") == 1 || my_strcmp(name, "lldi") == 1)
	   && (i == 1 || i == 2))
    return (1);
  else if ((my_strcmp(name, "sti") == 1) && (i == 2 || i == 3))
    return (1);
  else if (my_strcmp(name, "fork") == 1 || my_strcmp(name, "lfork") == 1)
    return (1);
  return (0);
}

int	add_bytes(char type, char b_param, int i, char *name)
{
  if ((b_param & type) == 0)
    {
      my_putstr("Syntax Error: Bad argument for instruction ", 1);
      my_putstr(name, 1);
      my_putstr(".\n", 1);
      return (-1);
    }
  if (b_param == 1)
    return (1);
  else if (b_param == 4 || param_execption(name, i) == 1)
    return (2);
  else if (b_param == 2)
    return (4);
  return (0);
}

char	**sort_params(char **tab, char *param)
{
  if (is_inside(param, '+') == 1)
    {
      if ((tab = my_strtowordtab(tab, param, '+')) == NULL)
	return (NULL);
    }
  else if (is_inside(param, '-') == 1)
    {
      if ((tab = my_strtowordtab(tab, param, '-')) == NULL)
	return (NULL);
    }
  else
    {
      if ((tab = my_strtowordtab(tab, param, ' ')) == NULL)
	return (NULL);
      if (tab[1] != NULL)
	return (NULL);
    }
  return (tab);
}

int	get_params(char *param, t_label *label_list)
{
  if (param[0] == LABEL_CHAR)
    {
      if (check_label(param + 1, label_list, 1, 0) == -1)
	return (-1);
    }
  else if (param[0] == '0' && param[1] == 'x')
    {
      if (my_atoi_base(param + 2, BASE16) == -1)
	return (-1);
    }
  else
    if (my_atoi_base(param, BASE10) == -1)
      return (-1);
  return (0);
}
