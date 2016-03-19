CC = g++
OBJ = gcd.cpp \
			modexp.cpp \
			encode.cpp \
			decode.cpp \
			keygen.cpp

gcd: $(OBJ)
	$(CC) gcd.cpp -o gcd

modexp: $(OBJ)
	$(CC) modexp.cpp -o modexp

encode: $(OBJ)
	$(CC) encode.cpp -o encode

decode: $(OBJ)
	$(CC) decode.cpp -o decode

keygen: $(OBJ)
	$(CC) keygen.cpp -o keygen
