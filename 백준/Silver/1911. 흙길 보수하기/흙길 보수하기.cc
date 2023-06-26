#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        int s,e;
        cin >> s >> e;
        v.push_back({s,e});
    }
    sort(v.begin(),v.end());
    int cur = 0;
    int ans = 0;
    for(int i = 0;i<v.size();i++){
        if(v[i].first >= cur) cur = v[i].first;
        int len = (v[i].second - cur);
        if(len <= 0) continue;
        int need = len/l;
        if(len%l != 0) need++;
        cur += (need*l);
        ans += need;
    }
    cout << ans;
}
