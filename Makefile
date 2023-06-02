##
## EPITECH PROJECT, 2021
## navy
## File description:
## Makefile
##

SRC	=	src/my_world.c 					\
		src/map/create_map.c			\
		src/map/draw_map.c				\
		src/map/draw_convex.c			\
		src/map/modify_map.c			\
		src/window/window_process.c		\
		src/window/sprite_process.c		\
		src/process/double_to_string.c	\
		src/events/dig_button.c		\
		src/events/lines_button.c	\
		src/events/tiles_button.c	\
		src/map/select_point.c

OBJ = $(SRC:.c=.o)

NAME = my_world

CFLAGS	+= -Wall -Wextra -W -I include -g

all:	$(NAME)

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy -lm $(CSFML)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f vgcore*
	rm -f saves/*

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re: fclean	all

.PHONY: clean fclean re
