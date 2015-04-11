/*
** strings.c for corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar/asm
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Sat Apr  4 20:07:54 2015 Boulay Arnaud
** Last update Sat Apr 11 14:27:50 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "asm.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i <= n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  int	j;
  int	i;

  j = -1;
  i = my_strlen(dest) - 1;
  while (src[++j] != '\0')
    dest[++i] = src[j];
  dest[++i] = '\0';
  return (dest);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (-1);
  while (str1[i] != '\0' && str2[i] != '\0')
    if (str1[i] == str2[i])
      ++i;
    else
      return (0);
  if (str1[i] == '\0' && str2[i] == '\0')
    return (1);
  else if (str1[i] == '\0')
    return (2);
  return (0);
}

char	*my_strdup(char *str)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    {
      my_putstr("Error: Malloc failed in my_strdup.\n", 1);
      return (NULL);
    }
  new = my_strncpy(new, str, my_strlen(str));
  return (new);
}

char	*my_cattab(char **tab, int i)
{
  char	*str;
  int	len;
  int	tmp;

  len = 0;
  tmp = i;
  while (tab[++i] != NULL && tab[i][0] != ';' && tab[i][0] != '#')
    len = len + my_strlen(tab[i]);
  if ((str = malloc(sizeof(char *) * (len + 1))) == NULL)
    {
      my_putstr("Error: Malloc failed in my_cattab.\n", 1);
      return (NULL);
    }
  i = tmp + 1;
  str = my_strncpy(str, tab[i], my_strlen(tab[i]));
  while (tab[++i] != NULL && tab[i][0] != ';' && tab[i][0] != '#')
    str = my_strcat(str, tab[i]);
  return (str);
}
