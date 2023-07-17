#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int L[200001];
int C[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	int s = 0;
	int e = 0;
	int ans = 0;
	while (e < N) {
		if (C[L[e]] < K) {
			C[L[e]]++;
			e++;
			ans = max(ans, e - s);
		}
		else {
			C[L[s++]]--;
		}
	}
	cout << ans;
}