all: electroportis_glut

CC=cc
COBJS=main_glut.o ../src/ep.o ../src/gluperspective.o
CFLAGS+=-I../windows/ElectroPortis/include -I../include -Wall

ifeq ($(shell uname),IRIX64)
	# SGI IRIX 6.5 with MIPSpro and GLUT from nekoware
	CFLAGS+=-c99 -O2 -I/usr/nekoware/include
	CFLAGS+=-DOPENGL11
	LIBS+=-lm -lGL -lglut -L/usr/nekoware/lib
else
	# Linux/UNIX systems using GCC/Clang
	CFLAGS+=-Os -Wno-int-conversion
	CFLAGS+=-DOPENGL15
	ifeq ($(shell uname),Darwin)
		# Mac
		CFLAGS+=-fsanitize=address
		LIBS+=-framework OpenGL -framework GLUT
	endif
endif

OBJS=$(COBJS)

electroportis_glut: $(OBJS)
	$(CC) -Wall $(CFLAGS) $^ $(LIBS) -o $@

test: CFLAGS+=-DTEST
test: electroportis_glut

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f electroportis_glut $(COBJS)

.PHONY: clean test
