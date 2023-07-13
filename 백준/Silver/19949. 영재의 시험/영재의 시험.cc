#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int Answer[10];
int ans = 0;
void SLV(int idx,string visited){
    if(visited.length() >= 3 &&
       visited[visited.length()-1] == visited[visited.length()-2]
       && visited[visited.length()-2] ==
       visited[visited.length()-3]
       ) return;
    if(idx == 10){
        int cCount = 0;
        for(int i = 0;i<visited.length();i++){
            if((visited[i]-'0') == Answer[i]){
                cCount++;
            }
        }
        if(cCount >= 5) ans++;
        return;
    }
    for(int i = 1;i<=5;i++){
        SLV(idx+1,visited+to_string(i));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0;i<10;i++){
        cin >> Answer[i];
    }
    SLV(0,"");
    cout << ans;
}
