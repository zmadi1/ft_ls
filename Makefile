NAME = ft_ls

LIB = libft/libft.a

SRCS = ft_changer.c ft_argument_counterfunc.c array_counter.c ft_count.c ft_filepath.c ft_opendir.c ls_flags.c ft_reverse.c main.c ft_sort.c ft_space.c ft_filechecker.c ft_timesort.c
OBJ = ft_changer.o ft_argument_counterfunc.o array_counter.o ft_count.o ft_filepath.o ft_opendir.o ls_flags.o ft_reverse.o main.o ft_sort.o ft_space.o ft_filechecker.o ft_timesort.o
all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRCS) $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(NAME)

re: fclean all

