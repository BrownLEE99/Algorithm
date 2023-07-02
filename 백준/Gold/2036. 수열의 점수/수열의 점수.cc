#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define INIT 1000001
int n;
struct cmp {
    bool operator()(long long a,long long b){
        if( a<0 && b < 0 ){
            return abs(a) < abs(b);
        }else{
            return a < b;
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    cin >> n;
    priority_queue<long long,vector<long long>,cmp> pq;
    int zero = 0;
    for(int i = 0;i<n;i++){
        int number;
        cin >> number;
        if(number == 0){
            zero++;
        }else{
            pq.push(number);
        }
    }
    long long sum = 0;
    long long prev = INIT;
    while(!pq.empty()){
        long long number = pq.top();
        pq.pop();
        if(prev == INIT){
            prev = number;
            continue;
        }
        if(prev > 0 && number > 0){
            if(number == 1){
                sum += prev;
                sum += number;
            }else{
                sum += (prev * number);
            }
            prev = INIT;
            continue;
        }
        if(prev > 0 && number < 0){
            sum += prev;
            prev = number;
            continue;
        }
        if(prev < 0 && number < 0){
            sum += (prev*number);
            prev = INIT;
            continue;
        }
    }
    if(prev != INIT){
        if(prev > 0){
            sum += prev;
        }else if(prev < 0){
            if(zero == 0){
                sum += prev;
            }
        }
    }
    cout << sum;
}

