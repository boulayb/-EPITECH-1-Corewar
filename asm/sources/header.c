/*
** header.c for corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar/asm
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Sat Apr  4 22:35:27 2015 Boulay Arnaud
** Last update Sat Apr 11 14:55:48 2015 Boulay Arnaud
*/

#include "asm.h"
#include "op.h"

void	disp_label(t_label *label_list)
{
  t_label *tmp;

  tmp = label_list->next;
  while (tmp != label_list)
    {
      my_putstr(tmp->name, 1);
      my_putchar(' ', 1);
      my_putnbr(tmp->role, 1);
      my_putchar(' ', 1);
      my_putnbr(tmp->bytes, 1);
      tmp = tmp->next;
      my_putchar('\n', 1);
    }
}

int	create_header(int src, int dest, t_label *label_list)
{
  int	total;

  if (check_syntax(src, &total, label_list) == -1)
    return (-1);
  if (total == 0)
    {
      my_putstr("Error: file is empty.\n", 1);
      return (-1);
    }
  my_putnbr(total, 1);
  my_putchar('\n', 1);
  (void)dest;
  return (0);
}
