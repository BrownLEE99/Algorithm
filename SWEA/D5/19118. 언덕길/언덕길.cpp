#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[1001];
int h[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    for(int t = 1; t <= test_case; ++t)
    {
        cin >> N;
        int height;
        for(int i = 1; i <= N; ++i)
        {  
            cin >> h[i];
            dp[i] = 1;
        }
        int max_length = 0;
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                if(h[j] < h[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length,dp[i]);
        }
        cout << "#" << t << " " << N - max_length << "\n";
    }
}