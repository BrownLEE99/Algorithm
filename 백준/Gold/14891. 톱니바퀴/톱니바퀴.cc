#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
#include <stack>
#include <math.h>
using namespace std;

// 1번이 2번과 맞닿은 인덱스 -> 2

// 2번이 1번과 맞닿은 인덱스 -> 6
// 2번이 3번과 맞닿은 인덱스 -> 2

// 3번이 2번과 맞닿은 인덱스 -> 6
// 3번이 4번과 맞닿은 인덱스 -> 2

// 4번이 3번과 맞닿은 인덱스 -> 6

// 톱니바퀴가 회전하면 인덱스가 변경되니깐 그냥 deque(덱)을 써도 되고,
// string자체로 돌려도 될것같다.

// 이번 풀이에서는 string만으로 돌리는 것으로 해보자
string gear[5];
// 시계 방향으로 회전
string clockwise(string input) {
    string output = (input[input.length()-1] + input).substr(0,input.length());
    return output;
}
// 반시계 방향으로 회전
string counterClockwise(string input) {
    string output = (input + input[0]).substr(1);
    return output;
}
// 왼쪽 확인
void rotateGearAndCheckLeft(int cur,int direction) {
    if(cur == 0) return ;

    int left = cur - 1;
    if(left >= 1) {
        if(gear[left][2] != gear[cur][6]) {
            rotateGearAndCheckLeft(left,0-direction);
        }
    }
    if(direction == 1) {
        gear[cur] = clockwise(gear[cur]);
    } else {
        gear[cur] = counterClockwise(gear[cur]);
    }
}
// 오른쪽 확인
void rotateGearAndCheckRight(int cur,int direction) {
    if(cur == 5) return ;
    int right = cur + 1;
    if(right <= 4) {
        if(gear[right][6] != gear[cur][2]) {
            rotateGearAndCheckRight(right,0-direction);
        }
    } 
    if(direction == 1) {
        gear[cur] = clockwise(gear[cur]);
    } else {
        gear[cur] = counterClockwise(gear[cur]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> gear[1] >> gear[2] >> gear[3] >> gear[4];
    int testCase;
    cin >> testCase;
    for(int i = 0;i<testCase;i++){
        int target,direction;
        cin >> target >> direction;
        rotateGearAndCheckLeft(target,direction);
        // 왼쪽 확인하면 현재 톱니바퀴가 회전된 상태라서 원상복구 한번만 해주자
        if(direction == 1) gear[target] = counterClockwise(gear[target]);
        else gear[target] = clockwise(gear[target]);
        rotateGearAndCheckRight(target,direction);

    }
    int answer = 0;
    for(int i = 1;i<=4;i++){
        if(gear[i][0] == '1') {
            answer += (int)pow(2,i-1);
        }
    }
    cout << answer;
}