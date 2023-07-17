#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int L[1001][1001];
int R[1001][1001];
pair <int,int> s;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool check[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i  =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> L[i][j];
            if(L[i][j] == 2){
                s = {i,j};
            }
            R[i][j] = -1;
            if(L[i][j] == 0) R[i][j] = 0;
        }
    }
    check[s.first][s.second] = true;
    queue <vector<int>> q;
    q.push({s.first,s.second,0});
    while(!q.empty()){
        vector <int> p = q.front();
        R[p[0]][p[1]] = p[2];
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = p[0] + dx[i];
            int ny = p[1] + dy[i];
            if(nx < 0 || nx >= n || ny< 0||ny>=m) continue;
            if(!check[nx][ny] && L[nx][ny] == 1){
                check[nx][ny] = true;
                q.push({nx,ny,p[2]+1});
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << R[i][j] << " ";
        }
        cout << "\n";
    }
}