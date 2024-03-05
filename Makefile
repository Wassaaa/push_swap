# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 05:08:26 by aklein            #+#    #+#              #
#    Updated: 2024/03/05 16:15:49 by aklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES		=	./include

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
					input_control_bonus.c\
					seperate_args_bonus.c\
					single_string_args_bonus.c\


################################################################################
# COMPILATION
################################################################################
CC				=	cc
CC_STRICT		=	-Wall -Wextra -Werror
CC_DEBUG		=	#-g #-fsanitize=leak
CC_INCLUDES		=	-I $(LIBFT_INCLUDES) -I $(INCLUDES)
CC_FULL			=	$(CC) $(CC_STRICT) $(CC_INCLUDES) $(CC_DEBUG)

################################################################################
# LIBFT
################################################################################

LIBFT			=	./libft/libft.a
LIBFT_DIR		=	./libft
LIBFT_INCLUDES	=	./libft/include

################################################################################
# MANDATORY
################################################################################
NAME			=	push_swap
SRC_DIR			=	./src
OBJECTS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
OBJ_DIR			=	./obj
ARCHIVES		=	./archives
M_MAIN			=	./main.c
M_HEADER		=	$(INCLUDES)/push_swap.h
M_ARCHIVE		=	$(ARCHIVES)/push_swap.a
M_ARCHIVES		=	$(M_ARCHIVE) $(LIBFT)

################################################################################
# BONUS
################################################################################
B_NAME			= 	checker
B_DIR			=	./bonus
B_OBJECTS		=	$(addprefix $(OBJ_DIR)/, $(B_SRCS:%.c=%.o))
B_MAIN			=	./main_bonus.c
B_HEADER		=	$(INCLUDES)/push_swap_bonus.h
B_ARCHIVE		=	$(ARCHIVES)/checker.a
B_ARCHIVES		=	$(B_ARCHIVE) $(LIBFT)

################################################################################
# RULES
################################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(M_ARCHIVE) $(M_MAIN)
					$(CC_FULL) $(M_MAIN) $(M_ARCHIVES) -o $(NAME)

$(LIBFT): libft_force
					make -C $(LIBFT_DIR)

libft_force:
					@true

$(M_ARCHIVE): $(OBJECTS) 
					mkdir -p $(@D)
					ar rcs $(M_ARCHIVE) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(M_HEADER)
					mkdir -p $(@D)
					$(CC_FULL) -c $< -o $@

bonus: $(B_NAME)

$(B_NAME): $(LIBFT) $(B_ARCHIVE) $(B_MAIN)
					$(CC_FULL) $(B_MAIN) $(B_ARCHIVES) -o $(B_NAME)

$(B_ARCHIVE): $(B_OBJECTS)
					mkdir -p $(@D)
					ar rcs $(B_ARCHIVE) $(B_OBJECTS)

$(OBJ_DIR)/%.o: $(B_DIR)/%.c $(B_HEADER)
					mkdir -p $(@D)
					$(CC_FULL) -c $< -o $@

clean:
					rm -rf $(OBJ_DIR) $(ARCHIVES)
					make clean -C $(LIBFT_DIR)

fclean: clean
					rm -f $(NAME) $(B_NAME)
					make fclean -C $(LIBFT_DIR)

re: fclean all

################################################################################
# TESTING
################################################################################

leaks:
					@echo "Checking for leaks \
					($(filter-out $@,$(MAKECMDGOALS)))..."
					$(RUBY_ARGS)\
					echo "leaks --atExit -- ./push_swap $$args\n";\
					leaks --atExit -- ./push_swap $$args

tests:
					@echo "Generating \
					$(filter-out $@,$(MAKECMDGOALS)) random numbers..."
					$(RUBY_ARGS)\
					echo "./push_swap $$args | wc -l\n";\
					./push_swap $$args | wc -l

visual:
					@echo "Generating \
					$(filter-out $@,$(MAKECMDGOALS)) random numbers..."
					$(RUBY_ARGS)\
					echo "./push_swap $$args | ./pro_checker $$args\n";\
					./push_swap $$args | ./pro_checker $$args

check:
					@echo "Generating \
					$(filter-out $@,$(MAKECMDGOALS)) random numbers..."
					$(RUBY_ARGS)\
					echo "./push_swap $$args | ./checker $$args\n";\
					./push_swap $$args | ./checker $$args

$(shell seq 1 1000):	
					@:
					
RUBY_ARGS		= 	@args=$$(ruby -e "\
						require 'set'; \
						nums = Set.new; \
						while nums.size < $(filter-out $@,$(MAKECMDGOALS)) \
							do nums.add(rand(-10000..10000)) \
						end; \
						puts nums.to_a.join(' ')");\

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

LOG_VG_TARGET = $(RUBY_ARGS)\
		$(VG) $(VG_LOG_FLAGS) ./push_swap $$args

VG_TARGET = $(RUBY_ARGS)\
		$(VG) $(VG_FLAGS) ./push_swap $$args

vg: vg_build
	$(VG_TARGET)

vglog: vg_build
	$(LOG_VG_TARGET)

vg_build: $(LIBFT) $(M_ARCHIVE)
	$(CC_VG) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		-o $(NAME)

vglog_clean: fclean
	rm -f $(VG_LOG)

.PHONY: all re clean fclean bonus libft_force

################################################################################
# NORM
################################################################################

norm: 
	norminette $(SRC_DIR) $(B_DIR) $(INCLUDES) $(LIBFT_DIR) | grep -v "OK!" || true

norm2: 
	norminette $(SRC_DIR) $(B_DIR) $(INCLUDES) $(LIBFT_DIR)

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m
