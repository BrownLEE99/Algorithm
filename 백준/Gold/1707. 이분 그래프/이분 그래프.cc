#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define RED 1
#define BLUE 2

vector<int> adj[20001];
int check[20001];
int V,E;

void BFS(int start) {
    check[start] = RED;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < adj[now].size(); i++) {
            int index = adj[now][i];
            if(check[index] == 0) {
                check[index] = (check[now] == RED) ? BLUE : RED;
                q.push(index);
            }
        }
    }
}

int SLV() {
    for(int i = 1; i <= V; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            int index = adj[i][j];
            if(check[i] == check[index]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int T;
    int u,v;

    cin >> T;
    
    while(T--) {
        cin >> V >> E;

        for(int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= V; i++) {
            if(check[i] == 0) {
                BFS(i);
            }
        }
        if(SLV() == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        memset(check,0,sizeof(check));
        memset(adj,0,sizeof(adj));
    }
}