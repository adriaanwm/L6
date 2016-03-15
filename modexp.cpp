#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main() {
	string args;
	int arr[3];

	cout << "Enter the values of a b and n to compute a^b mod n: ";
	getline(cin, args);

	stringstream ssin(args);
	int i = 0;
	string temp;

	while (ssin.good() && i < 3) {
		ssin >> temp;
		arr[i] = stoi(temp);
		i ++;
	}

	int pow = 1;
	for (int i = 0; i < arr[1]; i++)
		pow *= arr[0];

	cout << arr[0] << "^" << arr[1] << " mod "<< arr[2] << " = ";
	cout << pow % arr[2] << endl; 


	return 0;
}
