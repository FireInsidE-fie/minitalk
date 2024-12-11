CLIENT			=		client
SERVER			=		server
CLIENT_BONUS	=		client_bonus
SERVER_BONUS	=		server_bonus
CC				=		cc
CFLAGS			=		-Wall -Wextra -Werror
RM				=		rm
RMFLAGS			=		-f
SRCDIR			=		src/
CCLIENT			=		$(SRCDIR)client.c
CSERVER			=		$(SRCDIR)server.c
CCLIENT_BONUS	=		$(SRCDIR)client_bonus.c
CSERVER_BONUS	=		$(SRCDIR)server_bonus.c
OCLIENT			=		$(CCLIENT:.c=.o)
OSERVER			=		$(CSERVER:.c=.o)
OCLIENT_BONUS	=		$(CCLIENT_BONUS:.c=.o)
OSERVER_BONUS	=		$(CSERVER_BONUS:.c=.o)
INCLDIR			=		include/
IFILES			=		minitalk.h
LIBFTDIR		=		libftprintf/
LIBFT			=		$(LIBFTDIR)libftprintf.a

all:					$(CLIENT) $(SERVER)


$(CLIENT):				$(LIBFT) $(OCLIENT)
						$(CC) $(CFLAGS) $^ -o $@

$(SERVER):				$(LIBFT) $(OSERVER)
						$(CC) $(CFLAGS) $^ -o $@

%.o:					%.c
						$(CC) $(CFLAGS) -g -c $^ -o $@

$(LIBFT):				$(LIBFTDIR)/*.c
						cd $(LIBFTDIR) && make

clean:
						$(RM) $(RMFLAGS) $(OCLIENT) $(OSERVER)
						$(RM) $(RMFLAGS) $(OCLIENT_BONUS) $(OSERVER_BONUS)
						cd $(LIBFTDIR) && make clean
fclean:					clean
						$(RM) $(RMFLAGS) $(CLIENT) $(SERVER)
						cd $(LIBFTDIR) && make fclean
re:						fclean all


bonus:					$(CLIENT_BONUS) $(SERVER_BONUS)


$(CLIENT_BONUS):		$(LIBFT) $(OCLIENT_BONUS)
						$(CC) $(CFLAGS) $^ -o $@

$(SERVER_BONUS):		$(LIBFT) $(OSERVER_BONUS)
						$(CC) $(CFLAGS) $^ -o $@

.PHONY:					all clean fclean re bonus