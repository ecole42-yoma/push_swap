# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 18:25:02 by yongmkim          #+#    #+#              #
#    Updated: 2022/10/17 15:45:34 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 	Target Name
NAME		=	push_swap
NAME_B		=	checker

#	Compile
CC			=	gcc
CC_FLAG		=	-Wall -Wextra -Werror
RM			=	rm
RM_FLAG		=	-f
SNTZ		=	-g3 -fsanitize=address
DEBUG		=	-g
HDR_M		=	-I.
HDR_B		=	-I.
OBJ			=	$(SRC:.c=.o)
OBJ_M		=	$(SRC_M:.c=.o)
OBJ_B		=	$(SRC_B:.c=.o)

#	Library
LIBFT_DIR	=	./libft/
LIBFT_FLAG	=	-L$(LIBFT_DIR) -lft

#	Source
SRC			=	ps_atob.c			\
				ps_btoa.c			\
				util_parse.c		\
				util_error.c		\
				util_list_print.c	\
				util_op_print.c		\
				util_pivot.c		\
				util_small_sort.c	\
				util_small_sort_proc.c	\
				util_small_sort_rra.c	\
				util_small_sort_rra_proc.c	\
				util_sort.c			\
				util_option_detail.c\
				util_parse_opt.c	\
				util_op_optimize.c	\
				op_swap.c			\
				op_push.c			\
				op_rotate.c			\
				op_reverse_rotate.c	\

SRC_M		=	ps_main.c			\

SRC_B		=	bonus_checker.c		\


# OBJECT	=	$(OBJ_B)
# DIR		=	$(HDR_B)
#	Bonus
ifdef WITH_BONUS
	OBJECT	=	$(OBJ) $(OBJ_B)
	DIR		=	$(HDR_M)
else
	OBJECT	=	$(OBJ) $(OBJ_M)
	DIR		=	$(HDR_M)
endif

#	Sanitize
ifdef WITH_SNTZ
	CFLAG	=	$(CC_FLAG) $(SNTZ)
else
	CFLAG	=	$(CC_FLAG)
endif

#	Debug : -g
ifdef WITH_DEBUG
	CFLAG	=	$(CC_FLAG) $(DEBUG)
else
	CFLAG	=	$(CC_FLAG)
endif

#	Color
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
ORANGE		=	\e[38;5;214m
BLUE_PURPLE	=	\e[38;5;057m
PURPLE		=	\e[38;5;165m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(ORANGE)INFO$(RESET)]
_NAME		=	[$(GREEN)$(NAME)$(RESET)]
_NAME_B		=	[$(GREEN)  $(NAME_B)$(RESET)]
_PROG		=	$(_INFO) [$(ORANGE)$(NAME)$(RESET)] - Compile $(YELLOW)
_DONE		=	$(GREEN)✓$(RESET)

#	Loading bar
SHELL	=	/bin/bash
sp		=	/-\|/
idx		=	0




#	Make  ======================================================================

all			:	$(NAME)

$(NAME)		:	$(OBJECT)
		@printf "\b$(_DONE)\n"
		@$(MAKE) -C $(LIBFT_DIR)
		@$(CC) -g3 $(CFLAG) $(LIBFT_FLAG) $(DIR) $(OBJECT) -o $(NAME)
		@printf "$(_SUCCESS) $(_NAME) - all $(_DONE)\n"

%.o			:	%.c
		$(eval idx = $(shell expr $(idx) + 1))
		$(eval t_idx = $(shell expr $(idx) % 4 + 1))
		$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
		@if [ $(idx) = 1 ]; then\
			printf "   $(_PROG) ";\
		fi
		@printf "\b$(chr)"
		@$(CC) -g3 $(CC_FLAG) -o $@ -c $<

clean		:
		@$(MAKE) -C $(LIBFT_DIR) clean
		@$(RM) $(RM_FLAG) $(OBJECT) $(OBJ_B)
		@printf "   $(_INFO) $(_NAME) - clean $(_DONE)\n"

fclean		:
		@$(MAKE) -C $(LIBFT_DIR) fclean
		@$(RM) $(RM_FLAG) $(OBJECT) $(OBJ_B) $(NAME) $(NAME_B)
		@printf "   $(_INFO) $(_NAME) - fclean $(_DONE)\n"

re			:	fclean all

bonus		:	$(NAME_B)

$(NAME_B)	:	$(OBJ) $(OBJ_B)
		@printf "\b$(_DONE)\n"
		@$(MAKE) -C $(LIBFT_DIR)
		@$(CC) $(CFLAG) $(LIBFT_FLAG) $(DIR) $(OBJ) $(OBJ_B) -o $(NAME_B)
		@printf "$(_SUCCESS) $(_NAME_B) - bonus $(_DONE)\n"

sntz		:
		@make WITH_SNTZ=1 all
		@printf "   $(_INFO) $(_NAME) with sntz - $(_DONE)\n"

debug		:
		@make WITH_DEBUG=1 all
# @gcc -g -Wall -Wextra -Werror -L./libft/ -lft $(OBJECT) -o $(NAME)
# @gcc -g -Wall -Wextra -Werror -L./libft/ -lft $(OBJECT) -o $(NAME)
		@printf "   $(_INFO) $(_NAME) with debug - $(_DONE)\n"

lldb		:	debug

b			:	bonus

m			:	all

clear		:	clean

fclear		:	fclean

.PHONY		:	all clean fclean re bonus b m sntz debug lldb clear
