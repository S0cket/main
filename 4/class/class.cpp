#include "class.h"

Vector::Vector() {
	this->_x = 0;
	this->_y = 0;
	this->_z = 0;
}

Vector::Vector(double x, double y, double z) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

void Vector::print() const {
	std::cout << "<Vector x=" << this->_x
		<< " y=" << this->_y
		<< " z=" << this->_z << ">";
}

double Vector::length() const {
	return sqrt(pow(this->_x, 2) + pow(this->_y, 2) + pow(this->_z, 2));
}

double Vector::x() const {
	return this->_x;
}
double Vector::y() const {
	return this->_y;
}
double Vector::z() const {
	return this->_z;
}

void Vector::x(double x) {
	this->_x = x;
}
void Vector::y(double y) {
	this->_y = y;
}
void Vector::z(double z) {
	this->_z = z;
}

Vector Vector::operator+(const Vector &V) const {
	return Vector(this->x() + V.x(),
		this->y() + V.y(),
		this->z() + V.z());
}

double Vector::operator%(const Vector &V) const {
	return this->x() * V.x() + this->y() * V.y() + this->z() * V.z();
}

Vector Vector::operator*(const Vector &V) const {
	double x = this->y() * V.z() - this->z() * V.y();
	double y = this->z() * V.x() - this->x() * V.z();
	double z = this->x() * V.y() - this->y() * V.x();
	return Vector(x, y, z);

}

double Vector::operator/(const Vector &V) const {
	return acos((*this % V) / (this->length() * V.length()));
}

std::ostream& operator<<(std::ostream &out, const Vector &V) {
	out << "<Vector x=" << V.x()
		<< " y=" << V.y()
		<< " z=" << V.z() << ">";
	return out;
}

Vector::~Vector() {}