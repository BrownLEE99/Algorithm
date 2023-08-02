#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N;
long long  L[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	int s = 0, e = N - 1;
	long long sum = L[0] + L[N - 1];
	pair<int, int> ans = { L[0],L[N - 1] };
	long long mingap = abs(sum);
	while (e > s + 1) {
		if (sum == 0) {
			break;
		}

		int sabs = abs(L[e] + L[s + 1]);
		int eabs = abs(L[e - 1] + L[s]);
		if (sabs <= eabs) {
			if (mingap > sabs) {
				ans = { L[s+1],L[e] };
				mingap = sabs;
			}
			s++;
		}
		else {
			if (mingap > eabs) {
				ans = {L[s], L[e - 1] };
				mingap = eabs;
			}
			e--;
		}

	}
	cout << ans.first << " " << ans.second;
}