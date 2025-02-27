SRC_DIR := philo
OBJ_DIR := obj
CC := cc
# Also flags for the include directories. Yey :) 
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -I./lib/libft/include -Iinclude
DEP_LIBFT_DIR := lib/libft
DEP_LIBFT := $(DEP_LIBFT_DIR)/libft.a
DEP_LIBFT_FLAGS := -L$(DEP_LIBFT_DIR) -lft

# Executable setup
NAME := philo
SRC_FILES := \
	$(SRC_DIR)/main.c
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES) $(DEP_LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(DEP_LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Other rules
$(DEP_LIBFT):
	$(MAKE) -C $(DEP_LIBFT_DIR)

clean:
	$(MAKE) -C $(DEP_LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(DEP_LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
