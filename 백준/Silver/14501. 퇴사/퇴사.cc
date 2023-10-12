#include <iostream>
#include <algorithm>
using namespace std;

int N;
int L[16];
int C[32];
int D[32];
int max_profit = 0;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> C[i];
	}
	for (int i = 1; i <= N+1; i++) {
		for (int j = 1; j < i; j++) {
			if (L[j] + j <= i) {
				D[i] = max(D[i], D[j] + C[j]);
			}
		}
		max_profit = max(max_profit, D[i]);
	}
	cout << max_profit;
}