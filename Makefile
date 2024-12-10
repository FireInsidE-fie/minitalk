CLIENT			=		client
SERVER			=		server
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
						$(RM) $(RMFLAGS) $(OCLIENT_BONUS) $(OSERVER_BONUS)
						cd $(LIBFTDIR) && make clean

fclean:					clean
						$(RM) $(RMFLAGS) $(CLIENT) $(SERVER)
						cd $(LIBFTDIR) && make fclean

re:						fclean all


bonus:					client_bonus server_bonus $(LIBFT)


client_bonus:			$(OCLIENT_BONUS) $(LIBFT)
						$(CC) $(CFLAGS) $^ -o client

server_bonus:			$(OSERVER_BONUS) $(LIBFT)
						$(CC) $(CFLAGS) $^ -o server


.PHONY:					all clean fclean re bonus client_bonus server_bonus