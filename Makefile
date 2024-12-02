CLIENT			=		client
SERVER			=		server
CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror
RM				=		rm
RMFLAGS			=		-f
SRCDIR			=		src/
CCLIENT			=		$(SRCDIR)client.c
CSERVER			=		$(SRCDIR)server.c
OCLIENT			=		$(CCLIENT:.c=.o)
OSERVER			=		$(CSERVER:.c=.o)
INCLDIR			=		include/
IFILES			=		minitalk.h
LIBFTDIR		=		libftprintf/
LIBFT			=		$(LIBFTDIR)libftprintf.a

all:					$(CLIENT) $(SERVER)


$(CLIENT):				$(OCLIENT) $(LIBFT)
						$(CC) $(CFLAGS) $^ -o $@

$(SERVER):				$(OSERVER) $(LIBFT)
						$(CC) $(CFLAGS) $^ -o $@

%.o:					%.c
						$(CC) $(CFLAGS) -g -c $^ -o $@

$(LIBFT):				$(LIBFTDIR)/*.c
						cd $(LIBFTDIR) && make

clean:
						$(RM) $(RMFLAGS) $(OCLIENT) $(OCLIENT)
						cd $(LIBFTDIR) && make clean

fclean:					clean
						$(RM) $(RMFLAGS) $(CLIENT) $(SERVER)
						cd $(LIBFTDIR) && make fclean

re:						fclean all


bonus:					all


.PHONY:					all clean fclean re bonus