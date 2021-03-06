PROJECT = sandbox

CC = cc
SRC = src/main.c src/image.c src/mandelbrot.c
OBJ = ${SRC:.c=.o}
LIBS = -lm
CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations 
BINARY = bin/${PROJECT}

.c.o:
	${CC} -c ${CFLAGS} $<

main: ${OBJ}
	${CC} -o ${BINARY} *.o ${LIBS}

clean:
	@echo "Cleaning Executables ..."
	@rm *.o
	rm ${BINARY}