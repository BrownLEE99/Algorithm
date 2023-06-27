#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

int n;
int price[10];
int V[51];
int m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int minCost = 100;
    int mina = 0;
    int minCost2 = 100;
    int minb = 0;
    for(int i = 0;i<n;i++){
        cin >> price[i];
        if(minCost2 >= price[i]){
            minCost2 = price[i];
            minb = i;
        }
        if(i > 0){
            if(minCost >= price[i]){
                minCost = price[i];
                mina = i;
            }
        }
    }
    cin >> m;
    int chg = m-minCost;
    if(chg < 0){
        cout << 0;
        return 0;
    }
    int cnt = chg/minCost2;
    int chg2 = chg%minCost2;
    string answer = "";
    for(int i = 0;i<cnt;i++){
        answer += to_string(minb);
    }
    answer = to_string(mina) + answer;
    for(int i = 0;i<answer.length();i++){
        if(chg2 == 0) break;
        int number = answer[i] - '0';
        int tmp = number;
        for(int j = n-1;j>=0;j--){
            if(price[j]-price[number] <= chg2){
                answer[i] = j+'0';
                chg2 -= (price[j]-price[number]);
                break;
            }
        }
    }
    cout << answer;
}
