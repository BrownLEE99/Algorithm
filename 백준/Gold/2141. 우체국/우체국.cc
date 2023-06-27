#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

int n;
pair<long,long> pp [100001];
int main(){
    cin >> n;
    long long sum = 0;
    for(int i = 1;i<=n;i++){
        cin >> pp[i].first >> pp[i].second;
        sum += pp[i].second;
    }
    sort(pp+1,pp+n+1);
    long long cur = 0;
    for(int i = 1;i<=n;i++){
        cur += pp[i].second;
        if(cur >= (sum+1)/2) {
            cout << pp[i].first;
            break;
        }
    }
}
