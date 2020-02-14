#include <iostream>
using namespace std;

int N, answer;

bool hansu(int n) {
	bool flag = false;
	if (n < 100) flag = true;
	else {
		int a = n / 100;
		int b = (n % 100) / 10;
		int c = (n % 100) % 10;
		if (a - b == b - c) flag = true;
	}
	return flag;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		if (hansu(i)) answer++;
	printf("%d\n", answer);
	return 0;
}