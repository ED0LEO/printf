SRC = ft_printf.c ft_printf_utils.c ft_isdigit.c ft_putnbr_fd.c ft_putstr_fd.c ft_tolower.c ft_printf_types.c ft_shift_left.c ft_strdup.c ft_memcpy.c ft_printf_converters.c ft_prints.c ft_flags.c ft_atoi_ex.c ft_printf_utils_next.c ft_dot.c ft_dot_types.c ft_dot_types_more.c
OBJS = $(SRC:.c=.o)
CC = gcc
HEADER = ft_printf.h
DEPS = $(OBJS:.o=.d)
CFLAGS  = -Wall -Wextra -Werror
TARGET = libftprintf.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar -rc $@ $(OBJS)

.PHONY: clean fclean all re

-include .$(DEPS)

.c.o:
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

bonus: $(TARGET)