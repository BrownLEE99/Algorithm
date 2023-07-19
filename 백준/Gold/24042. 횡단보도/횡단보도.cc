#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;
typedef long long ll;
int N,M;
vector <pair<ll,ll>> v[100001];
ll DP[100001];
struct cmp {
    bool operator()(vector<ll> a,vector<ll> b){
        return a[0] > b[0];
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for(ll i = 1;i<=M;i++){
        ll a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    for(ll i = 1;i<=N;i++){
        DP[i] = LLONG_MAX;
    }
    
    DP[1] = 0;
    priority_queue <pair<ll,ll>> q;
    q.push({0,1});
    
    while(!q.empty()){
        ll node = q.top().second;
        ll time = -q.top().first;
        q.pop();
        for(ll i = 0;i<v[node].size();i++){
            ll nextNode = v[node][i].first;
            ll period = v[node][i].second;
            if(time > period){
                ll tmp = (time - period) / M;
                if((time - period) % M != 0){
                    tmp++;
                }
                period += M*tmp;
            }
            if(DP[nextNode] > period) {
                DP[nextNode] = period;
                q.push({-period,nextNode});
            }
        }
    }
    cout << DP[N];
}
