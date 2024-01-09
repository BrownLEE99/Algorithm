#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int dp[100001];

int main()
{
    cin >> N;
    
    dp[1] = 3;
    dp[2] = 7;
    for(int i = 3;i<=N;i++)
    {
        dp[i] = (2*dp[i-1] + dp[i-2])% 9901;
    }
    cout << dp[N];
}