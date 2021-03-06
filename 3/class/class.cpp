#include "class.h"

void Money::initnominals() {
	this->nominals[1] = 0;
	this->nominals[5] = 0;
	this->nominals[10] = 0;
	this->nominals[50] = 0;
	this->nominals[100] = 0;
	this->nominals[200] = 0;
	this->nominals[500] = 0;
	this->nominals[1000] = 0;
	this->nominals[5000] = 0;
	this->nominals[10000] = 0;
	this->nominals[50000] = 0;
	this->nominals[100000] = 0;
	this->nominals[500000] = 0;
}
void Money::renominals() {
	for (auto it = this->nominals.begin(); it != this->nominals.end(); ++ it)
		it->second = 0;

		int s = this->sum;
	std::map<int, int>::iterator iter = --this->nominals.end();
	while (s != 0) {
		int c = s / iter->first;
		s -= c * iter->first;
		iter->second = c;
		iter --;
	}
}

Money::Money() {
	this->initnominals();
	this->sum = 0;
}
Money::Money(double sum) {
	this->initnominals();
	if (sum < 0)
		this->sum = 0;
	else {
		this->sum = int(sum * 100);
		this->renominals();
	}
}

double Money::getsum() const {
	return this->sum / 100.0;
}

Money Money::operator+(const Money &M) {
	return Money(this->getsum() + M.getsum());
}
Money Money::operator-(const Money &M) {
	return Money(this->getsum() - M.getsum());
}
Money Money::operator/(const double n) {
	return Money(this->getsum() / n);
}
Money Money::operator*(const double n) {
	return Money(this->getsum() * n);
}

bool Money::operator>(const Money &M) {
	return this->getsum() > M.getsum();
}
bool Money::operator>=(const Money &M) {
	return this->getsum() >= M.getsum();
}
bool Money::operator<(const Money &M) {
	return this->getsum() < M.getsum();
}
bool Money::operator<=(const Money &M) {
	return this->getsum() <= M.getsum();
}
bool Money::operator==(const Money &M) {
	return this->getsum() == M.getsum();
}
bool Money::operator!=(const Money &M) {
	return this->getsum() != M.getsum();
}

Money::~Money() {}

std::ostream& operator<<(std::ostream& out, const Money &M) {
	out << "<Money\n" << "\tSum=" << M.getsum() << "\n";
	for (auto iter = M.nominals.begin(); iter != M.nominals.end(); ++ iter) {
		if (iter->second != 0)
			out << "\t" << (iter->first / 100.0) << "p.:" << iter->second << "\n";
	}
	out << ">\n";
	return out;
}