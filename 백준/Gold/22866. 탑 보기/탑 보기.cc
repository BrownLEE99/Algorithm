#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;
int building[100001];
pair<int,int> closest[100001];
int h[100001];
stack <pair<int,int>> s;
void findClosestBuilding(int i){
    int gap= abs(s.top().first-i);
    if(abs(s.top().first-i) < closest[i].second){
        closest[i].second = gap;
        closest[i].first = s.top().first;
    }else if(gap == closest[i].second){
        closest[i].first = min(closest[i].first,s.top().first);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        closest[i] = {0,100001};
        building[i] = 0;
        cin >> h[i];
    }
    for(int i = 1;i<=n;i++){
        if(s.empty()) s.push({i,h[i]});
        else{
            if(s.top().second > h[i]){
                building[i] += s.size();
                findClosestBuilding(i);
                s.push({i,h[i]});
            }else{
                while(!s.empty() && s.top().second <= h[i]){
                    s.pop();
                }
                building[i] += s.size();
                if(!s.empty())
                    findClosestBuilding(i);
                s.push({i,h[i]});
            }
        }
    }
    while(!s.empty())s.pop();
    for(int i = n;i>=1;i--){
        if(s.empty()) s.push({i,h[i]});
        else{
            if(s.top().second > h[i]){
                building[i] += s.size();
                findClosestBuilding(i);
                s.push({i,h[i]});
            }else{
                while(!s.empty() && s.top().second <= h[i]){
                    s.pop();
                }
                building[i] += s.size();
                if(!s.empty())
                    findClosestBuilding(i);
                s.push({i,h[i]});
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(closest[i].second == 100001) cout << 0 << "\n";
        else
            cout << building[i] << " " << closest[i].first << "\n";
    }
}

