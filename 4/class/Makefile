CC=g++
CLASS=class
MAIN=main
SRC=cpp
OBJ=obj

$(MAIN): $(CLASS).$(OBJ) $(MAIN).$(OBJ)
	@echo "Linking"
	@$(CC) $(MAIN).$(OBJ) $(CLASS).$(OBJ)

$(CLASS).$(OBJ): $(CLASS).$(SRC)
	@echo "Compiling $(CLASS).$(SRC)"
	@$(CC) -c $(CLASS).$(SRC) -o $(CLASS).$(OBJ)

$(MAIN).$(OBJ): $(MAIN).$(SRC)
	@echo "Compiling $(MAIN).$(SRC)"
	@$(CC) -c $(MAIN).$(SRC) -o $(MAIN).$(OBJ)