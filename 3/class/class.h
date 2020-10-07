#ifndef __CLASS_H__
#define __CLASS_H__

#include <iostream>
#include <map>

class Money {
private:
	std::map<int, int> nominals;
	int sum;
	void initnominals();
	void renominals();
public:
	Money();
	Money(double sum);
	double getsum() const;

	Money operator+(const Money &M);
	Money operator-(const Money &M);
	Money operator/(const double n);
	Money operator*(const double n);

	bool operator>(const Money &M);
	bool operator>=(const Money &M);
	bool operator<(const Money &M);
	bool operator<=(const Money &M);
	bool operator==(const Money &M);
	bool operator!=(const Money &M);

	friend std::ostream& operator<<(std::ostream& out, const Money &M);

	~Money();
};

#endif