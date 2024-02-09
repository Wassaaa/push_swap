NAME			=	push_swap
bonus			= 	checker
OBJ_DIR			=	./obj
SRC_DIR			=	./src
INCLUDES		=	./includes

M_MAIN			=	./main.c
B_MAIN			=	./main_bonus.c

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



OBJECTS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

CC				=	gcc

CC_STRICT		=	-Wall -Wextra -Werror

CC_DEBUG		=	-g #-fsanitize=leak

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
	./push_swap $$args | wc -l

checker: $(NAME)
	@args=$$(ruby -e "\
		require 'set'; \
		nums = Set.new; \
		while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
			do nums.add(rand(-10000..10000)) \
		end; \
		puts nums.to_a.join(' ')"); \
	./push_swap $$args | ./checker_Mac $$args

visual: $(NAME)
	@args=$$(ruby -e "\
		require 'set'; \
		nums = Set.new; \
		while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
			do nums.add(rand(-10000..10000)) \
		end; \
		puts nums.to_a.join(' ')"); \
	./push_swap $$args | ./pro_checker $$args

500:
	@echo

100:
	@echo

clean:
					rm -rf $(OBJ_DIR) $(ARCHIVES)
					make clean -C $(LIBFT_DIR)
					rm -rf push_swap.dSYM/
					@rm -f .bonus

fclean: clean
					rm -f $(NAME)
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
VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..100).to_a.shuffle.join(' ')")
#VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..500).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..1000).to_a.shuffle.join(' ')")
# VG_TARGET = ./push_swap  $(shell ruby -e "puts (1..10000).to_a.shuffle.join(' ')")

vg: vg_build
	$(VG) $(VG_FLAGS) $(VG_TARGET)

vglog: vg_build
	$(VG) $(VG_LOG_FLAGS) $(VG_TARGET)

vg_build: $(LIBFT) $(M_ARCHIVE)
	$(CC_VG) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VG_LOG)

.PHONY: all re clean fclean 500 100
