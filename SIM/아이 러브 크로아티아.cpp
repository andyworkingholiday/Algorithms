#include <iostream>
#define pung 210
using namespace std;

struct question {
	int time;
	char tf;
};

int k, n;
question q[100];

int main() {
	int sum = 0;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &q[i].time, &q[i].tf);
	}

	for (int i = 0; i < n; i++) {
		sum += q[i].time;
		if (sum >= pung) break;
		if (q[i].tf == 'T') {
			if (k == 8) k = 1;
			else k++;
		}
	}
	printf("%d\n", k);
	return 0;
}