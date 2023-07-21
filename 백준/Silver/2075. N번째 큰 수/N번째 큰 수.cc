#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    priority_queue<int> pq;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            int number;
            cin >> number;
            pq.push(-number);
            if(pq.size() > N) pq.pop();
        }
    }
    cout << -pq.top();
}
