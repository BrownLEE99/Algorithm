#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    priority_queue<pair<int,int>> pq;
    for(int i = 0;i<k;i++){
        pq.push({stones[i],i});
    }
    int MaxMin = 200000001;
    MaxMin = min(MaxMin,pq.top().first);
    for(int i = k;i<stones.size();i++){
        pq.push({stones[i],i});
        while(pq.top().second < i-k+1) {
            pq.pop();
        }
        //cout << pq.top().first << "\n";
        MaxMin = min(MaxMin,pq.top().first);
    }
    return MaxMin;
}