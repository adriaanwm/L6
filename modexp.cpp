#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

long long modexp(long long a, long long b, long long c);

void get_input(int *a, int *b, int *c);

int main() {
	long long a, b, n;
	get_input(&a, &b, &n);
	long long answer = modexp(a, b, n);

	cout << a << "^" << b << " mod "<< n << " = ";
	cout << answer << endl; 

	return 0;
}

void get_input(long long *a, long long *b, long long *n) {
	long long arr[3];
	string args;

	cout << "Enter the values of a b and n to compute a^b mod n: ";
	getline(cin, args);

	stringstream ssin(args);
	int i = 0;
	string temp;

	while (ssin.good() && i < 3) {
		ssin >> temp;
		arr[i] = stol(temp);
		i ++;
	}

	*a = arr[0];
	*b = arr[1];
	*n = arr[2];

}

long long modexp(long long a, long long b, long long n) {
	long long pow = 1;
	for (int i = 0; i < b; i++)
		pow *= a;
	return pow % n;
}
