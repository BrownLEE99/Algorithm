#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> building(n);
  for(int i = 0;i<n;i++){
    cin >> building[i];
  }
  int maxCnt = 0;
  // Check every building's
  for(int i = 0;i<n;i++){
    // left side
    int cnt = 0;
    for(int l = i-1;l>=0;l--){
      double mid = ((double)building[i] - building[l])/(i-l);
      bool flag = true;
      // check building between i and left
      for(int m = l+1;m<i;m++){
        if((double)building[m]- building[l] >= mid * (m-l)) {
          flag = false;
          break;
        }
      }
      if(flag) cnt++;
    }
    // right side
    for(int r = i+1;r<n;r++){
      double mid = ((double)building[r] - building[i])/(r-i);
      bool flag = true;
      // check building between i and left
      for(int m = r-1;m>i;m--){
        if((double)building[m] - building[i] >= mid * (m-i)) {
          flag = false;
          break;
        }
      }
      if(flag) cnt++;
    }

    maxCnt = max(maxCnt,cnt);
  }
  cout << maxCnt;
}