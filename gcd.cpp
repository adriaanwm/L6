#include <iostream>
#include <stdlib.h>
#include <ctime>

struct tuple {
	int x, y, gcd;
};

using namespace std;

tuple euclid_extended(int x, int y);
tuple gcd(int x, int y);

int main(int argv, char *argc[]) {
	int x;
	int y;
	clock_t start;

	if (argv != 3) return 0;

	x = atoi(argc[1]);
	y = atoi(argc[2]);

	/* start = clock(); */
	/* tuple t = euclid_extended(x, y); */
	/* cout << "Time: " << (clock() - start) / (double(CLOCKS_PER_SEC/1000)) << endl; */
	/* cout << "gcd(" << x << "," << y << ")=" << t.gcd; */
	/* cout << ", x= " << t.x << ", y= " << t.y << endl; */

	/* start = clock(); */
	/* cout << "Time: " << (clock() - start) / (double(CLOCKS_PER_SEC/1000)) << endl; */
	tuple t = gcd(x, y);
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


tuple gcd(int a, int b) {
	tuple results;
	int r = b;
	int prev_r = a;
	int s = 0;
	int prev_s = 1;
	int t = 1;
	int prev_t = 0;
	int temp;
	int quotient;
	while (r != 0) {
		quotient = prev_r / r;
		temp = prev_r;
		prev_r = r;
		r = temp - (quotient * r);
		temp = prev_s;
		prev_s = s;
		s = temp - (quotient * s);
		temp = prev_t;
		prev_t = t;
		t = temp - (quotient * t);
	}
	results.x = prev_s;
	results.y = prev_t;
	results.gcd = prev_r;
	return results;
}
