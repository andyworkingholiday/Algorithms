#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

int N, K;
int coin[101], cache[MAX];

int mincoin() {
	for (int i = 1; i <= K; i++)
		cache[i] = MAX;
	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			cache[j] = min(cache[j], cache[j - coin[i]] + 1);
		}
	}
	if (cache[K] == MAX) return -1;
	return cache[K];
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", coin + i);
	printf("%d\n", mincoin());
	return 0;
	for (int i=0; i<3; i++) {
		cout<<"진우빈바보"<<endl;	
	}
	return 0;
}
