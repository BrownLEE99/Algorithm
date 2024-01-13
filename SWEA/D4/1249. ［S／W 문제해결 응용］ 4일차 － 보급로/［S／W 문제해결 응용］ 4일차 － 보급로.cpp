#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 987654321
int N;
int L[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dp[101][101];
void input_and_init()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            char c;
            cin >> c;
            L[i][j] = c - '0';
            dp[i][j] = MAX;
        }
    }
}
struct cmp 
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[2] > b[2];
    }
};
int SLV()
{
    priority_queue <vector<int>, vector<vector<int>>, cmp> pq;
    vector <int> s = {1,1,0};
    pq.push(s);
    dp[1][1] = 0;
    while(!pq.empty())
    {
        vector <int> v = pq.top();
        pq.pop();
		if(v[0] == N && v[1] == N) break;
        for(int i = 0; i < 4; ++i)
        {
            int nx = v[0] + dx[i];
            int ny = v[1] + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(dp[nx][ny] > dp[v[0]][v[1]] + L[nx][ny])
            {
                dp[nx][ny] = dp[v[0]][v[1]] + L[nx][ny];
                pq.push({nx,ny,dp[nx][ny]});
            }
        }
    }

    return dp[N][N];
}
void opt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    opt();
    int test_case;
    cin >> test_case;

    for(int t = 1; t <= test_case; ++t)
    {
        input_and_init();
        cout << "#" << t << " " << SLV() << "\n";
    }
}

