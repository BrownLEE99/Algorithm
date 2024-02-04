#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
int N,K;
int main()
{
    int test_case;
    int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> K;
        int fair_cnt = (N/K);
        int last = (N%K);
        ll answer = (ll)(pow(fair_cnt,K-last) * pow(fair_cnt+1, last));
        cout << "#" << test_case << " " << answer << "\n";
    }
}