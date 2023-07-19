#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
using namespace std;
int H[10];
int CHECK[10];
int N;
void PICK(vector<int> v){
    if(v.size() == N){
        
        for(int i = 0;i<v.size();i++){
            int cnt = 0;
            for(int j = 0;j<i;j++){
                if(v[j] > v[i]) {
                    cnt++;
                }
            }
            if(H[v[i]] != cnt) return ;
        }
        for(int i = 0;i<v.size();i++){
            cout << v[i] << " ";
        }
        return ;
    }
    for(int i = 1;i<= N;i++){
        if(CHECK[i]) continue;
        CHECK[i] = true;
        v.push_back(i);
        PICK(v);
        v.pop_back();
        CHECK[i] = false;
    }
}
int main(){
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> H[i];
    }
    vector<int> v;
    PICK(v);
}
