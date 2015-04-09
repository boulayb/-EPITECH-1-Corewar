/*
** check_tools.c for corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar/asm
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Thu Apr  9 12:34:36 2015 Boulay Arnaud
** Last update Thu Apr  9 15:26:48 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

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
