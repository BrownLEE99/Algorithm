#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T;
    cin >> T;
    for(test_case = 1; test_case <= T; test_case++)
    {
        int N;
        cin >> N;
        int L[1001];
        int dp[1001];
        for(int i = 1; i <= N; i++)
        {
            cin >> L[i];
            dp[i] = 1;
        }
        int max_length = 0;

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j<= i; j++)
            {
                if(L[j] < L[i])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            max_length = max(max_length,dp[i]);
        }
        cout << "#" << test_case << " " << N- max_length << "\n";
    }
}