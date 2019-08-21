NAME = ft_ls

LIB = libft/libft.a

SRCS = ft_filepath.c ft_opendir.c ls_flags.c ft_reverse.c main.c ft_sort.c ft_space.c ft_filechecker.c ft_timesort.c

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror $(SRCS) $(LIB) 
