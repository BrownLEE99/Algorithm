#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string,int> play;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    char type;
    cin >> n >> type;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        if(play[str] != 0) continue;
        play[str] = 1;
        cnt++;
    }
    if(type == 'Y'){
        cout << cnt;
    }
    else if(type == 'F'){
        cout << cnt/2;
    }
    else if(type == 'O'){
        cout << cnt/ 3;
    }
}
