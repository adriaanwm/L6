// gpruesse@wolf:~/Lab6$./encode filename 191 11314200 
// Creating file named filename.encoded... 

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argv, char *argc[]) {
	if (argv != 4) return 0;

	string file(argc[1]);
	int key1 = atoi(argc[1]);
	int key2 = atoi(argc[2]);

	cout << "Creating file named " << file << ".encoded..." << endl;
	
	return 0;
}
