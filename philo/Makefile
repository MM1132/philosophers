SRC_DIR := src
OBJ_DIR := obj
CC := cc
# Also flags for the include directories. Yey :) 
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -Iinclude

# Executable setup
NAME := philo
SRC_FILES := \
	$(SRC_DIR)/main.c
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Other rules
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
