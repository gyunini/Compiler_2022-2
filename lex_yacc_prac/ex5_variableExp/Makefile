variable:	variable.l variable.y
	bison -d -b y variable.y
	flex variable.l
	gcc -o $@ y.tab.c lex.yy.c -lfl

.PHONY: clean

clean:
	rm -rf *.tab.c *.tab.h *.yy.c variable