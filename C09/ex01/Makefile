CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs

SRCS = ${SRCS_DIR}/ft_putchar.c ${SRCS_DIR}/ft_swap.c ${SRCS_DIR}/ft_putstr.c ${SRCS_DIR}/ft_strlen.c ${SRCS_DIR}/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

TARGET = libft.a

${TARGET} : ${OBJS}
	ar rsc ${TARGET} ${OBJS}

${SRCS_DIR}/ft_putchar.o :${SRCS_DIR}/ft_putchar.c
	${CC} ${CFLAGS} -c -I./includes/ $< -o $@

${SRCS_DIR}/ft_swap.o :${SRCS_DIR}/ft_swap.c
	${CC} ${CFLAGS} -c -I./includes/ $< -o $@

${SRCS_DIR}/ft_putstr.o :${SRCS_DIR}/ft_putstr.c
	${CC} ${CFLAGS} -c -I./includes/ $< -o $@

${SRCS_DIR}/ft_strlen.o :${SRCS_DIR}/ft_strlen.c
	${CC} ${CFLAGS} -c -I./includes/ $< -o $@

${SRCS_DIR}/ft_strcmp.o :${SRCS_DIR}/ft_strcmp.c
	${CC} ${CFLAGS} -c -I./includes/ $< -o $@

all : ${TARGET}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f  ${TARGET}

re: fclean all
