#include <iostream>
#include <stdlib.h>

struct tuple {
	int x, y, gcd;
};

using namespace std;

int gcd(int x, int y);

void gcd_extended(int x, int y, int *xl, int *yl, int *gcd); 
void gcd_2(int x, int y, int *xl, int *yl, int *gcd); 
tuple fun (int x, int y);

int main(int argv, char *argc[]) {
	int x;
	int y;

	if (argv != 3) return 0;

	x = atoi(argc[1]);
	y = atoi(argc[2]);

	int xl, yl, gcd;
	// gcd_extended(x, y, &xl, &yl, &gcd);
	// cout << "gcd(" << x << "," << y << ")=" << gcd;
	// cout << ", x= " << xl << ", y= " << yl << endl;
  //
	// gcd_2(x, y, &xl, &yl, &gcd);
	tuple t = fun (x, y);

	cout << "gcd(" << x << "," << y << ")=" << t.gcd;
	cout << ", x= " << t.x << ", y= " << t.y << endl;
  
	return 0;
}

int gcd(int x, int y) {
	int r;

	do {
		r = x % y;
		x = y;
		y = r;
	} while (r > 0);

	return x;
}


void gcd_extended(int x, int y, int *xl, int *yl, int *gcd) {
	struct node {
		node *next;
		node *prev;
		int value;
		int a, b, bm;
	};
	int r;
	node *head = new node();
	node *curr = head;

	do {
		r = x % y;

		curr->next = new node();
		curr->next->prev = curr;
		curr = curr->next;

		curr->value = r;
		curr->a = x;
		curr->b = y;
		curr->bm = -1 * (x-r) / y;

		x = y;
		y = r;
	} while (r > 0);

	curr = curr->prev;
	cout << curr->value << endl;
	*gcd = curr->value;

	*xl = 1; 
	*yl = curr->bm; 
	int temp;
	curr = curr->prev;

	while (curr->prev) {
		cout << "xl: " << *xl << endl;
		cout << "yl: " << *yl << endl;
		cout << "bm: " << curr->bm << endl;

		temp = *xl;
		*xl = *yl;
		*yl = temp + (curr->bm * *yl);
		curr = curr->prev;
	}

}

void gcd_2(int x, int y, int *xl, int *yl, int *gcd) {
	int r;
	int v1 = 1;
	int v2 = 1;
	int m = 1;
	int temp;

	do {
		r = x % y;
		m = - (x-r) / y;

		temp = v1;
		v1 = v2;
		v2 = temp + (m * v2);

		cout << "v1: " << v1 << endl;
		cout << "v2: " << v2 << endl;
		cout << "m: " << m << endl;

		x = y;
		y = r;
	} while (r > 0);
}


/**
 * 9 = 5 * 1 + 4
 * 5 = 4 * 1 + 1
 *
 * 1 = 5 * 1 + 4 * -1
 * 	= 5 * 1 + ( 9  - 5 * 1) *-1/
 *	= 9 * -1 + 5 * 2
 */
tuple euclid_extended(int x, int y) {
	int v1, v2;
	
	tuple t;

	if (y % (x % y) == 0) {
		t.gcd = (x % y);
		t.x = 1;
		t.y = (-1 * (x - (x % y)) / y);
		return t;
	}

	t = fun(y, x % y);
	v1 = t.y;
	v2 = (-1 * (x - (x % y)) / y) * t.y + t.x;
	
	t.x = v1;
	t.y = v2;

	return t;
}


/**
 * x*a + y*b = gcd
 * gcd = v1*n1 + v2*n2
 *
 * a			b  c		d
 * 144 = 122*1  + 22
 * 122 = 22 *5  + 2
 * 22  = 2  *11 +0
 *
 * 2 = 122 - 22*5
 *	 = 122 - (155-122*1)*5
 *	 = 122*6 - 155*5
 */

// 41, 173
//
// 173 = 41 * 4 + 9
// 41  = 9  * 4 + 5
// 9		= 5  * 1 + 4
// 5		= 4	 * 1 + 1
//
// 9,5
//
//
//
// 1 = 5 - 4 * 1
//   = 5 - (9 - 5)
// 	= (41 - 9*4) - (9 - (41 - 9*4))
// 	= (41 - (173 - 41*4)*4) - ((173 - 41*4) - (41 - (173 - 41*4)*4)) 
//
// 	1 = 5 * 1 + 4 * -1
//		= 5 * 1 + (9 - 5) * -1
//		= -9 * 1 + 5 * 2
//		= -9 * 1 + (41 - 9*4)*2
//		= 41 *2 + 9*-9
//		= 41*2  + (173-41*4)*-9
//		=	173*-9 + 41*38 
//
// 	1 = x * 1 + x * -1
//		= x * 1 + (x + x(-1)) * -1
//		= x * 1 + x * 2
//		= x * 1 + (x + x(-4)) * 2
//		= x * 2 + x *-9
//		= x * 2 + (x + x(4))*-9
//		=	x *-9 + x * 38 
//
//		v1 = -9 = 2 * -4 + 1 = 
//
//		-1 * -1 +
//
//					v1          bm		v2
//		= 9 * -1 + (41 + 9*-4) * 2
//
