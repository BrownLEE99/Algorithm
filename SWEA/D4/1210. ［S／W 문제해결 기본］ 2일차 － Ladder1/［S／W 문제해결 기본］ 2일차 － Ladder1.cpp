#include <iostream>
using namespace std;

int L[101][101];
pair<int,int> p;
int dx[] = {-1,0,0};
int dy[] = {0,-1,1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 10;
    for(int t = 1; t <= T; ++t)
    {
        int test_case;
        cin >> test_case;

        for(int i = 0; i < 100; ++i)
        {
            for(int j = 0; j < 100; ++j)
            {
                cin >> L[i][j];
                if(L[i][j] == 2)
                {
                    p = {i,j};
                }
            }
        }
        int dir = 0;
        while(true)
        {
            if(p.first == 0) break;
            // cout << p.first << " " << p.second << "\n";
            // 일단 이동
            p.first += dx[dir];
            p.second += dy[dir];

            // 이동 방향의 수직인 방향에 길이 있을 경우
            if(dir == 0)
            {
                pair<int,int> left = {p.first + dx[1], p.second + dy[1]};
                pair<int,int> right = {p.first + dx[2], p.second + dy[2]};
                if(left.second >= 0 && L[left.first][left.second] == 1)
                {
                    dir = 1;
                }
                if(right.second < 100 && L[right.first][right.second] == 1)
                {
                    dir = 2;
                }
            }
            else
            {
                pair<int,int> up = {p.first + dx[0], p.second + dy[0]};
                if(L[up.first][up.second] == 1)
                {
                    dir = 0;
                }
            }
        }
        cout << "#" << test_case << " " << p.second << "\n";
    }
}