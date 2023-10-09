#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N;
int L[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int max_score = 0;
void SLV(int try_count, int B[][21]) {
	/*for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cout << B[x][y] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";*/
	if (try_count == 5) return;
	vector <int> v;

	for (int i = 0; i < 4; i++) {
		int T[21][21];
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				T[x][y] = B[x][y];
			}
		}
		if (i == 0) {
			int pos = 0;
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = 0; j < N; j++) {
					if (T[i][j] != 0)q.push(T[i][j]);
				}
				int tmp = 0;
				int idx = 0;
				while (!q.empty()) {
					if (tmp == 0) {
						tmp = q.front();
						q.pop();
					}
					else {

						if (tmp == q.front()) {
							T[i][idx++] = tmp * 2;
							max_score = max(max_score, tmp * 2);
							tmp = 0;
							q.pop();
						}
						else {
							T[i][idx++] = tmp;
							max_score = max(max_score, tmp);
							tmp = q.front();
							q.pop();
						}

					}
				}
				if (tmp != 0) {
					T[i][idx++] = tmp;
					max_score = max(max_score, tmp);
				}
				while (idx < N) {
					T[i][idx++] = 0;
					pos++;
				}
				
			}
			if(pos != 0)
				SLV(try_count + 1, T);
		}
		else if (i == 1) {
			int pos = 0;
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = N - 1; j >= 0; j--) {
					if (T[j][i] != 0)q.push(T[j][i]);
				}
				int tmp = 0;
				int idx = N - 1;
				while (!q.empty()) {
					if (tmp == 0) {
						tmp = q.front();
						q.pop();
					}
					else {

						if (tmp == q.front()) {
							T[idx--][i] = tmp * 2;
							max_score = max(max_score, tmp * 2);
							tmp = 0;
							q.pop();
						}
						else {
							T[idx--][i] = tmp;
							max_score = max(max_score, tmp);
							tmp = q.front();
							q.pop();
						}

					}
				}
				if (tmp != 0) {
					T[idx--][i] = tmp;
					max_score = max(max_score, tmp);
				}
				while (idx >= 0) {
					T[idx--][i] = 0;
					pos++;
				}
			}
			if (pos != 0)
				SLV(try_count + 1, T);
		}
		else if (i == 2) {
			int pos = 0;
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = N - 1; j >= 0; j--) {
					if (T[i][j] != 0)q.push(T[i][j]);
				}
				int tmp = 0;
				int idx = N - 1;
				while (!q.empty()) {
					if (tmp == 0) {
						tmp = q.front();
						q.pop();
					}
					else {

						if (tmp == q.front()) {
							T[i][idx--] = tmp * 2;
							max_score = max(max_score, tmp * 2);
							tmp = 0;
							q.pop();
						}
						else {
							T[i][idx--] = tmp;
							max_score = max(max_score, tmp);
							tmp = q.front();
							q.pop();
						}

					}
				}
				if (tmp != 0) {
					T[i][idx--] = tmp;
					max_score = max(max_score, tmp);
				}
				while (idx >= 0) {
					T[i][idx--] = 0;
					pos++;
				}
			}
			if(pos != 0)
				SLV(try_count + 1, T);
		}
		else {
		int pos = 0;
			for (int i = 0; i < N; i++) {
				queue <int> q;
				for (int j = 0; j < N; j++) {
					if (T[j][i] != 0)q.push(T[j][i]);
				}
				int tmp = 0;
				int idx = 0;
				while (!q.empty()) {
					if (tmp == 0) {
						tmp = q.front();
						q.pop();
					}
					else {
						if (tmp == q.front()) {
							T[idx++][i] = tmp * 2;
							max_score = max(max_score, tmp * 2);
							tmp = 0;
							q.pop();
						}
						else {
							T[idx++][i] = tmp;
							max_score = max(max_score, tmp);
							tmp = q.front();
							q.pop();
						}
					}
				}
				if (tmp != 0) {
					T[idx++][i] = tmp;
					max_score = max(max_score, tmp);
				}
				while (idx < N) {
					T[idx++][i] = 0;
					pos++;
				}
			}
			if(pos != 0)
				SLV(try_count + 1, T);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> L[i][j];
		}
	}
	SLV(0, L);
	cout << max_score;
}