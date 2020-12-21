#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

bool correct(pair<int, int> point, int n, int m) {
	return (point.first >= 0 && point.first < n && point.second >= 0 && point.second < m);
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void print(int** arr, int n, int m) {
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j)
			printf("%4d ", arr[i][j]);
		cout << "\n";
	}
	cout << "\n";
}

int main(void) {
	int n, m;
	cin >> n >> m;
	int **arr = new int*[n];
	for (int i = 0; i < n; ++ i)
		arr[i] = new int[m];

	cout << "0 - close, 1 - open\n";
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			int x;
			cin >> x;
			if (x != 0 && x != 1) {
				cout << "Incorrect input!!!\n";
				return 1;
			}
			arr[i][j] = x - 1;
		}
	}
	pair<int, int> begin, end;
	cout << "Begin:\n";
	cin >> begin.first >> begin.second;
	cout << "End:\n";
	cin >> end.first >> end.second;

	if (!correct(begin, n, m)) {
		cout << "Incorrect coordinats!!!\n";
		for (int i = 0; i < n; ++ i)
			delete [] arr[i];
		delete [] arr;
		return 2;
	}
	if (!correct(end, n, m)) {
		cout << "Incorrect coordinats!!!\n";
		for (int i = 0; i < n; ++ i)
			delete [] arr[i];
		delete [] arr;
		return 2;
	}
	if (arr[begin.first][begin.second] == -1 || arr[end.first][end.second] == -1) {
		cout << "Begin or End is unavailable\n";
		for (int i = 0; i < n; ++ i)
			delete [] arr[i];
		delete [] arr;
		return 3;
	}

	queue<pair<int, int>> que;
	que.push(begin);
	arr[begin.first][begin.second] = 1;
	bool flag = true;
	while (!que.empty() && flag) {
		pair<int, int> cur = que.front();
		que.pop();
		int value = arr[cur.first][cur.second];
		for (int i = 0; i < n; ++ i) {
			pair<int, int> tmp(cur.first + dx[i], cur.second + dy[i]);
			if (correct(tmp, n, m) && arr[tmp.first][tmp.second] == 0) {
				que.push(tmp);
				arr[tmp.first][tmp.second] = value + 1;
				if (tmp == end) {
					flag = false;
					break;
				}
			}
		}
		//print(arr, n, m);
	}

	if (arr[end.first][end.second] != 0) {
		pair<int, int> *way = new pair<int, int>[arr[end.first][end.second]];
		way[0] = end;
		int value = arr[end.first][end.second] - 1;
		for (int i = 1; i < arr[end.first][end.second]; ++ i) {
			for (int j = 0; j < 4; ++ j) {
				pair<int, int> tmp(way[i - 1].first + dx[j], way[i - 1].second + dy[j]);
				if (correct(tmp, n, m) && arr[tmp.first][tmp.second] == value) {
					value --;
					way[i] = tmp;
					break;
				}
			}
		}
		reverse(way, way + arr[end.first][end.second]);
		cout << "Answer:\n";
		for (int i = 0; i < arr[end.first][end.second]; ++ i) {
			cout << way[i].first << " " << way[i].second << "\n";
		}
		delete [] way;
	}
	else {
		cout << "Umpossible\n";
	}


	for (int i = 0; i < n; ++ i)
		delete [] arr[i];
	delete [] arr;
	return 0;
}