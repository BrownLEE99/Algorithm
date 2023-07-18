#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(int i =1;i<=n;i++){
        int number;
        cin >> number;
        if(pq1.size() == pq2.size()){
            if(pq1.empty())
                pq1.push(number);
            else{
                int top1 = pq1.top();
                int top2 = pq2.top();
                if(top2<= number){
                    pq1.push(top2);
                    pq2.pop();
                    pq2.push(number);
                }else{
                    pq1.push(number);
                }
            }
        }else if(pq1.size() > pq2.size()){
            int top = pq1.top();
            if(top > number){
                pq1.pop();
                pq2.push(top);
                pq1.push(number);
            }else{
                pq2.push(number);
            }
        }else{
            int top = pq2.top();
            if(top <= number){
                pq2.pop();
                pq1.push(top);
                pq2.push(number);
            }else{
                pq1.push(number);
            }
        }
        cout << pq1.top() << "\n";
    }
}
