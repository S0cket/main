#include <iostream>
#include <math.h>

using namespace std;

typedef struct {
	int cnt;
	double x1, x2;
}roots;

class Circle;

class Line {
	// y = ax + b
private:
	double a, b;
public:
	Line() {
		this->a = 0;
		this->b = 0;
	}
	Line(double a, double b) {
		this->a = a;
		this->b = b;
	}
	double operator()(double x) {
		return a * x + b;
	}
	~Line() {}
	friend roots func(Line L, Circle C);
};

class Circle {
	//(x - a)^2 + (y - b)^2 = r^2
private:
	double a, b, r;
public:
	Circle() {
		this->a = 0;
		this->b = 0;
		this->r = 1;
	}
	Circle(double a, double b, double r) {
		this->a = a;
		this->b = b;
		this->r = r;
	}
	~Circle() {}
	friend roots func(Line L, Circle C);
};

roots func(Line L, Circle C) {
	double m = L.b - C.b;
	//ax^2 + bx + c = 0
	double a = pow(L.a, 2) + 1;
	double b = -(2 * C.a + 2 * L.a * m);
	double c = pow(C.a, 2) + pow(m, 2) - pow(C.r, 2);

	double d = pow(b, 2) - 4 * a * c;
	if (d < 0) {
		roots ret = {0, 0, 0};
		return ret;
	}
	else {
		int cnt = (d == 0) ? 1 : 2;
		double x1 = (-b + sqrt(d)) / (2 * a);
		double x2 = (-b - sqrt(d)) / (2 * a);
		roots ret = {cnt, x1, x2};
		return ret;
	}
}

int main(void) {
	double a, b, r;

	cout << "Input a, b, r for Circle:\n";
	cin >> a >> b >> r;
	Circle c(a, b, r);

	cout << "Input a, b for Line:\n";
	cin >> a >> b;
	Line l(a, b);

	roots res = func(l, c);
	cout << "\n\n";
	if (res.cnt == 0) {
		cout << "No roots";
	}
	else if (res.cnt == 1) {
		cout << "1 root: (" << res.x1 << "; " << l(res.x1) << ")";
	}
	else {
		cout << "2 roots: (" << res.x1 << "; " << l(res.x1) << "), " << "(" << res.x2 << "; " << l(res.x2) << ")";
	}
	cout << "\n";
	return 0;
}