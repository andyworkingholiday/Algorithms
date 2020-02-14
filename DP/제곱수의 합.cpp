#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 987654321;
using namespace std;

int n;
int arr[MAX];

int squares() {
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		for (int j = 1; j*j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
			for (int k = 1; k <= n; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
		}
	}
	return arr[n];
}

int main() {
	scanf("%d", &n);
	printf("%d\n", squares());
	return 0;
}