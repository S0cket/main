#include <iostream>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#define forn(i, n) for (int i = 0; i < (n); ++ i)
#define forit(iter, elem) for (auto iter = (elem).begin(); iter != (elem).end(); ++ iter)
#define endl "\n"

using namespace std;

void print(multiset<double> st, string str = "\nmultiset:\n", char sep = ' ') {
	cout << str;
	forit(it, st) cout << *it << sep;
	if (sep != '\n')
		cout << "\n";
}

int main(void) {
	time_t t = time(NULL);
	srand(t);
	cout << "t = " << t << endl;

	int n;
	cin >> n;
	multiset<double> st;
	forn(i, n) st.insert(rand() % 100);
	print(st);

//1
	cout << "\n1:\n";
	double s = 0;
	forit(it, st) s += *it;
	s /= st.size();
	st.insert(s);
	cout << "Srednee = " << s << endl;
	print(st);

//2
	cout << "\n2:\n";
	int a, b;
	cout << "Input range> ";
	cin >> a >> b;
	if (a > b) swap(a, b);
	auto it1 = st.lower_bound(a);
	auto it2 = st.upper_bound(b);
	st.erase(it1, it2);
	print(st);

//3
	cout << "\n3:\n";
	s = *(st.begin()) + *(-- st.end());
	
	{
		multiset<double> st_;
		forit(it, st) st_.insert(*it + s);
		st = st_;
	}

	print(st);

	return 0;
}