#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool check[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1, vector<int>(n+1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue <int> q;
	q.push(1);
	check[1] = true;
	int ans = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			int newNode = v[node][i];
			if (!check[newNode] && newNode) {
				check[newNode] = true;
				ans++;
				q.push(newNode);
			}
		}
	}
	cout << ans;
}