#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int M,N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    vector<int> snack(N,0);
    int s = 0;
    int e = 987654321;
    for(int i = 0;i<N;i++){
        cin >> snack[i];
        //e = max(e,snack[i]);
    }
    sort(snack.begin(),snack.end());
    while(s + 1 < e){
        int mid = (s+e)/2;
        int cnt = 0;
        for(int i = 0;i<snack.size();i++){
            cnt += (snack[i]/mid);
        }
        if(cnt >= M){
            s = mid;
        }else{
            e = mid;
        }
    }
    cout << e-1;
}
