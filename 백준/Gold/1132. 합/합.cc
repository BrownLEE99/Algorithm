#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n;
long long AJ[10];
int rk[10];
bool isFirst[10];
vector<pair<int,long long>> v;
bool cmp(pair<int,long long> a,pair<int, long long> b){
    return a.second > b.second;
}
vector <string> input;
long long loc(int x){
    long long res = 1;
    while(x--){
        res *= 10;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        input.push_back(str);
        isFirst[str[0]-'A'] = true;
        for(int j = 0;j<str.length();j++){
            AJ[str[j]-'A'] += loc(str.length()-j);
        }
    }
    for(int i = 0;i<10;i++){
        v.push_back({i,AJ[i]});
    }
    sort(v.begin(),v.end(),cmp);
//    for(int i = 0;i<v.size();i++){
//        cout << v[i].first << "\n";
//    }
    if(isFirst[v[9].first]){
        for(int i = 8;i>=0;i--){
            if(!isFirst[v[i].first]){
                pair<int,long long> tmp;
                tmp = v[i];
                v.erase(v.begin()+i);
                v.push_back(tmp);
                break;
            }
        }
    }
    for(int i = 0;i<v.size();i++){
        AJ[v[i].first] = 9-i;
    }
//    for(int i = 0;i<v.size();i++){
//        cout << AJ[i] << " ";
//    }
    long long answer = 0;
    for(int i = 0;i<input.size();i++){
        string str = input[i];
        string tmp = "";
        for(int i = 0;i<str.length();i++){
            tmp += (AJ[(str[i]-'A')]+'0');
        }
        answer += stoll(tmp);
        //cout << stoll(tmp) << "\n";
    }
    cout << answer;
}

