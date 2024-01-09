#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;
int dp[201][201];
int SLV(int n,int k)
{
    if(n > N) return 0;
    if(k == K){
        if(n == N)
            return 1;
        else
            return 0;
    }

    // 메모제이션 대상
    // 만약에 i-1번째 숫자에서 a라는 정수를 골랐다면
    // dp[i][k] += dp[i-a][k-1];
    int &res = dp[n][k];
    if(res != -1) return res;
    res = 0;
    for(int i = 0;i<=N;i++)
    {
        if(n + i <= N && k + 1 <= K)
        {
            res = (res + SLV(n + i, k + 1)) % 1000000000;
        }
    }

    return res;
}
void init()
{
    for(int i = 0;i<201;i++)
    {
        for(int j = 0; j < 201; j++)
        {
            dp[i][j] = -1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> N >> K;
    // for(int i = 0;i<=N;i++)
    // {
    //     // 정수 1개 -> 자기자신
    //     dp[i][1] = 1;
    // }
    cout << SLV(0,0);
}