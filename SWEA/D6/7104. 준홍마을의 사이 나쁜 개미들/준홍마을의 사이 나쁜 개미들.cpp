#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 987654321
int K,N,M;
vector <int> adj[501];
int visited[501];
int flow[501][501];
int capacity[501][501];
vector<vector<int>> candidate;
void init() {
    for(int i = 0; i < 501; ++i) {
        adj[i].clear();
        for(int j = 0; j < 501; ++j) {
            flow[i][j] = 0;
            capacity[i][j] = 0;
        }
    }
    candidate.clear();
}

int maxflow(int source,int sink) {
    int answer =0 ;
    while(1) {
        for(int i = 0; i < 501; ++i) {
            visited[i] = -1;
        }
        queue <int> q;
        q.push(source);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bool flag = false;
            for(int i = 0; i < adj[node].size(); ++i){
                int next = adj[node][i];
                if(visited[next] == -1 && capacity[node][next] - flow[node][next] > 0) {
                    q.push(next);
                    visited[next] = node;
                    if(next == sink) {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(visited[sink] == -1) break;
        int f = MAX;
        for(int i = sink; i != source; i = visited[i]) {
            f = min(f, capacity[visited[i]][i] - flow[visited[i]][i]);
        }
        if(f == 0) break;
        for(int i = sink; i != source; i = visited[i]) {
            flow[visited[i]][i] += f;
        }
        answer += f;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    for(int t = 1; t <= test_case; ++t){
        init();
        cin >> K >> N >> M;
        int s,e;
        s = e = 0;
        for(int i = 0; i < M; ++i){
            int x,y;
            cin >> x >> y;
            if(capacity[x][y] == 0) adj[x].push_back(y);
            if(x == 1) s++;
            if(y == 2) e++;
            if(x == 1 && y == 2) capacity[x][y]++;
            else capacity[x][y] = 1;
        }
        if(s < K || e < K) {
            cout << "#" << t << " NO\n"; 
        } else {
            int answer = maxflow(1,2);
            if(answer >= K) cout << "#" << t << " YES\n";
            else cout << "#" << t << " NO\n";
        }
    }
}