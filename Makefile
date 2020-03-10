CC = gcc

RM = rm -rf

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_len.c	\
		ft_print_char.c \
		ft_print_int.c \
		ft_print_hex.c \
		ft_print_pointer.c \
		ft_len.c \
		ft_print_str.c \
		ft_speci.c \

OBJS = ft_printf.o \
		ft_len.o	\
		ft_print_char.o \
		ft_print_int.o \
		ft_print_hex.o \
		ft_print_pointer.o \
		ft_len.o \
		ft_print_str.o \
		ft_speci.o \

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all