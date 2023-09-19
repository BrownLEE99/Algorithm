#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector <pair<int,int>> v(N);
    for(int i = 0;i<N;i++) {
        cin >> v[i].first >> v[i].second;
        dp[i] = 1;
    }
    sort(v.begin(),v.end());
    int max_up = 0;
    for(int i = 0;i<N;i++){
        for(int j = i;j<N;j++){
            if(v[i].second < v[j].second) {
                dp[j] = max(dp[j],dp[i]+1);
            }
        }
        max_up = max(max_up,dp[i]);
    }
    cout << N - max_up;
}