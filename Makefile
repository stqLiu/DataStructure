CC:=gcc
FLAGS=-g
FILES:=STQDataStruct.c STQrbtree.c STQSort.c STQTools.c STQTest.c
INCLUDE:= 

OBJ:= test


$(OBJ):
	$(CC) $(FILES) $(FLAGS) -o $(OBJ)

clean:
	rm test