#include "class.h"

using namespace std;

int main(void) {
	Vector a(4, 7, 9), b(3, 5, 7), c = a * b;
	cout << a << endl << b << endl << c << endl;
	return 0;
}