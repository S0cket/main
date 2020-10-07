#include <iostream>
#include <math.h>

using namespace std;

class Vector {
private:
	double _x, _y, _z;
public:
	Vector() {
		this->_x = 0;
		this->_y = 0;
		this->_z = 0;
	}

	Vector(double x, double y, double z) {
		this->_x = x;
		this->_y = y;
		this->_z = z;
	}

	void print() const {
		std::cout << "<Vector x=" << this->_x
			<< " y=" << this->_y
			<< " z=" << this->_z << ">";
	}

	double length() const {
		return sqrt(pow(this->_x, 2) + pow(this->_y, 2) + pow(this->_z, 2));
	}

	double x() const {
		return this->_x;
	}
	double y() const {
		return this->_y;
	}
	double z() const {
		return this->_z;
	}
	void x(double x) {
		this->_x = x;
	}
	void y(double y) {
		this->_y = y;
	}
	void z(double z) {
		this->_z = z;
	}

	Vector operator+(const Vector &V) const {
		return Vector(this->x() + V.x(),
			this->y() + V.y(),
			this->z() + V.z());
	}
	double operator%(const Vector &V) const {
		return this->x() * V.x() + this->y() * V.y() + this->z() * V.z();
	}
	Vector operator*(const Vector &V) const {
		double x = this->y() * V.z() - this->z() * V.y();
		double y = this->z() * V.x() - this->x() * V.z();
		double z = this->x() * V.y() - this->y() * V.x();
		return Vector(x, y, z);
	}
	double operator/(const Vector &V) const {
		return acos((*this % V) / (this->length() * V.length()));
	}

	friend std::ostream& operator<<(std::ostream &out, const Vector &V);

	~Vector() {}

};

std::ostream& operator<<(std::ostream &out, const Vector &V) {
	out << "<Vector x=" << V.x()
		<< " y=" << V.y()
		<< " z=" << V.z() << ">";
	return out;
}

int main(void) {
	Vector a(4, 7, 9), b(3, 5, 7), c = a * b;
	cout << a << endl << b << endl << c << endl;
	return 0;
}