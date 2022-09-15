CC = gcc
NAME = #insert
SRC = $(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
LFT = lib-twinters
CFLAGS = -Werror -Wall
LFLAGS = L $(LFT)-lft

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -I/src/ -c $< -o $@

$(NAME) : $(OBJ)
	@make -C $(LFT)
	@$(CC) $(CFLAGS) $(OBJ) -L $(LFT) -lft -o $(NAME)

re : fclean all

clean :
	@rm -rf src/*.o
	@make fclean -C $(LFT)
	@echo Done

fclean : clean
	@rm -rf $(NAME)
