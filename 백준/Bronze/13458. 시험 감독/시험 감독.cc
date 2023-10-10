#include <iostream>
#include <math.h>
using namespace std;

int n;
double L[1000001];
double b, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}
	cin >> b >> c;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		double pp = L[i];
		pp -= b;
		double aa = ceil(pp / c);
		if (aa > 0) {
			ans += aa;
		}
	}
	cout << (long long)ans + n;
}