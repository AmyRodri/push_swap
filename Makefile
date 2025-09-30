NAME        = push_swap
NAME_BONUS  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDE     = -I libft/srcs/includes -I include

RM          = rm -f
RUNLIB      = -C libft

# Diretórios
SRCSDIR         = srcs
SRCSDIR_BONUS   = srcs_bonus
OBJDIR          = objs

# Fontes normais
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
       calc_cost.c 

# Fontes bônus
SRCS_BONUS = checker.c \
             parse.c \
             utils.c \
             utils2.c \
             lst.c \
             ft_swap.c \
             ft_push.c \
             ft_rotate.c \
             ft_reverse_rotate.c \
			 cath_the_moves.c

# Adiciona prefixo do diretório
SRCS        := $(addprefix $(SRCSDIR)/, $(SRCS))
SRCS_BONUS  := $(addprefix $(SRCSDIR_BONUS)/, $(SRCS_BONUS))

# Objetos
OBJS        = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS  = $(addprefix $(OBJDIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

# Lib
LIBFT = libft/libft.a

# ---------- Regras ----------
all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

# regra para compilar arquivos normais
$(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# regra para compilar arquivos bônus
$(OBJDIR)/%.o: $(SRCSDIR_BONUS)/%.c | $(OBJDIR)
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
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) fclean $(RUNLIB)

re: fclean all

.PHONY: all bonus clean fclean re
