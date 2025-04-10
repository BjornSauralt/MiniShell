NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = obj
LIBFT_DIR = libft
DPRINTF_DIR = ft_dprintf
LIBS = -lreadline
INCLUDE_DIR = Include

MINISHELL = $(wildcard $(SRC_DIR)/**/*.c)

OBJS = $(MINISHELL:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

DPRINTF = $(DPRINTF_DIR)/libftprintf.a

INCLUDES = -I$(LIBFT_DIR) -I$(INCLUDE_DIR) -I$(DPRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(DPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBS) $(DPRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(DPRINTF):
	$(MAKE) -C $(DPRINTF_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(DPRINTF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(DPRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
