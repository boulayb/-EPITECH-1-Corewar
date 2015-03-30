##
## Makefile for corewar in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_corewar
##
## Made by Boulay Arnaud
## Login   <boulay_b@epitech.net>
##
## Started on  Mon Mar 30 09:35:37 2015 Boulay Arnaud
## Last update Mon Mar 30 10:29:37 2015 Boulay Arnaud
##

ASMFO	= asm/

CORFO	= corewar/

NAME1	= $(ASMFO)asm

NAME2	= $(CORFO)corewar

ASRCFO	= $(ASMFO)sources/

CSRCFO	= $(CORFO)sources/

ASRCS	= $(ASRCFO)main.c

CSRCS	= $(CSRCFO)main.c

AOBJS	= $(ASRCS:.c=.o)

COBJS	= $(CSRCS:.c=.o)

RM	= rm -rf

GCC	= gcc -o

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I$(ASMFO)include/ -I$(CORFO)include/

all: $(NAME1) $(NAME2)

debug:	CFLAGS	+= -g3
debug:	all

$(NAME1): $(AOBJS)
	$(GCC) $(NAME1) $(AOBJS) $(CFLAGS)

$(NAME2): $(COBJS)
	$(GCC) $(NAME2) $(COBJS) $(CFLAGS)

clean:
	rm -rf $(AOBJS)
	rm -rf $(COBJS)

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)

re: fclean all

.PHONY: all debug clean fclean re
