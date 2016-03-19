#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int modInverse(long n, long p);

int main(int argv, char *argc[]) {
	long p1 = 20477;
	long p2 = 32353;
	long n = p1 * p2;
	long e = 1327;
	long d = modInverse(e, (p1 - 1) * (p2 - 1));

	cout << "e: " << e << endl;
	cout << "d: " << d << endl;
	cout << "n: " << n << endl;

	return 0;
}

int modInverse(long n, long p) {
    n = n % p;
    for(int x = 1; x < p; x++) 
        if(n*x % p == 1) return x;
    return 0;
}
