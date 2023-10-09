#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k,l;
bool apple[102][102];
char direction[10001];
char tail[102][102];
bool body[102][102];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
pair <pair<int, int>,int> shead;
pair<pair<int, int>,int> stail;

int slen = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		apple[x][y] = true;
	}
	cin >> l;
	for (int i = 0; i < 10001; i++) {
		direction[i] = 'C';
	}
	for (int i = 0; i < l; i++) {
		int t;
		char c;
		cin >> t >> c;
		direction[t] = c;
	}
	int t = 0;
	shead.first = { 1,1 };
	shead.second = 3;
	stail.first = { 1,1 };
	stail.second = 3;
	body[1][1] = true;

	while (slen >= 1) {
		t++;
		int nx = shead.first.first + dx[shead.second];
		int ny = shead.first.second + dy[shead.second];
		if (nx < 1 || nx > n || ny < 1 || ny > n)break;
		if (body[nx][ny]) break;  
		body[nx][ny] = true;
		bool longerbody = false;
		if (apple[nx][ny]) { 
			longerbody = true;
			slen++;
			apple[nx][ny] = false;
		}
		if (!longerbody) {
			if (body[stail.first.first][stail.first.second] && tail[stail.first.first][stail.first.second] == 'L') {
				if (stail.second == 0)
					stail.second = 2;
				else if (stail.second == 1)
					stail.second = 3;
				else if (stail.second == 2)
					stail.second = 1;
				else stail.second = 0;

			}
			if (body[stail.first.first][stail.first.second] && tail[stail.first.first][stail.first.second] == 'D') {
				if (stail.second == 0)stail.second = 3;
				else if (stail.second == 1)
					stail.second = 2;
				else if (stail.second == 2)
					stail.second = 0;
				else stail.second = 1;
			}
			body[stail.first.first][stail.first.second] = false;
			tail[stail.first.first][stail.first.second] = 'C';
			stail.first = { stail.first.first + dx[stail.second],stail.first.second + dy[stail.second] };
		}
		int new_d = shead.second;
		if (direction[t] == 'L') {
			if (shead.second == 0)new_d = 2;
			else if (shead.second == 1)new_d = 3;
			else if (shead.second == 2)new_d = 1;
			else new_d = 0;

			tail[nx][ny] = 'L';
		}
		else if (direction[t] == 'D') {
			if (shead.second == 0)new_d = 3;
			else if (shead.second == 1)new_d = 2;
			else if (shead.second == 2)new_d = 0;
			else new_d = 1;
			tail[nx][ny] = 'D';
		}
		shead.second = new_d;
		shead.first = { nx,ny };
	}

	cout << t;
}