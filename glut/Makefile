all: electroportis_glut

CC=cc
COBJS=main_glut.o ../src/ep.o
CFLAGS+=-I../windows/ElectroPortis/include -I../include -Wall -Os -Wno-int-conversion

ifeq ($(shell uname),Darwin)
	# Mac
	CFLAGS+=-arch i386
	LIBS+=-framework OpenGL -framework GLUT
else
	# Linux/Unix
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
