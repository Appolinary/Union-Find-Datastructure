src = $(wildcard *.c)
obj = $(src:.c=.o)

myprog : $(obj)
	gcc $^ -o $@

.PHONY: clean
.PHONY: run

clean:
	rm *.o myprog
run: 
	./myprog
