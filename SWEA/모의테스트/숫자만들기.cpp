#include <iostream>
#include <algorithm>
using namespace std;

int maxs = -987654321;
int mins = 987654321;
int N, value;
int numbers[12];
int op[4];

void calculate(int pos) {
	if (pos == N) {
		maxs = max(value, maxs);
		mins = min(value, mins);
		return;
	}

	if (op[0]) {
		op[0]--;
		value += numbers[pos];
		calculate(pos + 1);
		op[0]++;
		value -= numbers[pos];
	}

	if (op[1]) {
		op[1]--;
		value -= numbers[pos];
		calculate(pos + 1);
		op[1]++;
		value += numbers[pos];
	}

	if (op[2]) {
		op[2]--;
		value *= numbers[pos];
		calculate(pos + 1);
		op[2]++;
		value /= numbers[pos];
	}

	if (op[3]) {
		op[3]--;
		int k = value % numbers[pos];
		value /= numbers[pos];
		calculate(pos + 1);
		op[3]++;
		value = value * numbers[pos] + k;		
	}
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		scanf("%d", &N);
		mins = 987654321, maxs = -987654321;
		for (int i = 0; i < 4; i++) {
			scanf("%d", op + i);
		}

		for (int i = 0; i < N; i++) {
			scanf("%d", numbers + i);
		}

		value = numbers[0];
		calculate(1);
		printf("#%d %d\n", t, maxs - mins);
	}
	return 0;
}