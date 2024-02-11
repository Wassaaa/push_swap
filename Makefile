INCLUDES		=	./includes

SRCS			=	args.c\
					commands.c\
					commands_reverse.c\
					commands_rotate.c\
					commands_push_swap.c\
					debug_prints.c\
					error.c\
					execute.c\
					find_rotations.c\
					find_stuff.c\
					ft_atol.c\
					handle_less_args.c\
					input_control.c\
					is_sorted.c\
					output.c\
					possible_rotations.c\
					push_to_a.c\
					push_to_b.c\
					quick_sort.c\
					seperate_args.c\
					simulation.c\
					single_string_args.c\
					stack.c\

B_SRCS			=	args_bonus.c\
					checker_bonus.c\
					commands_bonus.c\
					commands_push_swap_bonus.c\
					commands_reverse_bonus.c\
					commands_rotate_bonus.c\
					ft_atol_bonus.c\
					get_next_line_bonus.c\
					get_next_line_utils_bonus.c\
					input_control_bonus.c\
					seperate_args_bonus.c\
					single_string_args_bonus.c\


CC				=	gcc
CC_STRICT		=	-Wall -Wextra -Werror
CC_DEBUG		=	-g #-fsanitize=leak
CC_INCLUDES		=	-I $(LIBFT_INCLUDES) -I $(INCLUDES)
CC_FULL			=	$(CC) $(CC_STRICT) $(CC_INCLUDES) $(CC_DEBUG)


LIBFT			=	./libft/libft.a
LIBFT_DIR		=	./libft
LIBFT_INCLUDES	=	./libft


NAME			=	push_swap
SRC_DIR			=	./src
OBJECTS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
OBJ_DIR			=	./obj
ARCHIVES		=	./archives
M_MAIN			=	./main.c
M_HEADER		=	$(INCLUDES)/push_swap.h
M_ARCHIVE		=	$(ARCHIVES)/push_swap.a
M_ARCHIVES		=	$(M_ARCHIVE) $(LIBFT)


B_NAME			= 	checker
B_DIR			=	./bonus
B_OBJECTS		=	$(addprefix $(OBJ_DIR)/, $(B_SRCS:%.c=%.o))
B_MAIN			=	./main_bonus.c
B_HEADER		=	$(INCLUDES)/push_swap_bonus.h
B_ARCHIVE		=	$(ARCHIVES)/checker.a
B_ARCHIVES		=	$(B_ARCHIVE) $(LIBFT)

all: $(NAME)

$(NAME): $(LIBFT) $(M_ARCHIVE)
					$(CC_FULL) $(M_MAIN) $(M_ARCHIVES) -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_DIR)

$(M_ARCHIVE): $(OBJECTS)
					mkdir -p $(@D)
					ar rcs $(M_ARCHIVE) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
					mkdir -p $(@D)
					$(CC_FULL) -c $< -o $@

bonus: $(B_NAME)

$(B_NAME): $(LIBFT) $(B_ARCHIVE)
					$(CC_FULL) $(B_MAIN) $(B_ARCHIVES) -o $(B_NAME)

$(B_ARCHIVE): $(B_OBJECTS)
					mkdir -p $(@D)
					ar rcs $(B_ARCHIVE) $(B_OBJECTS)

$(OBJ_DIR)/%.o: $(B_DIR)/%.c
					mkdir -p $(@D)
					$(CC_FULL) -c $< -o $@

leaks: $(NAME)
	@echo "Checking for leaks (100 random numbers)..."
	@args=$$(ruby -e "\
		require 'set'; \
		nums = Set.new; \
		while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
			do nums.add(rand(-10000..10000)) \
		end; \
		puts nums.to_a.join(' ')"); \
	leaks --atExit -- ./$(NAME) $$args

tests: $(NAME)
	@echo "Generating $(filter-out $@,$(MAKECMDGOALS)) random numbers..."
	@args=$$(ruby -e "\
		require 'set'; \
		nums = Set.new; \
		while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
			do nums.add(rand(-10000..10000)) \
		end; \
		puts nums.to_a.join(' ')"); \
		echo ./push_swap $$args; \
	./push_swap $$args > file

visual: $(NAME)
	@args=$$(ruby -e "\
		require 'set'; \
		nums = Set.new; \
		while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
			do nums.add(rand(-10000..10000)) \
		end; \
		puts nums.to_a.join(' ')"); \
	./push_swap $$args | ./pro_checker $$args

test_check:
	@args=$$(ruby -e "\
		require 'set'; \
		nums = Set.new; \
		while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
			do nums.add(rand(-10000..10000)) \
		end; \
		puts nums.to_a.join(' ')"); \
	./push_swap $$args | ./checker $$args

500:
	@echo

100:
	@echo

clean:
					rm -rf $(OBJ_DIR) $(ARCHIVES)
					make clean -C $(LIBFT_DIR)
					rm -rf push_swap.dSYM/

fclean: clean
					rm -f $(NAME) $(B_NAME)
					make -C libft fclean

re: fclean all

################################################################################
# VALGRIND
################################################################################

CC_VG = $(CC) $(CC_INCLUDES) $(CC_STRICT)

VG = valgrind
VG_FLAGS = --leak-check=full --show-leak-kinds=all --trace-children=yes
VG_LOG = valgrind_leaks.log
VG_LOG_FLAGS = --log-file=$(VG_LOG) \
	--leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \
	--track-origins=yes \
	--verbose

# VG_TARGET = ./$(NAME) 2 +2147483648 3
# VG_TARGET = ./$(NAME) 1 2 2 3
# VG_TARGET = ./$(NAME) 3 2 1 3

# VG_TARGET = ./$(NAME)
# VG_TARGET = ./$(NAME) 2 1 3 6 5 8
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..1).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..2).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..3).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..4).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..5).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..6).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..7).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..8).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..9).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..10).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..11).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..20).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..50).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..100).to_a.shuffle.join(' ')")
#VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..500).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..1000).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..10000).to_a.shuffle.join(' ')")
VG_TARGET = @args=$$(ruby -e "\
		require 'set'; \
		nums = Set.new; \
		while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
			do nums.add(rand(-10000..10000)) \
		end; \
		puts nums.to_a.join(' ')"); \
		$(VG) $(VG_FLAGS) ./push_swap $$args

vg: vg_build
	$(VG_TARGET)

vglog: vg_build
	$(VG) $(VG_LOG_FLAGS) $(VG_TARGET)

vg_build: $(LIBFT) $(M_ARCHIVE)
	$(CC_VG) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VG_LOG)

.PHONY: all re clean fclean 500 100 bonus
