#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
char L[11][11];
bool check[11][11][11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct BALL {
	int x;
	int y;
	int prevD = -1;
	int cnt = 0;
};
queue <pair<pair<BALL, BALL>, int>> q; // 공이 있을수 있는 위치를 담아놓은 큐
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	BALL r;
	BALL b;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			L[i][j] = str[j];
			if (L[i][j] == 'R') {
				r.x = i;
				r.y = j;
			}
			if (L[i][j] == 'B') {
				b.x = i;
				b.y = j;
			}
		}
	}
	int cnt = 0;
	q.push({ { r,b },0 });
	check[r.x][r.y][b.x][b.y] = true;
	while (!q.empty()) {
		BALL red = q.front().first.first;
		BALL blue = q.front().first.second;
		int trycount = q.front().second;
		q.pop();
		if (trycount >= 10) break;
		for (int i = 0; i < 4; i++) {
			bool rflag = false;
			bool bflag = false;
			int rnx = red.x;
			int rny = red.y;
			int bnx = blue.x;
			int bny = blue.y;
			while (L[rnx+dx[i]][rny+dy[i]] != '#'&& !(rnx + dx[i] == bnx && rny + dy[i] == bny)) {
				if (L[rnx+dx[i]][rny+dy[i]] == 'O') {
					rflag = true;
				}
				rnx += dx[i];
				rny += dy[i];
				while (L[bnx + dx[i]][bny + dy[i]] != '#' &&(rflag || !(rnx == bnx + dx[i] && rny == bny + dy[i]))) {
					bnx += dx[i];
					bny += dy[i];
					if (L[bnx][bny] == 'O'){bflag = true;
                                           break;}
				}
			}
            if(bflag)continue;
			while (L[bnx+dx[i]][bny+dy[i]] != '#' &&(rflag || !(rnx == bnx + dx[i] && rny == bny + dy[i]))) {
				if (L[bnx+dx[i]][bny+dy[i]] == 'O'){bflag = true;
                                                   break;}
				bnx += dx[i];
				bny += dy[i];
				while (L[rnx+dx[i]][rny+dy[i]] != '#'&& !(rnx+dx[i] == bnx && rny + dy[i] == bny)) {
					rnx += dx[i];
					rny += dy[i];
					if (L[rnx][rny] == 'O') {
						rflag = true;
						rnx = -1; rny = -1;
					}
				}
			}
			if (!bflag && rflag) {
				cout << trycount+1;
				exit(0);
			}
			if (bflag) continue;
			
			if (!check[rnx][rny][bnx][bny]) {
				check[rnx][rny][bnx][bny] = true;
				BALL rr, bb;
				rr.x = rnx; rr.y = rny;
				bb.x = bnx; bb.y = bny;
				q.push({ {rr,bb},trycount + 1 });
			}
		}
	}
	cout << -1;
}