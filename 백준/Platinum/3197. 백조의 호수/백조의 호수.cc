#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int R,C;
char L[1501][1501];
vector <pair<int,int>> swan;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool check[1501][1501];

int main(){
    queue <pair<int,int>> water;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for(int i = 0;i<R;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            L[i][j] = str[j];
            if(L[i][j] == 'L'){
                swan.push_back({i,j});
                L[i][j] = '.';
                water.push({i,j});
            }else if(L[i][j] == '.'){
                water.push({i,j});
            }
        }
    }
    int day = 0;
    queue <pair<int,int>> q;
    check[swan[0].first][swan[0].second] = true;
    q.push(swan[0]);
    while(true){
    queue <pair<int,int>> nex;
    while(!q.empty()){
        pair <int,int> p = q.front();
        q.pop();
        if(p.first == swan[1].first && p.second == swan[1].second){
            cout << day;
            return 0;
        }   
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            
            if(L[nx][ny] == '.' && !check[nx][ny]){
                q.push({nx,ny});
                check[nx][ny] = true;
            }
            if(L[nx][ny] == 'X' && !check[nx][ny]){
                nex.push({nx,ny});
                check[nx][ny] = true;
            }
        }
    }
    q = nex;
        
    int sz = water.size();
    while(sz--){
        pair<int,int> p = water.front();
        water.pop();
        for(int i = 0;i<4;i++){
            int nx = p.first +dx[i];
            int ny = p.second + dy[i];
            if(nx <0 || nx >= R || ny < 0 || ny >= C) continue;
            if(L[nx][ny] == 'X'){
                water.push({nx,ny});
                L[nx][ny] = '.';
            }
        }
    }
    day++;
    }
}