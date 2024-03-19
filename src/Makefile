OBJS=tokenizer.o history.o  uimain.o
CFLAGS=-g -03
all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS)$(OBJS)
	cc -o history

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenize
	rm -f *.o history

run: tokenize
	./tokenize
