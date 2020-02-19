#include <iostream>
#include <algorithm>
using namespace std;

struct difficulty {
	int easy, hard;
};


bool cmp(difficulty a, difficulty b) {
	return a.hard < b.hard;
}

int N, L, K, sum;
difficulty problem[100];

int main() {
	scanf("%d %d %d", &N, &L, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &problem[i].easy, &problem[i].hard);
	}

	sort(problem, problem + N, cmp);

	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (ret == K) break;
		if (L >= problem[i].hard) {
			sum += 140;
			ret++;
		}
		else break;
	}
	

	for (int i = ret; i < N; i++) {
		if (ret == K) break;
		if (L >= problem[i].easy) {
			sum += 100;
			ret++;
		}		
	}
	printf("%d\n", sum);
	return 0;
}