#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

#define INIT -100000001
int input[1001][1001];
int Value[1001][1001][3];
int N,M;
bool check[1001][1001];
int dx[3] = {0,1,0};
int dy[4] = {-1,0,1};
int GO(int x,int y,int path){
    if(x == N && y == M){
        return input[x][y];
    }
    int &res = Value[x][y][path];
    if(res != INIT) return res;
    for(int i = 0;i<3;i++){
        if(path == 0 && i == 2) continue;
        if(path == 2 && i == 0) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
        
        res = max(res,GO(nx,ny,i) + input[x][y]);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            cin >> input[i][j];
            Value[i][j][0] = INIT;
            Value[i][j][1] = INIT;
            Value[i][j][2] = INIT;
        }
    }
    cout << GO(1,1,1);
}
