// gpruesse@wolf:~/Lab8$./decode filename -3085456 11314200 
// Creating file named filename.decoded... 

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

long long modexp(long long a, long long b, long long c);

int main(int argv, char *argc[]) {
	if (argv != 4) return 0;

	char *file_name = argc[1];
	long long e = atol(argc[2]);
	long long n = atol(argc[3]);
	const char *encoded_extention = ".decoded";

	char * encoded_file = (char *) malloc(1 + strlen(file_name)+ strlen(encoded_extention) );
	strcpy(encoded_file, file_name);
	strcat(encoded_file, encoded_extention);

	printf("Creating file named %s.decoded...", file_name);

	char y = 'y';
	int yi = y;

	// read file
	ifstream f;
	ofstream of;
	f.open(file_name);
	of.open(encoded_file);
	if (!f) { 
		cerr << "File not openable. " << endl; return 0; 
	}
	if (!of) { 
		cerr << "Output file not openable. " << endl; return 0; 
	}
	char c;
	long long ci;
	string word;
	long long code;

	while (f >> word) {
		code = stoll(word);
		of << (char)modexp(code, e, n);
	}
	
	return 0;
}

long long modexp(long long base, long long exponent, long long n) {
	if (n == 1) return 0;
	long long result = 1;
	base = base % n;

	while (exponent > 0) {
		if (exponent % 2 == 1)
			result = result * base % n;
		exponent = exponent >> 1; // divide by 2
		base = base * base % n;
	}

	return result;

}


