COPTS=-Wall -g -c  -O0 -std=c++11
OBJS=main.o \
	 langlex.o \
	 SymbolTable.o \
	 HashTable.o \
	 Symbol.o \
	 langparse.o \
	 PrintNode.o \
	 BlockNode.o \
	 StmtsNode.o \
	 FloatNode.o \
	 IntNode.o \
	 ExprNode.o \
	 BinaryExprNode.o \
	 DeclsNode.o \
	 VarDecl.o \
	 StmtNode.o \
	 FuncCall.o \
	 ParamsNode.o \
	 ReturnNode.o \
	 IfStmt.o \
	 ScanStmt.o \
	 IfElseStmt.o \
	 WhileStmt.o \
	 AssignStmt.o \
	 StructDecl.o \
	 FuncHeader.o \
	 FuncPrefix.o \
	 FuncDef.o \
	 FuncDecl.o \
	 Paramsspec.o \
	 ArraySpec.o \
	 ArrayVal.o \
	 VarPart.o \
	 VarRef.o

all: lang

clean:
	rm -f $(OBJS)
	rm -f langlex.c
	rm -f langparse.c
	rm -f langparse.h
	rm -f lang
	rm -f out

.cpp.o:
	g++ $(COPTS) $? -o $@

.c.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langparse.c langlex.c
	g++ $(COPTS) main.cpp -o $@

langparse.c: lang.y
	bison --defines=langparse.h lang.y -o langparse.c

lang: $(OBJS)
	g++ $(OBJS) -o lang

langlex.c: lang.l
	flex -o langlex.c lang.l

langlex.o: langlex.c
	g++ $(COPTS) -Wno-sign-compare langlex.c -o $@

SymbolTable.o: SymbolTable.cpp
	g++ $(COPTS) -Wno-sign-compare SymbolTable.cpp -o $@
