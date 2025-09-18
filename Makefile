NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I libft/srcs/includes 

RM = rm -f
RUNLIB = -C libft

SRCS = main.c \
		parse.c \
		utils.c \
		utils2.c \
		lst.c \
		ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_sort.c \
		ft_sort_2.c \
		calc_cost.c \
		ft_atol.c 

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	$(MAKE) $(RUNLIB)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)
	$(MAKE) clean $(RUNLIB)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	$(MAKE) fclean $(RUNLIB)

re: fclean all

.PHONY: all clean fclean re
