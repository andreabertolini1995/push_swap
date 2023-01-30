NAME = push_swap

SOURCES = ft_stack_utils.c main.c

PRINTF = ft_printf/ft_printf.a

LIBFT = libft/libft.a

OBJS = $(SOURCES:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)	

$(NAME): $(PRINTF) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)