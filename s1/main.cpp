#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <list>

using namespace std;

int N = 15;

void print(vector<int> v) {
	for (int i = 0; i < v.size(); ++ i)
		cout << v[i] << " ";
	cout << endl;
}
void print(list<int> l) {
	for (auto iter = l.begin(); iter != l.end(); ++ iter)
		cout << *iter << " ";
	cout << endl;
}

int main(void) {
	srand(time(NULL));

	//1
	vector<int> v(N);
	for (int i = 0; i < N; ++ i)
		v[i] = rand() % 100;
	print(v);
	for (int i = 0; i < 3; ++ i)
		v.push_back(v[i + 10] - 2);
	print(v);

	//2
	list<int> lst;
	for (int i = 0; i < N; ++ i)
		lst.push_back(rand() % 100);
	print(lst);
	auto iter = min_element(lst.begin(), lst.end());
	if (iter == lst.begin() || iter == --lst.end())
		lst.erase(iter);
	else {
		lst.erase(--iter);
		auto iter = min_element(lst.begin(), lst.end());
		lst.erase(++iter);
	}
	print(lst);

	return 0;
}