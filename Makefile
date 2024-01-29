NAME			=	push_swap
OBJ_DIR			=	./obj
SRC_DIR			=	./src
INCLUDES		=	./includes

M_MAIN			=	./main.c

SRCS			=	push_swap.c\


OBJECTS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

CC				=	gcc

CC_STRICT		=	-Wall -Wextra -Werror

CC_DEBUG		=	-g -fsanitize=leak

CC_INCLUDES		=	-I $(LIBFT_INCLUDES) -I $(INCLUDES)

CC_FULL			=	$(CC) $(CC_STRICT) $(CC_INCLUDES) $(CC_DEBUG)

LIBFT			=	./libft/libft.a

LIBFT_DIR		=	./libft

LIBFT_INCLUDES	=	./libft

ARCHIVES		=	./archives

M_ARCHIVE		=	$(ARCHIVES)/push_swap.a

M_ARCHIVES		=	$(M_ARCHIVE) $(LIBFT)

all: $(LIBFT) $(M_ARCHIVE) $(NAME)

$(LIBFT):
					make -C $(LIBFT_DIR)

$(M_ARCHIVE): $(OBJECTS)
					mkdir -p $(@D)
					ar rcs $(M_ARCHIVE) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
					mkdir -p $(@D)
					$(CC_FULL) -c $< -o $@

$(NAME):
					$(CC_FULL) $(M_MAIN) $(M_ARCHIVES) -o $(NAME)

clean:
					rm -rf $(OBJ_DIR) $(ARCHIVES)
					make clean -C $(LIBFT_DIR)
					@rm -f .bonus

fclean: clean
					rm -f $(NAME)
					make -C libft fclean

re: fclean all

.PHONY: all re clean fclean