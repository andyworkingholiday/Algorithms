#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[10];
int check[10];
int password[10];

void can_go(int idx) {
	int front = password[idx];
	int next = password[idx + 1];
	check[front]++;

	if (front == 5) {
		for (int i = 1; i <= 9; i++) {
			if (i != 5) {
				v[i].push_back(10 - i);
			}
		}
	}

	if (front == 2) {
		v[3].push_back(1);
		v[1].push_back(3);
	}

	if (front == 8) {
		v[9].push_back(7);
		v[7].push_back(9);
	}

	if (front == 4) {
		v[1].push_back(7);
		v[7].push_back(1);
	}

	if (front == 6) {
		v[3].push_back(9);
		v[9].push_back(3);
	}

	if (check[front] == 2) {
		printf("NO\n");
		exit(0);
	}

	if (idx == n) {
		printf("YES\n");
		exit(0);
	}

	bool flag = false;
	for (int i = 0; i < v[front].size(); i++) {
		if (v[front][i] == next) {
			flag = true;
			break;
		}
	}

	if(flag) can_go(idx + 1);
	else {
		printf("NO\n");
		exit(0);
	}
}

int main() {

	for (int i = 1; i <= 9; i++) {
		if (i == 1 || i == 3 || i == 7 || i == 9) {
			v[i].push_back(2);
			v[i].push_back(4);
			v[i].push_back(6);
			v[i].push_back(8);
			v[i].push_back(5);
		}

		else if (i == 2 || i == 4 || i == 6 || i == 8) {
			for (int j = 1; j <= 9; j++) {
				if (i + j != 10 && i!=j) {
					v[i].push_back(j);
				}
			}
		}

		else {
			for (int j = 1; j <= 9; j++) {
				if (j != 5) v[i].push_back(j);
			}
		}
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &password[i]);
	}

	can_go(1);
	return 0;
}
