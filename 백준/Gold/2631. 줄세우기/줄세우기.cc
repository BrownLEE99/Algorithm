#include <iostream>
using namespace std;

int dp[202];
int L[202];

int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> L[i];
		dp[i] = 1;
	}
	int max_len = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (L[i] > L[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max_len = max(max_len, dp[i]);
	}
	cout << n - max_len;
}