#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

int N,M;
int L[51][51];
pair <int,int> loc;
int direc = 0;
bool check[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
vector<int> isThereMore(pair <int,int> p ){
    vector <int> ret;
    for(int i = 0;i<4;i++){
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];
        
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(L[nx][ny] == 0 && !check[nx][ny]) { // Not cleaned yet
            ret.push_back(i);
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    cin >> loc.first >> loc.second >> direc;
    if(direc == 1) direc = 3;
    else if(direc == 3) direc= 1;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> L[i][j];
        }
    }
    int clean = 0;
    while(true){
        // 1.
        if(L[loc.first][loc.second] == 0 && !check[loc.first][loc.second]){
            check[loc.first][loc.second] = true;
            //cout << loc.first << " " << loc.second << "\n";
            clean++;
        }
        // 2.
        vector<int> nextD = isThereMore(loc);
        if(nextD.size() == 0){ // all cleaned
            int nd;
            nd = (direc+2)%4;
            int nx = loc.first + dx[nd];
            int ny = loc.second + dy[nd];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
            if(L[nx][ny] == 1) break;
            loc.first = nx;
            loc.second = ny;
            
        }else{
            direc = (direc+1)%4;
            int nx = loc.first + dx[direc];
            int ny = loc.second + dy[direc];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(L[nx][ny] == 0 && !check[nx][ny]){
                loc.first = nx;
                loc.second = ny;
            }
        }
        
    }
    cout << clean;
}
