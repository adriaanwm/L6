#include <iostream>
#include <stdlib.h>

struct tuple {
	int x, y, gcd;
};

using namespace std;

tuple euclid_extended(int x, int y);

int main(int argv, char *argc[]) {
	int x;
	int y;

	if (argv != 3) return 0;

	x = atoi(argc[1]);
	y = atoi(argc[2]);

	tuple t = euclid_extended(x, y);

	cout << "gcd(" << x << "," << y << ")=" << t.gcd;
	cout << ", x= " << t.x << ", y= " << t.y << endl;
  
	return 0;
}

tuple euclid_extended(int x, int y) {
	int v1, v2;
	tuple t;

	// int ys_in_x = (x - (x % y)) / y;
	int ys_in_x = x / y;

	// if next remainder is 0, we're done
	if (y % (x % y) == 0) {
		t.gcd = (x % y);
		t.x = 1;
		t.y = (-1 * ys_in_x);
		return t;
	}

	t = euclid_extended(y, x % y);
	v1 = t.y;
	v2 = (-1 * ys_in_x) * t.y + t.x;
	
	t.x = v1;
	t.y = v2;

	return t;
}


