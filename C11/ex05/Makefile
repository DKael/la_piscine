CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs

SRCS = ${wildcard ${SRCS_DIR}/*.c}

OBJS = ${SRCS:.c=.o}

NAME = do-op

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${SRCS_DIR}/%.o :${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -c -Iincludes/ $< -o $@

all : ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f  ${NAME}

re: fclean all