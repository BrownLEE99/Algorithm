#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

vector <vector<int>> vec;
int N;
int T[4];
bool check[16];
int minCost;
vector <vector<int>> visited;

void SLV(int idx,vector<vector<int>> v,int cost){
    if(idx == N){
        int A[4];
        int totalCost = 0;
        for(int i = 0;i<4;i++) A[i] = 0;
        vector<int> node;
        for(int i = 0;i<v.size();i++){
            for(int j = 1;j<=4;j++){
                A[j-1] += v[i][j];
            }
            totalCost += v[i][5];
            node.push_back(v[i][0]);
        }
        bool flag = true;
        for(int i = 0;i<4;i++){
            if(A[i] < T[i]){
                flag = false;
            }
        }
        if(flag){
            if(minCost > totalCost){
                minCost = totalCost;
                visited.clear();
                visited.push_back(node);
            }else if(minCost == totalCost){
                visited.push_back(node);
            }
        }
        return;
    }
    if(cost > minCost){
        return;
    }
    v.push_back(vec[idx]);
    SLV(idx+1,v,cost+vec[idx][5]);
    v.pop_back();
    SLV(idx+1,v,cost);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    minCost = 987654321;
    cin >> N;
    for(int i = 0;i< 4;i++){
        cin >> T[i];
    }
    for(int i = 0;i<N;i++){
        int p,f,s,v,c;
        cin >> p >> f >> s >> v >> c;
        vec.push_back({i+1,p,f,s,v,c});
    }
    vector<vector<int>> tmp;
    SLV(0,tmp,0);
    if(visited.size() == 0){
        cout << -1;
    }else{
        for(int i = 0;i<visited.size();i++){
            sort(visited[i].begin(),visited[i].end());
        }
        sort(visited.begin(),visited.end());
        cout << minCost  << "\n";
        for(auto a : visited[0]){
            cout << a << " " ;
        }
    }
}
