#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

int N,M,x,y,K;
int board[21][21];
int command;
int dice[6];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
// 그림에서 보이는 대로 순서를 매기면
// 2 -> 1
// 4 -> 2
// 1 -> 3
// 5-> 4
// 6-> 5
void left() {
    int top = dice[0];
    int secondLeft = dice[1];
    int secondMid = dice[2];
    int secondRight = dice[3];
    int third = dice[4];
    int fourth = dice[5];

    dice[0] = top;
    dice[1] = secondMid;
    dice[2] = secondRight;
    dice[3] = fourth;
    dice[4] = third;
    dice[5] = secondLeft;   
}
void right() {
    int top = dice[0];
    int secondLeft = dice[1];
    int secondMid = dice[2];
    int secondRight = dice[3];
    int third = dice[4];
    int fourth = dice[5];

    dice[0] = top;
    dice[1] = fourth;
    dice[2] = secondLeft;
    dice[3] = secondMid;
    dice[4] = third;
    dice[5] = secondRight;
}
void up() {
    int top = dice[0];
    int secondLeft = dice[1];
    int secondMid = dice[2];
    int secondRight = dice[3];
    int third = dice[4];
    int fourth = dice[5];

    dice[0] = secondMid;
    dice[1] = secondLeft;
    dice[2] = third;
    dice[3] = secondRight;
    dice[4] = fourth;
    dice[5] = top;
}
void down() {
    int top = dice[0];
    int secondLeft = dice[1];
    int secondMid = dice[2];
    int secondRight = dice[3];
    int third = dice[4];
    int fourth = dice[5];

    dice[0] = fourth;
    dice[1] = secondLeft;
    dice[2] = top;
    dice[3] = secondRight;
    dice[4] = secondMid;
    dice[5] = third;
}
bool isOut(int nx,int ny){
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> x >> y >> K;
    // 보드판 상태 입력받기
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> board[i][j];
        }
    }
    // 명령 입력받기
    for(int i = 0;i<K;i++){
        cin >> command;
        int nx = x + dx[command-1];
        int ny = y + dy[command-1];
        if(isOut(nx,ny)) continue;
        int flag = false;
        if(board[nx][ny] == 0) flag = true;
        switch(command) {
            case 1:
                right();
                if(flag) {
                    board[nx][ny] = dice[5];
                }
                else {
                    dice[5] = board[nx][ny];
                    board[nx][ny] = 0;
                }
                break;
            case 2:
                left();
                if(flag) {
                    board[nx][ny] = dice[5];
                }
                else {
                    dice[5] = board[nx][ny];
                    board[nx][ny] = 0;
                }
                break;
            case 3:
                up();
                if(flag) {
                    board[nx][ny] = dice[5];
                }
                else {
                    dice[5] = board[nx][ny];
                    board[nx][ny] = 0;
                }
                break;
            case 4:
                down();
                if(flag) {
                    board[nx][ny] = dice[5];
                }
                else {
                    dice[5] = board[nx][ny];
                    board[nx][ny] = 0;
                }
                break;    
            default:
                break;    
        }
        cout << dice[2] << "\n";
        x = nx;
        y = ny;
    }
}