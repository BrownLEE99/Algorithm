#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
using namespace std;
int N;
int H[10];
int main(){
    cin >> N;
    for(int i = 0;i<N;i++){
        int h;
        cin >> h;
        for(int j =0;j<N;j++){
            if(h == 0 && H[j] == 0){
                H[j] = i+1;
                break;
            }
            else if(H[j] == 0){
                h--;
            }
        }
    }
    for(int i = 0;i<N;i++){
        cout << H[i] << " ";
    }
}
