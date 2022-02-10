NAME = so_long

CC = cc
INCLUDE = -I libft 
IN = -L libft
LIB = -lm -lmlx -framework OpenGL -framework AppKit 
CC_FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =  check_error.c \
        check_error1.c \
		game_img.c \
		img_to_win.c \
		main.c \
		map_read.c \
		move.c \
		move_utils.c \
		so_long.c \
		get_next_line.c \
		get_next_line_utils.c \

SRCS1 = bonus/check_error_bonus.c \
        bonus/check_error1_bonus.c \
		bonus/game_img_bonus.c \
		bonus/img_to_win_bonus.c \
		bonus/main_bonus.c \
		bonus/map_read_bonus.c \
		bonus/move_bonus.c \
		bonus/move_utils_bonus.c \
		bonus/so_long_bonus.c \
		bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c \
		bonus/enemy_move_bonus.c \
		bonus/move_utils_1_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS1 = $(SRCS1:.c=.o)

%.o: %.c
	$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS) 
	make -C libft
	@$(RM) $(OBJS1) $(NAME)
	$(CC) $(CC_FLAGS) $(INCLUDE) $(IN) $^ -o $@ -lft $(LIB)

bonus: $(OBJS1)
	make -C libft
	@$(RM) $(OBJS) $(NAME)
	 $(CC) $(CC_FLAGS) $(INCLUDE) $(IN) $^ -o $(NAME) -lft $(LIB)

clean:
	make clean -C libft
	$(RM) $(OBJS) $(OBJS1)	

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all
