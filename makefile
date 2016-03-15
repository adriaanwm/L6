CC = g++
OBJ = gcd.cpp \
			modexp.cpp

All: $(OBJ)
	$(CC) $(OBJ) -o gcd

gcd: $(OBJ)
	$(CC) gcd.cpp -o gcd

modexp: $(OBJ)
	$(CC) modexp.cpp -o modexp
