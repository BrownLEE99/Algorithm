#include <iostream>
#include <algorithm>
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
        int N,M;
        int L[16][16];
        cin >> N >> M;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                cin >> L[i][j];
            }
        }
        int max_value = 0;
        for(int i = 0; i <= N-M; ++i)
        {
            for(int j = 0; j<= N-M; ++j)
            {
                int sum = 0;
            
                for(int x = 0; x < M; x++)
                {
                    for(int y = 0; y < M; y++)
                    {
                        sum += L[i + x][j + y];
                    }
                }
                max_value = max(max_value, sum);
            }
        }
        cout << "#" << test_case << " " << max_value << "\n";
    }
}