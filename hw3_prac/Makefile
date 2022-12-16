parser_201720736:	hw3_1.l hw3_1.y
	flex hw3_1.l
	bison -d -b y hw3_1.y
	gcc -o $@ y.tab.c lex.yy.c -lfl

.PHONY: clean

clean:
	rm -rf *.tab.c *.tab.h *.yy.c parser_201720736