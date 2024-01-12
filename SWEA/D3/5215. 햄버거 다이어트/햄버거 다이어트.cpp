#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int score[1001];
int carlorie[1001];
int dp[21][10001];
int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        int N,L;
        cin >> N >> L;
        for(int i = 1; i <= N; ++i)
        {
            cin >> score[i] >> carlorie[i];
        }
        int max_score = 0;
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 0; j <= L; ++j)
            {
                if(j - carlorie[i] >= 0)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - carlorie[i]] + score[i]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
                max_score = max(max_score,dp[i][j]);
            }
        }
        cout << "#" << t << " " << max_score << "\n";
    }
}