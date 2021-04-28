NAME = getline
HEADER_PATH = ./
SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -I ${HEADER_PATH} -D BUFFER_SIZE=4096
RAN = ranlib
ARFLAGS = rc
TMP = ${SRCS:.c=.c~}
DEPS = ${SRCS} ${HEADERS} Makefile

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

${NAME}: ${OBJS} ${DEPS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}
clean:
	${RM} ${TMP}
fclean: clean
	${RM} ${OBJS}
	${RM} ${NAME}
	${RM} ${BNS_OBJS}
re: fclean all
