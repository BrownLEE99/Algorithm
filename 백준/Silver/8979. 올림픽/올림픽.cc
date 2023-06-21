#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


vector <vector<int>> v;
bool comp(vector <int> a,vector<int> b){
    if(a[1]== b[1]){
        if(a[2] == b[2]){
            return a[3] > b[3];
        }else{
            return a[2] > b[2];
        }
    }
    return a[1] > b[1];
}
int main(){
    int a,k;
    cin >> a >> k;
    for(int i = 0;i<a;i++){
        int idx,g,s,b;
        cin >> idx >> g >> s >> b;
        v.push_back({idx,g,s,b});
    }
    sort(v.begin(),v.end(),comp);
    int rank = 1;
    int dup = 0;
    int last = 0;
    for(int i = 0;i<v.size()-1;i++){
        vector <int> cur = v[i];
        if(cur[0] == k){
            cout << last+1;
            break;
        }
        vector <int> next = v[i+1];
        bool same = true;
        for(int q = 1;q<next.size();q++){
            if(next[q] != cur[q]){
                same = false;
                break;
            }
        }
        if(same){
            dup++;
        }else{
            last = i+1;
            dup = 0;
        }
    }
}
