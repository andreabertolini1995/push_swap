NAME = push_swap
SOURCES = main.c ft_sorting.c ft_operations.c ft_operations_in_list.c ft_operations_in_list_2.c ft_stack_utils.c ft_fill_arrays.c \
		ft_stack_utils_2.c ft_cases.c ft_print.c ft_calc_num_operations.c ft_sort_two_three_five.c ft_utils.c ft_loops.c ft_conditions.c ft_errors.c
PRINTF = ft_printf/ft_printf.a
OBJS = $(SOURCES:.c=.o)
INCLUDES = -I ft_printf/includes

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)	

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(INCLUDES) -o $(NAME)

$(PRINTF):
	make -C ft_printf

clean:
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	make -C ft_printf clean
	$(RM) $(NAME)

re: fclean $(NAME)