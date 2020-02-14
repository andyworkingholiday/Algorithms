#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

char map[29];

int T, N, K;
vector<int> v;

bool isbig(int a, int b) {
	return a > b;
}

void rotate() {
	for (int i = N-1; i >=0; i--) {
		map[i + 1] = map[i];
	}
	map[0] = map[N];
}

void calculate() {
	bool flag;
	for (int i = 0; i < 4; i++) {
		int result = 0;
		flag = true;
		for (int j = 0; j < N / 4; j++) {
			int number;
			if (map[N/4 * i + j] >= 'A') {
				number = map[N/4 * i + j] - 'A' + 10;
			}
			else number = map[N/4 * i + j] - '0';
			result += pow(16, (N / 4) - j - 1)*number;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == result) {
				flag = false;
				break;
			}
		}
		if (flag) v.push_back(result);
	}
}



int main() {
	scanf("%d", &T);
	for (int iter = 1; iter <= T; iter++) {
		v.clear();
		v.push_back(-1);
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}

		for (int i = 0; i < N / 4; i++) {
			calculate();
			rotate();
		}


		sort(v.begin(), v.end(), isbig);
		printf("#%d %d\n", iter, v[K - 1]);
	}
	return 0;
}