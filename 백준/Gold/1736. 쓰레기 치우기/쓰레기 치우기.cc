#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

// 열 하나씩 청소를 진행한다
// 위의 열의 로봇의 위치를 벡터에 저장한다
// 각 로봇 위치 전까지 쓰레기들을 쭉 정리해서 마지막 위치(각 로봇의 위치 바로 뒤)까지 청소
// 만약에 위의 줄의 첫번째 로봇 전에 쓰레기가 존재하면 로봇 하나를 추가해야함
int L[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    /*for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> L[i][j];
        }
    }
    int prev = 101;
    int ans1 = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(L[i][j] == 1){
                if(j <= prev){
                    ans1++;
                    prev = j;
                }
                break;
            }
        }
    }
    prev = 101;
    int ans2 = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(L[j][i] == 1){
                if(j <= prev){
                    ans2++;
                    prev = j;
                }
                break;
            }
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    cout << min(ans1,ans2);*/
    
    vector <int> v;
    int ans = 0;
    for(int i = 0;i<n;i++){
        
        if(v.size() == 0){
            int lastRobot = -1;
            for(int j = 0;j<m;j++){
                cin >> L[i][j];
                if(L[i][j] == 1){
                    lastRobot = j;
                }
            }
            if(lastRobot != -1){
                v.push_back(lastRobot);
                ans++;
            }
        }else{
            vector <int> nv;
            for(int j = 0;j<m;j++){
                cin >> L[i][j];
            }
            int lastRobot1 = -1;
            for(int j = 0;j<v[0];j++){
                if(L[i][j]==1) lastRobot1 = j;
            }
            if(lastRobot1 != -1) {
                nv.push_back(lastRobot1);
                ans++;
            }
            for(int x = 0;x<v.size()-1;x++){
                int lastRobot = -1;
                for(int j = v[x];j<v[x+1];j++){
                    if(L[i][j] == 1) lastRobot = j;
                }
                if(lastRobot != -1){
                    nv.push_back(lastRobot);
                }else{
                   nv.push_back(v[x]);
                }
            }
            int lastRobot2 = -1;
            for(int j = v[v.size()-1];j<m;j++){
                if(L[i][j]==1) lastRobot2 = j;
            }
            if(lastRobot2 != -1) nv.push_back(lastRobot2);
            else {
                nv.push_back(v[v.size()-1]);
            }
            v = nv;
        }
        
    }
    cout << ans;
}
