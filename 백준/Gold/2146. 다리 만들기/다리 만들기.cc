#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
using namespace std;

int N;
int L[101][101];
bool check[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector <pair<int,int>> v[10001];
void BFS(int x,int y,int a){
    L[x][y] = a;
    queue <pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    v[a].push_back({x,y});
    while(!q.empty()) {
        pair <int,int> p = q.front();
        q.pop();
        v[a].push_back(p);
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(L[nx][ny] == 1 && !check[nx][ny]) {
                check[nx][ny] = true;
                L[nx][ny] = a;
                q.push({nx,ny});
                
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> L[i][j];
        }
    }
    int area = 2;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(L[i][j] == 1 && !check[i][j]){
                BFS(i,j,area++);
            }
        }
    }
    int minGap = 987654321;
    for(int i = 2;i<area;i++){
        for(int j = i+1;j<=area;j++){
            for(int x = 0;x < v[i].size();x++){
                for(int y = 0;y<v[j].size();y++){
                    int dist = abs(v[i][x].first - v[j][y].first) + abs(v[i][x].second - v[j][y].second)-1;
                    minGap = min(minGap,dist);
                }
            }
        }
    }
    cout << minGap;
}
