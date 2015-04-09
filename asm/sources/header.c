/*
** header.c for corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar/asm
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Sat Apr  4 22:35:27 2015 Boulay Arnaud
** Last update Mon Apr  6 14:47:42 2015 Boulay Arnaud
*/

#include "asm.h"
#include "op.h"

int	create_header(int src, int dest, t_label *label_list)
{
  int	total;

  if (check_syntax(src, &total, label_list) == -1)
    return (-1);
  (void)dest;
  return (0);
}
