##
## EPITECH PROJECT, 2021
## Philosophers
## File description:
## Makefile
##

NAMEPHILO	=	philo

SRCSPHILO	=	src/main.c	\
				src/start.c	\
				src/engine.c	\
				src/action.c	\

CFLAGS	+=	-W -Wall -Wextra -Werror -g
CFLAGS	+=	-I include

LDFLAGS	+=	-lpthread

CC	=	gcc

RM	=	rm -f

OBJSPHILO	=	$(SRCSPHILO:.c=.o)

all:		philos

philos:		$(NAMEPHILO)


$(NAMEPHILO):	$(OBJSPHILO)
		@$(CC) $(OBJSPHILO) -o $(NAMEPHILO) $(LDFLAGS)

clean:
		@$(RM) $(OBJSPHILO)

fclean:		clean
		@$(RM) $(NAMEPHILO)

re:		fclean all

.PHONY:		all clean fclean re