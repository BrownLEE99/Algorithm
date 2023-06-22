#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        vector <int> v[26];
        string s;
        int k;
        cin >> s;
        cin >> k;
        for(int i = 0;i<s.length();i++){
            v[s[i]-'a'].push_back(i);
        }
        int game3 = 10001;
        int game4 = 0;
        for(int i = 0;i<26;i++){
            vector <int> tmp = v[i];
            if(tmp.size() < k) continue;
            for(int j = 0;j<=tmp.size()-k;j++){
                game3 = min(game3,tmp[j+k-1]-tmp[j] + 1);
                game4 = max(game4,tmp[j+k-1]-tmp[j] + 1);
            }
        }
        if(game3 == 10001 || game4 == 0){
            cout << -1 << "\n";
        }else{
            cout << game3 << " " << game4 << "\n";
        }
    }
}
