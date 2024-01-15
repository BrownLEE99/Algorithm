#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int L[16][16];
bool visited[16][16];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
pair <int,int> s;
pair <int,int> e;
bool BFS()
{
    for(int i = 0; i < 16; ++i)
    {
        for(int j = 0; j < 16; ++j)
        {
            visited[i][j] = false;
        }
    }
    queue <pair<int,int>> q;
    q.push(s);
    visited[s.first][s.second] = true;

    bool flag = false;
        
    while(!q.empty())
    {
        pair <int,int> p = q.front();
        q.pop();

        if(p == e) {
            flag = true;
            break;
        }

        for(int i = 0; i < 4; ++i)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= 16 || ny >= 16) continue;

            if(!visited[nx][ny] && L[nx][ny] == 0)
            {
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }

    }

    return flag;
}
int main()
{
    for(int t = 1; t <= 10; ++t)
    {
        int test_case;
        cin >> test_case;

        for(int i = 0; i < 16; ++i)
        {
            for(int j = 0; j < 16; ++j)
            {
                char c;
                cin >> c;
                L[i][j] = c - '0';
                if(L[i][j] == 2) s = {i, j};
                if(L[i][j] == 3) {
                    e = {i,j};
                    L[i][j] = 0;
                }
            }
        }
        cout << "#" << t << " " << BFS() << "\n";
    }
}