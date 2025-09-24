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
		calc_utils.c \
		ft_atol.c 

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

# regra para compilar .c em .o dentro de objs/
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# cria a pasta objs se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) $(RUNLIB)

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) clean $(RUNLIB)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	$(MAKE) fclean $(RUNLIB)

re: fclean all

.PHONY: all clean fclean re
