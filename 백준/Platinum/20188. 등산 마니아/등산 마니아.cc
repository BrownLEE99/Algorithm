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
vector<int> v[300001];
int dist[300001];
bool check[300001];
int p[300001];

int n;
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
    queue <pair<int,int>> q;
    q.push({1,0});
    check[1] = true;
    p[1] =1;
    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        dist[node] = d;
        for(int i = 0;i<v[node].size();i++){
            int next = v[node][i];
            if(check[next] == false){
                p[next] = node;
                check[next] = true;
                q.push({next,d+1});
            }
        }
    }
    int answer = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            int a = i,b =j;
            if(dist[a] > dist[b]){ // 높이 맞추기
                while(dist[a] != dist[b]){
                    a = p[a];
                }
            } else if(dist[a] < dist[b]) {
                while(dist[a] != dist[b]){
                    b = p[b];
                }
            }
            
            while(p[a] != p[b]){
                a = p[a];
                b = p[b];
            }
            int parent = p[a];
            if(a == b){ // 같은 리프에서 올라옴
                answer += abs(dist[i]-dist[j]);
                answer += dist[a];
            } else{
                answer += dist[parent];
                answer += (dist[i] - dist[parent]) + (dist[j]-dist[parent]);
            }
        }
    }
    cout << answer;
}
