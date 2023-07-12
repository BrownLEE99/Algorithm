#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int N,C,M;
vector <vector<int>> v;
int bucket[101];
bool cmp(vector<int> a , vector<int> b){
    if(a[1] == b[1]) return a[0] > b[0];
    return a[1] < b[1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> C;
    cin >> M;
    for(int i = 0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),cmp);
    int answer = 0;
    for(int i = 0;i<v.size();i++){
        vector<int> tmp = v[i];
        // 넣을 수 있는 공간의 최솟값
        int posSize = 987654321;
        for(int j = tmp[0];j<tmp[1];j++){
            
            posSize = min(posSize,C - bucket[j]);
        }
        if(posSize > 0){
            if(posSize > tmp[2]) posSize = tmp[2];
            for(int j = tmp[0];j<tmp[1];j++){
                bucket[j] += posSize;
            }
            answer += posSize;
        }
    }
    cout << answer;
}
