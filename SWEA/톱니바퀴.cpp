#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int cycle[4][8];
bool check[5];
int direction[4];
int K;

void isrotate(int n) {
	check[n] = true;
	if (n == 2 || n == 3) {
		int back = cycle[n - 1][2];
		int front = cycle[n - 1][6];

		if (back!=cycle[n][6] && !check[n+1]) {
			isrotate(n + 1);
		}

		if (front != cycle[n-2][2] && !check[n-1]) {
			isrotate(n - 1);
		}
	}

	else if (n == 4) {
		int front = cycle[n - 1][6];
		if (front != cycle[n - 2][2] && !check[n - 1]) {
			isrotate(n - 1);
		}
			
	}

	else {
		int back = cycle[n - 1][2];
		if (back != cycle[n][6] && !check[n + 1]) {
			isrotate(n + 1);
		}
	}
}


void rotate(int row, int n) {
	int temp;
	if (n == 0) {
		for (int i = 7; i >= 0; i--) {
			if (i == 7) temp = cycle[row - 1][i];
			else cycle[row-1][i + 1] = cycle[row-1][i];
		}
		cycle[row - 1][0] = temp;
	}
	else {
		for (int i = 0; i <= 7; i++) {
			if (i == 0) temp = cycle[row-1][i];
			else cycle[row-1][i - 1] = cycle[row-1][i];
		}
		cycle[row - 1][7] = temp;
	}
}

int main() {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &cycle[i][j]);
		}
	}
	scanf("%d", &K);
	while (K--) {
		memset(check, false, sizeof(check));
		int number, dir, divid;
		scanf("%d %d", &number, &dir);

		if (dir == 1) divid = 0;
		else divid = 1;

		isrotate(number);
		
		for (int i = -1; i < 3; i++) {
			direction[((number + i) % 4)] = divid;
			divid = (divid + 1) % 2;
		}
		for (int i = 1; i <= 4; i++) {
			if (check[i]) {
				rotate(i, direction[i - 1]);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		ans += cycle[i][0] * pow(2, i);
	}
	printf("%d\n", ans);
	return 0;
}