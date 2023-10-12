#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;
// 도형의 개수는 5가지
// 각 5가지의 경우에서 반전 회전의 경우들을 다 따져보면 될것같다.
int answer;
int N,M;
int board[501][501];
// 1. 청록색
// 좌우반전 의미 없음, 회전하는 경우만 따지만 총 2가지의 모습이 나온다.
void one() {
    // 1. 가로 버전
    vector<pair<int,int>> v = {{0,0},{0,1},{0,2},{0,3}};
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            int sum = 0;
            // i와 j를 시작점으로 잡고서 범위 내에 들어가는 경우에 대해서만 따지면 될것같다.
            int endY = v[3].second + j;
            // 범위를 벗어나는 경우
            if(endY >= M) continue;
            for(int z = 0;z<4;z++){
                sum += board[i+v[z].first][j+v[z].second];
            }
            answer = max(answer,sum);
        }
    }
    // 2. 세로 버전
    v = {{0,0},{1,0},{2,0},{3,0}};
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            int sum = 0;
            // i와 j를 시작점으로 잡고서 범위 내에 들어가는 경우에 대해서만 따지면 될것같다.
            int endX = v[3].first + i;
            // 범위를 벗어나는 경우
            if(endX >= N) continue;
            for(int z = 0;z<4;z++){
                sum += board[i+v[z].first][j+v[z].second];
            }
            answer = max(answer,sum);
        }
    }
}
// 2. 정사각형 모양
// 좌우반전 및 회전이 의미가 없다. 모양은 1개
void two() {
    vector<pair<int,int>> v = {{0,0},{0,1},{1,0},{1,1}};
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            int sum = 0;
            // i와 j를 시작점으로 잡고서 범위 내에 들어가는 경우에 대해서만 따지면 될것같다.
            int endX = v[3].first + i;
            int endY = v[3].second + j;
            // 범위를 벗어나는 경우
            if(endY >= M || endX >= N) continue;
            for(int z = 0;z<4;z++){
                sum += board[i+v[z].first][j+v[z].second];
            }
            answer = max(answer,sum);
        }
    }
}
// 3~5 번째 테트로미노들은 반전하면 다르고, 회전도 다 다르다
// 총 8개의 모양이다.
// 8개의 모양에 대한 인덱스를 다 설정하는거는 피곤하니깐
// 배열의 회전 공식을 이용해서 편하게 해보자
// 돌리는 배열의 틀은 가로 혹은 세로의 maxLength가 한변의 길이가 된다.
// 3~5 의 경우 모두 3*3 격자에서 돌린다고 생각하면 편할 듯
// 통일 성을 위해서 1~2 도 똑같이 할 순 있긴 한데 여기서는 3가지의 경우에 대해서만 해보자

// 3*3 격자 구조체를 만들고 내부 메소드로 회전 메소드를 만들자
// v는 테트로미노의 모양의 상대적 위치를 담은 것
// 회전은 시계 방향으로 만들어보자.
struct Grid {
    int b[3][3];
    vector<pair<int,int>> v;
    void rotate() {
        // 시계 방향으로 돌린다고 하면
        // 0,0 -> 0,2
        // 1,2 -> 2,1
        // 1,1 -> 1,1
        // 2,2 -> 2,0
        // i,j -> j , 3-i-1
        int tmp[3][3];
        // 회전 할 경우를 담아주고
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                tmp[i][j] = b[j][3-i-1];
            }
        }
        vector <pair<int,int>> tv;
        // 원본 배열에 복사해주기
        int mx = 3;
        int my = 3;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                b[i][j] = tmp[i][j];
                if(b[i][j] == 1) {
                    tv.push_back({i,j});
                    mx = min(mx,i);
                    my = min(my,j);
                }
            }
        }
        // 상대적 위치는 왼쪽 위를 기준으로 잡자
        for(int i = 0;i<tv.size();i++){
            tv[i].first -= mx;
            tv[i].second -= my;
        }
        v = tv;
    }
    void flip() {
        int tmp[3][3];
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                tmp[i][j] = b[i][3-j-1];
            }
        }
        vector <pair<int,int>> tv;
        // 원본 배열에 복사해주기
        int mx = 3;
        int my = 3;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                b[i][j] = tmp[i][j];
                if(b[i][j] == 1) {
                    tv.push_back({i,j});
                    mx = min(mx,i);
                    my = min(my,j);
                }
            }
        }
        // 상대적 위치는 왼쪽 위를 기준으로 잡자
        for(int i = 0;i<tv.size();i++){
            tv[i].first -= mx;
            tv[i].second -= my;
        }
        v = tv;
    }
    void copy(int L[3][3]) {
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                b[i][j] = L[i][j];
            }
        }
    }
};

// 뒤집기, 방향 돌리기 다 하는 함수
void caculate(int tmpList[3][3]) {
    Grid g;
    g.copy(tmpList);
    for(int f = 0;f<2;f++){
        g.flip();
        for(int t = 0;t<4;t++){
            g.rotate();
            for(int i = 0;i<N;i++){
                for(int j = 0;j<M;j++){
                    int sum = 0;
                    bool out = false;
                    // i와 j를 시작점으로 잡고서 범위 내에 들어가는 경우에 대해서만 따지면 될것같다.
                    for(int z = 0;z<4;z++){
                        int x = i+g.v[z].first;
                        int y = j+g.v[z].second;
                        if(x < 0 || x >= N || y <0 || y>= M) {
                            out = true;
                            break;
                        }
                        sum += board[i+g.v[z].first][j+g.v[z].second];
                    }
                    if(!out)
                        answer = max(answer,sum);
                }
            }
        }
    }
}
// 3. ㄴ모양 
// 회전 시 4개의 모양이 나오고, 반전도 바뀐다
// 총 8가지의 경우의 수
void three() {
    int tmpList[3][3] = {
        {1,0,0},
        {1,0,0},
        {1,1,0}
    };
    caculate(tmpList);
}
// 4. ㄱㄴ모양 
// 회전 시 4개의 모양이 나오고, 반전도 바뀐다
// 총 8가지의 경우의 수
void four() {
    int tmpList[3][3] = {
        {1,0,0},
        {1,1,0},
        {0,1,0}
    };
    caculate(tmpList);
}
// 5. ㅜ모양 
// 회전 시 4개의 모양이 나오고, 반전은 그대로
// 총 4가지의 경우의 수
void five() {
    int tmpList[3][3] = {
        {0,0,0},
        {1,1,1},
        {0,1,0}
    };
    caculate(tmpList);
}
void RUN() {
    one();
    two();
    three();
    four();
    five();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    answer = 0;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> board[i][j];
        }
    }
    RUN();
    cout << answer;
}