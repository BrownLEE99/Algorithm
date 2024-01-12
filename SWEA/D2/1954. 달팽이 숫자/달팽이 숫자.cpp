#include <iostream>
#include <vector>
using namespace std;
int L[11][11];
bool visited[11][11];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void SLV(int x, int y, int cnt, int dir, int len)
{
    if(cnt == len * len + 1)
        return ;
    

    L[x][y] = cnt;
    visited[x][y] = true;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    int change = 0;

    if(nx < 0 || ny < 0 || nx >= len || ny >= len) change = true;
    if(visited[nx][ny]) change = true;

    if(change)
    {
        int newdir = (dir + 1) % 4;
        int nx = x + dx[newdir];
        int ny = y + dy[newdir];
        SLV(nx, ny, cnt+1, newdir, len);
    }
    else
    {
        SLV(nx, ny, cnt+1, dir, len);
    }
    
}

void init()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            L[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        init();
        int len;
        cin >> len;
        SLV(0,0,1,0,len);
        cout << "#" << i+1 << "\n";
        for(int x = 0; x < len; x++)
        {
            for(int y = 0; y < len; y++)
            {
                cout << L[x][y] << " ";
            }
            cout << "\n";
        }
    }
}