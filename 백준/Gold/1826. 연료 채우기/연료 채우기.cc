#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;
vector <pair<int,int>> gasStation;
int N;
int target,oil;

void SLV(int idx){
    
}
int main(){
    
    cin >> N;
    for(int i = 0;i<N;i++){
        int a,b;
        cin >> a >> b;
        gasStation.push_back({a,b});
    }
    cin >> target >> oil;
    sort(gasStation.begin(),gasStation.end());
    
    
    int idx = 0;
    int answer = 0;
    priority_queue<int> pq;
    while(target > oil){
        while(idx < N && gasStation[idx].first <= oil){
            pq.push(gasStation[idx++].second);
        }
        
        if(!pq.empty()){
            oil += pq.top();
            pq.pop();
            answer++;
        }else if(idx == N || gasStation[idx].first > oil){
            answer = -1;
            break;
        }
    }
    cout << answer;
}
