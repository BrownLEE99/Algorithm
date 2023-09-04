#include <iostream>
using namespace std;
int n,m;
int c[101];
int w[101];
int dp[101][10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int max_sum = 0;

    for(int i = 1;i<=n;i++){
        cin >> c[i];
    }
    for(int i = 1;i<=n;i++){
        cin >> w[i];
        max_sum += w[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=max_sum;j++){
            if(j-w[i] >= 0){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + c[i]);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 10000000;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=max_sum;j++){
            if(dp[i][j] >= m) {
                ans = min(ans,j);
            }
        }
    }
    cout << ans;
}