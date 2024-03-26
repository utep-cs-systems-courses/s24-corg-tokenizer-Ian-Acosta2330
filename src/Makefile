OBJS = history.o tokenizer.o uimain.o

CFLAGS= -g -O3

all: uimain

tokenizer.o:tokenizer.h
history.o:history.h
uimain.o:uimain.c history.h tokenizer.h

uimain: $(OBJS)
	cc -o $@ $^ $(CFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.c# *.c~ uimain

run: uimain
	./uimain
