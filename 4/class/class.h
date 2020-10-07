#ifndef __CLASS_H__
#define __CLASS_H__

#include <iostream>
#include <math.h>

class Vector {
private:
	double _x, _y, _z;
public:
	Vector();
	Vector(double x, double y, double z);

	void print() const;
	double length() const;

	double x() const;
	double y() const;
	double z() const;
	void x(double x);
	void y(double y);
	void z(double z);

	Vector operator+(const Vector &V) const;
	double operator%(const Vector &V) const;
	Vector operator*(const Vector &V) const;
	double operator/(const Vector &V) const;

	friend std::ostream& operator<<(std::ostream &out, const Vector &V);

	~Vector();

};

#endif