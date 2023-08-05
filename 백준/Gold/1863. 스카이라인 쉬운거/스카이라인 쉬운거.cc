#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
#include <stack>
using namespace std;

int n;
vector<pair<int,int>> v;
int main(){
    cin >> n;
    int answer = 0;
    for(int i = 0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    stack <int> s;
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        int height = v[i].second;
        if(s.empty()){
            if(height != 0)
                s.push(height);
        }else{
            if(s.top() < height){
                s.push(height);
            }
            else {
                while(!s.empty() && s.top() > height){
                    answer++;
                    s.pop();
                }
                if((s.empty() && height != 0) || (!s.empty() && s.top() < height)){
                    s.push(height);
                }
                
            }
        }
    }
    if(!s.empty()){
        answer += s.size();
    }
    cout << answer;
}
