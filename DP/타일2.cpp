#include <iostream>
#define MAX 1001
using namespace std;

int n;
int tile[MAX];

int main() {
	scanf("%d", &n);
	tile[1] = 1, tile[2] = 3;
	for (int i = 3; i <= n; i++) 
		tile[i] = (tile[i - 1] + 2 * tile[i - 2]) % 10007;
	printf("%d\n", tile[n]);
}