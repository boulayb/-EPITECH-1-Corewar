/*
** my_strdup.c for strdup in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Wed Dec 24 11:18:31 2014 Danilov Dimitri
** Last update Sun Apr 12 12:33:04 2015 Bocquet Celestin
*/

#include	"cw.h"

char		*my_strdup(char *src)
{
  int		i;
  char		*dest;

  i = 0;
  while (src[i] != '\0')
    i = i + 1;
  if ((dest = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
