#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int n,m;
int L[1002][1002];
int A[4001];
int x,y,d;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int changeGo = 1;
map <pair<int,int>,int> mm;
void SLV(int cnt){
    if(cnt == 2*(n+m)+1){
        return ;
    }
        queue <vector<int>> q;
        q.push({x,y,d});
        pair <int,int> dest;
        while(!q.empty()){
            vector<int> v = q.front();
            q.pop();
            
            if(L[v[0]][v[1]] == 0){
                int nx = v[0] + dx[v[2]];
                int ny = v[1] + dy[v[2]];
                
                if(nx <= 0 || nx > n || ny <= 0 || ny > m){
                    dest.first = nx;
                    dest.second = ny;
                    break;
                }
                q.push({nx,ny,v[2]});
            }else{
                int nd;
                if(v[2] == 0) nd = 3;
                else if(v[2] == 1) nd = 2;
                else if(v[2] == 2) nd = 1;
                else nd = 0;
                
                int nx = v[0] + dx[nd];
                int ny = v[1] + dy[nd];
                if(nx <= 0 || nx > n || ny <= 0 || ny > m){
                    dest.first = nx;
                    dest.second = ny;
                    break;
                }
                q.push({nx,ny,nd});
            }
        }
       // A[mm[dest]] = mm[{x,y}];
    
    if(changeGo== 1){
        A[mm[{x,y-1}]] = mm[dest];
        int nx = x+1;
        int ny = y;
        if(nx == n+1){
            changeGo = 2;
            d = 0;
            x = n;
            y = 1;
            SLV(cnt+1);
        }else{
            x = nx;
            y = ny;
            SLV(cnt+1);
        }
    }else if(changeGo == 2){
        A[mm[{x+1,y}]] = mm[dest];
        int nx = x;
        int ny = y +1;
        if(y == m+1){
            d = 2;
            changeGo = 3;
            x = n;
            y = m;
            SLV(cnt+1);
        }else {
            x = nx;
            y = ny;
            SLV(cnt+1);
        }
    }else if(changeGo == 3){
        A[mm[{x,y+1}]] = mm[dest];
        int nx = x-1;
        int ny = y;
        if(nx == 0){
            d = 1;
            changeGo = 4;
            x = 1;
            y = m;
            SLV(cnt+1);
        }else{
            x = nx;
            y = ny;
            SLV(cnt+1);
        }
    }else{
        A[mm[{x-1,y}]] = mm[dest];
        int nx = x;
        int ny = y-1;
        if(ny == 0){
            return;
        }else{
            x = nx;
            y = ny;
            SLV(cnt+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> L[i][j];
        }
    }
    for(int i = 0;i<2*(n+m);i++){
        A[i] = -1;
    }
    int cnt = 1;
    for(int i = 1;i<=n;i++){
        mm[{i,0}] = cnt++;
    }
    for(int i = 1;i<=m;i++){
        mm[{n+1,i}] = cnt++;
    }
    for(int i = n;i>=1;i--){
        
        mm[{i,m+1}] = cnt++;
    }
    for(int i = m;i>=1;i--){
        mm[{0,i}] = cnt++;
    }
    x = y = 1;
    d = 3;
    SLV(0);
    for(int i = 1;i<= 2*(n+m);i++){
        cout << A[i] << " ";
    }
}
