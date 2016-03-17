CC = g++
OBJ = gcd.cpp \
			modexp.cpp \
			encode.cpp

gcd: $(OBJ)
	$(CC) gcd.cpp -o gcd

modexp: $(OBJ)
	$(CC) modexp.cpp -o modexp

encode: $(OBJ)
	$(CC) encode.cpp -o encode
