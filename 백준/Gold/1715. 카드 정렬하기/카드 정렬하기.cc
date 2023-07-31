#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;

struct cmp {
    bool operator()(int a,int b){
        return a > b;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int N;
    cin >> N;
    vector<int> input(N,0);
    priority_queue<int,vector<int>,cmp> pq;
    for(int i = 0;i<N;i++){
        int number;
        cin >> number;
        pq.push(number);
    }
    long long sum = 0;
    while(pq.size() >= 2){
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        sum += (A+B);
        pq.push(A+B);
    }
    cout << sum;
}
