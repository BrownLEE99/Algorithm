#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

// 고기를 사면 해당 고기보다 싼 고기들을 꽁짜로 얻는다
// 누적합?

bool cmp(pair<int,int> a,pair<int,int> b){
    if(b.second == a.second) return a.first > b.first;
    return a.second < b.second;
}
vector <pair<int,int>> meat;
int n,m;
int main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        meat.push_back({a,b});
    }
    sort(meat.begin(),meat.end(),cmp);
    int w=0,v=0;
    int prev = -1;
    for(int i = 0;i<meat.size();i++){
        if(w >= m){
            if((prev!=meat[i].second) && (v >= meat[i].second)){
                prev = v = meat[i].second;
            }
        }else{
            if(prev == meat[i].second){
                v += meat[i].second;
            }else{
                prev = v = meat[i].second;
            }
        }
        
        w += meat[i].first;
    }
    if(w < m) {
        cout << -1;
    }else{
        cout << v;
    }
    
}
