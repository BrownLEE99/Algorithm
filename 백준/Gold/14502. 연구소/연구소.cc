#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
#include <stack>
using namespace std;

// 바이러스가 최대로 퍼지는 걸 막기 위해 추가로 벽을 3개 세우자

// 벽을 3개 세울 때 뭐 최적화된 장소를 실제로 해보지 않고서는 찾을 수 없어 보인다.
// -> 그냥 0인 공간에서 3개 다 골라봐서 확인해보자
// 최대 8*8사이즈에 3개 고르는거니깐
// 64C3 의 경우가 있겠네요
int N,M;
int board[8][8];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<pair<int,int>> candidate;
vector <pair<int,int>> virus;
int answer;
void SPREAD() {
    int tmp[8][8];
    queue <pair<int,int>> q;
    memcpy(&tmp,&board,sizeof(board));
    for(int i = 0;i<virus.size();i++){
        q.push(virus[i]);
    }
    // 바이러스 퍼뜨리고
    while(!q.empty()){
        pair <int,int> p = q.front();
        q.pop();

        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(tmp[nx][ny] == 0) {
                tmp[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
    // 청정 구역 개수 확인
    int clean = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(tmp[i][j] == 0) {
                clean++;
            }
        }
    }
    answer = max(answer,clean);
}

// 벽 세울 곳 고르기
void PICK(int cnt,int prevIdx) {
    // 3개 다 골랐으면 실제로 바이러스를 투하
    if(cnt == 3) {
        SPREAD();
        return ;
    }
    for(int i = prevIdx+1;i<candidate.size();i++){
        pair<int,int> picked = candidate[i];
        board[picked.first][picked.second] = 1;
        PICK(cnt+1,i);
        board[picked.first][picked.second] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    answer = 0;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j =0;j<M;j++){
            cin >> board[i][j];
            if(board[i][j] == 0) {
                candidate.push_back({i,j});
            }
            if(board[i][j] == 2) {
                virus.push_back({i,j});
            }
        }
    }
    // 3개 고르고 다 고르면 퍼뜨리고 결과 확인하면 된다.
    PICK(0,-1);

    cout << answer;
}