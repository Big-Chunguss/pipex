CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

FT_PRINTF_DIR = lib/ftprintf
LIBFT_DIR = lib/libft
UTILS_DIR = utils
SRC_DIR = src
OBJ_DIR = obj
INCS = -I includes

SRC = main.c free.c

UTILS = 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o) $(UTILS:.c=.o))

LIBS = -L$(FT_PRINTF_DIR) -lftprintf \
       -L$(LIBFT_DIR) -lft

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m

all: $(FT_PRINTF_DIR)/libftprintf.a $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -no-pie -o $(NAME)
	@echo "$(GREEN) Compilation of $(NAME) completed!$(BLUE)"

$(FT_PRINTF_DIR)/libftprintf.a:
	@make -C $(FT_PRINTF_DIR) --no-print-directory


$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW) Created directory: $(OBJ_DIR)$(BLUE)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(YELLOW) Cleaned object files.$(BLUE)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(YELLOW) Removed $(NAME) and compiled files.$(BLUE)"

re: fclean all

.PHONY: all clean fclean re
