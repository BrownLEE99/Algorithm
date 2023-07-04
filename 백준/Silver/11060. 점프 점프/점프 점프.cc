#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int n;
vector <int> v;
int dp[1001];
int JUMP(int idx){
    if(idx == n-1){
        return 0;
    }
    int &res = dp[idx];
    if(res != 987654321){
        return res;
    }
    //int minJ = 987654321;
    for(int i = 1;i<=v[idx];i++){
        res = min(res,JUMP(i+idx)+1);
    }
    return res;
    
}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        dp[i] = 987654321;
    }
    for(int i = 0;i<n;i++){
        int number;
        cin >> number;
        v.push_back(number);
    }
    int answer = JUMP(0);
    if(answer == 987654321) cout << -1;
    else cout << answer;
    
}
