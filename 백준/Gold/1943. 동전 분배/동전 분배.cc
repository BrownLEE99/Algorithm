#include <iostream>
#include <algorithm>
#include <vector>

#include <string>
#include <map>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 3;
    vector<int> ans;
    while(T--){
        int n,sum = 0;
        int L[50001];
        cin >> n;
        vector<pair<int,int>> c(n);
        for(int i = 0;i<n;i++){
            cin >> c[i].first >> c[i].second;
            sum += (c[i].first * c[i].second);
        }
        for(int i = 0;i<=50000;i++){
            L[i] = 0;
        }
        L[0] = 1;
        if(sum % 2 == 1) ans.push_back(0);
        else {
            int half = sum / 2;
            for(int i = 0;i<c.size();i++){
                for(int j = 50000;j>=0;j--){
                    if(j-c[i].first >=0){
                        if(L[j-c[i].first] == 1){
                            for(int k = 0;k<c[i].second;k++){
                                if(j + k * c[i].first > 50000) break;
                                L[j + k * c[i].first] = 1;
                            }
                        }
                    }
                }
            }
            ans.push_back(L[sum/2]);
        }
    }
    for(auto e : ans){
        cout << e << "\n";
    }
}
