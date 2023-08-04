#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;
int answer;
int main(){
    int testCase;
    cin >> testCase;
    
    while(testCase--){
        int n,budget;
        cin >> n >> budget;
        map <string,int> index;
        vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>> v;
        int idx = 0;
        
        // 각 부품 별 우선순위 큐
        // 우선순위는 가격 낮은거 먼저
        for(int i = 0;i<n;i++){
            string type,name;
            int price,quality;
            cin >> type >> name >> price >> quality;
            if(index.find(type) == index.end()){
                index[type] = idx++;
                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
                q.push({price,quality});
                v.push_back(q);
            }else{
                int node = index[type];
                v[node].push({price,quality});
            }
        }
        
        // 부품 별로 고른 거 담은 벡터
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pick;
        
        int minValue = 1000000000;
        
        int sum = 0;
        int minIdx = -1;
        
        
        // 맨처음에는 1하나씩 다 골라야함
        // 모든 부품의 퀄리티를 최소로 맞춘 컴퓨터
        for(int i = 0;i<v.size();i++){
            pair<int,int> top = v[i].top();
            v[i].pop();
            sum += top.first;
            pick.push({top.second,{i,top.first}});
            if(minValue > top.second){
                minValue =  top.second;
                minIdx = i;
            }
        }
        
        while(sum <= budget){
            answer = pick.top().first;
            pair<int,pair<int,int>> top = pick.top();
            pick.pop();
            int price = top.second.second;
            int number = top.second.first;
            int quality = top.first;
            while(v[number].size() != 0 && v[number].top().second <=  quality){
                v[number].pop();
            }
            if(v[number].size() == 0){
                break;
            }
            else{
                int newPrice = v[number].top().first;
                int newQuality = v[number].top().second;
                v[number].pop();
                sum = sum  + newPrice - price;
                pick.push({newQuality,{number,newPrice}});
            }
        }
        cout << answer << "\n";
    }

}
