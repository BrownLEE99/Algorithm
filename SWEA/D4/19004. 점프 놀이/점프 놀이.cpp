#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX 987654321
using namespace std;
int L[52][52];
int dp[52][52];
int N,K;
void init()
{
    for(int i = 0; i < 52; ++i)
    {
        for(int j = 0; j < 52; ++j)
        {
            L[i][j] = 0;
            dp[i][j] = MAX;
        }
    }
}

int SLV(int x, int y)
{
    // 만약에 도착지에 도착했다면 return 0;
    if(L[x][y] == K)
    {
        //dp[x][y] = 0;
        return 0;
    }

    // 해당 위치에서 가장 가까운 거리까지 갱신이 되었다면
    // 굳이 더 찾아볼 필요가 없이 전에 계산된 값을 이용한다.
    int &ret = dp[x][y];
    if(ret != MAX) return ret;

    // 좌표에서 점프할 수 있는 곳(자신의 값+1)을 찾는다.
    for(int i = 1;i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            // 그중 최소인 값을 저장한다.
            if(L[i][j] == L[x][y] + 1)
            {
                ret = min(ret, SLV(i,j) + abs(i-x) + abs(j-y));
            }
        }
    }

    return ret;
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
        init();
        cin >> N >> K;
        for(int i = 1;i <= N;++i)
        {
            for(int j = 1; j <= N; ++j)
            {
                cin >> L[i][j];
            }
        }
        int min_dist = MAX;
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= N; ++j)
            {
                if(L[i][j] == 1)
                {
                    min_dist = min(min_dist, SLV(i,j));
                }
            }
        }
        if(min_dist == MAX) min_dist = -1;
        cout << "#" << t << " " << min_dist << "\n";
    }
}