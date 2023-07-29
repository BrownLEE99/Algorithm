#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;

int K;
int N;
vector <string> level;
int main(){
    cin >> K;
    cin >> N;
    string output;
    cin >> output;
    int target;
    for(int i = 0;i<N;i++){
        string tmp;
        cin >> tmp;
        level.push_back(tmp);
        if(tmp[0] == '?') target = i;
    }
    
    // 1. ABCDEFG... 부터 ???? 전까지
    string start ="";
    for(int i = 0;i<K;i++){
        start += ('A'+ i);
    }
    //cout << start << "\n";
    for(int i = 0;i<target;i++){
        for(int j = 0;j<level[i].length();j++){
            char c = level[i][j];
            if(c == '-') { // 가로 막대기가 존재하면 두 알파벳의 위치를 변경
                char left = start[j];
                char right = start[j+1];
                start[j] = right;
                start[j+1] = left;
            }
        }
    }
    //cout << start;
    // 2. ouput부터 ???? 까지
    for(int i = N-1;i> target;i--){
        for(int j = 0;j<level[i].length();j++){
            char c = level[i][j];
            if(c == '-') { // 가로 막대기가 존재하면 두 알파벳의 위치를 변경
                char left = output[j];
                char right = output[j+1];
                output[j] = right;
                output[j+1] = left;
            }
        }
    }
    string answer = "";
    // 1과 2를 비교해서 한단계 만으로 1에서 2로 바꿀수 있는가?
    for(int i = 0;i<start.length()-1;i++){
        if(start[i] == output[i+1] && output[i] == start[i+1]){
            answer += "-";
            if(i+2 <start.length())
                answer += "*";
            i += 1;
        }else if(start[i] == output[i]){
            answer += "*";
        }else{
            answer = "x";
            break;
        }
    }
    if(answer == "x"){
        for(int i = 0;i<K-1;i++){
            cout << "x";
        }
    }else{
        cout << answer;
    }

}
