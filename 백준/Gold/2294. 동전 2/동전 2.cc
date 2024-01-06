#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX (10001)
int N,K;
bool isExist[100001];
vector <int> coin;

int dp[10001];
int minCount = MAX;
void SLV(int value,int cnt)
{
    if(cnt >= minCount) return;
    if(value == K)
    {
        minCount = min(minCount,cnt);
        return ;
    }

    int &ret = dp[value];
    if(ret > cnt) ret = cnt;
    else return ;

    for(int i = 0; i < coin.size(); i++)
        if(coin[i] + value <= K)
            SLV(value + coin[i], cnt + 1);

    return ;
}

void input()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        if(!isExist[value])
        {
            isExist[value] = true;
            coin.push_back(value);
        }
    }
}
void init()
{
    for(int i = 0; i <= 10000; i++) dp[i] = MAX;
}
void output()
{
    for(int i = 0; i <= K; i++)
        cout << "dp[" << i << "] = " << dp[i] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    input();
    SLV(0,0);
    if(minCount == MAX) cout << -1;
    else cout << minCount;
}