#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
#include <stack>
#include <math.h>
using namespace std;

// 브루트포스로 푼다고 생각해보면
// 그냥 4방향 다 다르다고 가정하고
// 최대 CCTV가 8개니깐
// 확인하는 경우의 수가 4^8 ->2^16 = 65536

// 최대 크기 8*8에서 매순간 건들이는 배열의 크기가 최악으로(5번의 경우)
// 한 16개 정도

int N,M;
int board[8][8];
vector <vector<int>> cctv;
int answer = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool isOut(int nx,int ny) {
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) return true;
    return false;
}
int RUN(vector<vector<int>> v) {
    int tmp[8][8];
    memcpy(&tmp,&board,sizeof(board));
    for(int i = 0;i<v.size();i++){
        int type = v[i][2];
        int x = v[i][0];
        int y = v[i][1];
        int d = v[i][3];
        if(type == 1) {
            while(true) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(isOut(nx,ny)) break;
                if(tmp[nx][ny] == 6) break;
                if(tmp[nx][ny] == 0) {
                    tmp[nx][ny] = 7;
                }
                x = nx;
                y = ny;
            }
        } else if(type == 2) {
            queue <vector<int>> q;
            if(d == 0) {
                q.push({x,y,0});
                q.push({x,y,2});
            } else {
                q.push({x,y,1});
                q.push({x,y,3});
            }
            while(!q.empty()){
                vector<int> p = q.front();
                q.pop();
                int nx = p[0] + dx[p[2]];
                int ny = p[1] + dy[p[2]];
                if(isOut(nx,ny)) continue;
                if(tmp[nx][ny] == 6) continue;
                if(tmp[nx][ny] == 0) {
                    tmp[nx][ny] = 7;
                } 
                q.push({nx,ny,p[2]});     
            }
        } else if(type == 3) {
            queue <vector<int>> q;
            q.push({x,y,d});
            q.push({x,y,(d+1)%4});
            while(!q.empty()){
                vector<int> p = q.front();
                q.pop();
                int nx = p[0] + dx[p[2]];
                int ny = p[1] + dy[p[2]];
                if(isOut(nx,ny)) continue;
                if(tmp[nx][ny] == 6) continue;
                if(tmp[nx][ny] == 0) {
                    tmp[nx][ny] = 7;
                } 
                q.push({nx,ny,p[2]});     
            }
        } else if(type == 4) {
            queue <vector<int>> q;
            for(int i = 0;i<4;i++){
                if(d == i) continue;
                q.push({x,y,i});
            }
            while(!q.empty()){
                vector<int> p = q.front();
                q.pop();
                int nx = p[0] + dx[p[2]];
                int ny = p[1] + dy[p[2]];
                if(isOut(nx,ny)) continue;
                if(tmp[nx][ny] == 6) continue;
                if(tmp[nx][ny] == 0) {
                    tmp[nx][ny] = 7;
                } 
                q.push({nx,ny,p[2]});     
            }
        }else if(type == 5) {
            queue <vector<int>> q;
            for(int i = 0;i<4;i++){
                q.push({x,y,i});
            }
            while(!q.empty()){
                vector<int> p = q.front();
                q.pop();
                int nx = p[0] + dx[p[2]];
                int ny = p[1] + dy[p[2]];
                if(isOut(nx,ny)) continue;
                if(tmp[nx][ny] == 6) continue;
                if(tmp[nx][ny] == 0) {
                    tmp[nx][ny] = 7;
                } 
                q.push({nx,ny,p[2]});     
            }
        }
    }
    int zeroCount = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(tmp[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    return zeroCount;
}
void PICK(int cnt,vector<vector<int>> v) {
    if(cnt == cctv.size()) {
        int cantSee = RUN(v);
        answer = min(answer,cantSee);
        return ;
    }
    int type = cctv[cnt][2];
    int x = cctv[cnt][0];
    int y = cctv[cnt][1];
    if(type == 1 || type ==3 || type == 4) {
        for(int i = 0;i<4;i++){
            v.push_back({x,y,type,i});
            PICK(cnt+1,v);
            v.pop_back();
        }
    } else if(type == 2) {
        for(int i = 0;i<2;i++){
            v.push_back({x,y,type,i});
            PICK(cnt+1,v);
            v.pop_back();
        }
    } else if(type == 5) {
        v.push_back({x,y,type,0});
        PICK(cnt+1,v);
        v.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    answer = 100;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5) {
                cctv.push_back({i,j,board[i][j]});
            }
        }
    }
    vector<vector<int>> tmp;
    PICK(0,tmp);
    cout << answer;
}