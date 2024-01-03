#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
#include <stack>
using namespace std;
long long n;
vector<int> v[300001];
long long dist[300001];
long long answer = 0;
long long pick(long long a){
    return a * (a-1)/2;
}

long long DFS(int node){
    dist[node] = 1;
    
    for(auto next : v[node]){
        if(!dist[next]){
            dist[node] += DFS(next);
        }
    }
    answer += pick(n) - pick(n-dist[node]);
    return dist[node];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    cout << answer - pick(n);
}
