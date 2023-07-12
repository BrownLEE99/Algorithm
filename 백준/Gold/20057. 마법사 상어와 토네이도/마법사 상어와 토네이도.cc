#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int answer = 0;
int N;
int A[500][500];

// 좌 아래 우 위 -> 토네이도의 방향이 바뀌는 순서
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int sand[5][5] =
{
    {0,0,2,0,0},
    {0,10,7,1,0},
    {5,0,0,0,0},
    {0,10,7,1,0},
    {0,0,2,0,0}
};

pair <int,int> tornado;

void changeSpreadSand(){
    int tmp[5][5];
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            tmp[i][j] = sand[i][j];
        }
    }
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            sand[i][j] = tmp[j][5-i-1];
        }
    }
}
// 모래가 퍼질 때 모래가 격자 밖으로 나갈 수 있다.

void spreadSand(int x,int y){
    int tmp = A[x][y];
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            int spreadedSand = (int)((tmp/100.0)*(double)sand[i][j]);
            int spx = x-2+i;
            int spy = y-2+j;
            A[x][y] -= spreadedSand;
            if(spx<0 || spy <0 || spx >= N || spy >= N){
                answer += spreadedSand;
                continue;
            }else{
                A[spx][spy] += spreadedSand;
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
            cin >> A[i][j];
        }
    }
    
    tornado = {N/2,N/2};
    int totalCount = 0;
    int level = 1; // 토네이도가 이동하는 거리(단계) 1,1 -> 2,2 -> 3,3 -> .. 식으로 증가한다
    int curDirect = 0; // 처음에 토네이도가 바라보는 방향은 왼쪽
    while(true){ // 모든 좌표를 방문할 때 까지 반복한다
        bool finish = false;
        // 아래 행동을 2 번씩 반복
        for(int i = 0;i<2;i++){
            // ** 마지막 레벨에서는 한번만 움직이면 끝난다
            // 각 단계의 길이만큼 움직인다
            int levelCnt = 0;
            bool finish2 = false;
            while(levelCnt < level){
                int nx = tornado.first + dx[curDirect];
                int ny = tornado.second + dy[curDirect];
                if(nx == 0 && ny == -1){
                    finish2 = true;
                    break;
                }
                //cout << nx << " " << ny << "\n";
                // 현재 위치에서 nx,ny 로 움직이면 nx,ny에 있는 모래 퍼지고, 바로보는 방향으로 남은 모래를 움직인다.
                // 1.y 위치를 기준으로 모래 뿌리기
                spreadSand(nx,ny);
                // 2. 남은 모래 뿌리기 (해당 단계에서 모래가 격자 밖으로 나갈 수 있다)
                int nx2 = nx + dx[curDirect];
                int ny2 = ny + dy[curDirect];
                if(!(nx2 < 0 || ny2 < 0 || nx2 >= N || ny2 >= N))
                    A[nx2][ny2] += A[nx][ny];
                else{
                    answer += A[nx][ny];
                }
                // 토네이도가 이동하는 위치에는 모래가 없다
                A[nx][ny] = 0;
                // 토네이도 위치 이동
                tornado = {nx,ny};
                
                levelCnt++;

            }
            if(finish2){
                finish = true;
                break;
            }
            // 각 길이만큼 움직일 때마다 방향을 바꾼다.
            curDirect = (curDirect+1) % 4;
            // 방향이 바뀌면 모래가 퍼지는 모양도 바뀐다
            changeSpreadSand();
            
            totalCount += level;
        }
        if(finish) break;
        // 해당 레벨이 끝나면 레벨 업
        level++;
    }
    cout << answer;
}
