#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
using namespace std;

int main(){
    string str="";
    cin >> str;
//    for(int i = 0;i<1000;i++){
//        if(i%2 ==0) str += "a";
//        else str += "b'";
//    }
    string tmp = str;
    sort(tmp.begin(),tmp.end());
    int cnt = (int)str.length();
    int minDiff = 1001;
    while(cnt--){
        int diff = 0;
        for(int i = 0;i<tmp.length();i++){
            if(tmp[i] != str[i]) diff++;
        }
        minDiff = min(minDiff, diff/2);
        char lastChar = tmp.back();
        tmp.pop_back();
        tmp = lastChar + tmp;
    }
    cout << minDiff;
    
}
