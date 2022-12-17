parser_201720736:	hw3.l hw3.y
	flex hw3.l
	bison -d -b y hw3.y
	gcc -o $@ y.tab.c lex.yy.c -lfl

.PHONY: clean

clean:
	rm -rf *.tab.c *.tab.h *.yy.c parser_201720736