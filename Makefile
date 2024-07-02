# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 15:44:01 by jaehukim          #+#    #+#              #
#    Updated: 2024/06/30 22:59:33 by jaehukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADR = ./includes/push_swap.h
CC = clang
CFLAGS =  -g

LIB = ./libft/libft.a
SUBDIR = ./libft

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = 	ps_main.c \
		ps_chk_arg.c \
		ps_chk_dup_srt.c \
		ps_parse.c \
		ps_opert_swap.c \
		ps_opert_push.c \
		ps_opert_rotate.c \
		ps_opert_rrotate.c \
		ps_push_swap.c \
		ps_sort_three.c \
		ps_tim_sort.c

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) -I$(SUBDIR) -L$(SUBDIR) -lft -o $(NAME)

$(LIB) : 
	@$(MAKE) -C $(SUBDIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADR)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(SUBDIR)  -c $< -o $@

clean:
	@$(MAKE) clean -C $(SUBDIR)
	@rm -rf $(OBJS_DIR)/*.o

fclean: clean
	@$(MAKE) fclean -C $(SUBDIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
