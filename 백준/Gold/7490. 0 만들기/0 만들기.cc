#include <iostream>
#include <vector>
#include <string>
using namespace std;
void SLV(string str,int limit){
  if(limit == str.length() + 1){
    int sum = 0;
    int tmp = 0;
    char command = 'x';
    vector<int> v;
    for(int i = 0;i<str.length();i++){
      if(str[i] == '1' || str[i] == '3'){
        if(tmp == 0){
          v.push_back(i+1);
        } else{
          v.push_back(tmp*10 + (i+1));
          tmp = 0;
        }
      }else if(str[i] == '2'){
        tmp = tmp*10 + (i+1);
      }
    }
    if(tmp != 0){
      v.push_back(tmp*10 + limit);
    }else {
      v.push_back(limit);
    }
    sum = v[0];
    int cnt = 1;
    bool flag = false;
    for(int i = 0;i<str.length();i++){
      if(str[i] == '2') continue;
      if(str[i] == '1') {
        flag = true;
        sum += v[cnt++];
      }else{
        flag = true;
        sum -= v[cnt++];
      }
    }
    if(sum == 0 && flag){
      for(int i = 0;i<str.length();i++){
        cout << i+1;
        if(str[i] == '1') cout << "+";
        else if(str[i] == '2') cout << " ";
        else cout << "-";
      }
      cout << limit;
      cout << "\n";
    }
    return;
  }
  SLV(str+"2",limit);
  SLV(str+"1",limit);
  SLV(str+"3",limit);
}
int main(){
  int T;
  cin >> T;
  while(T--){
    int number;
    cin >> number;
    SLV("",number);
    cout << "\n";
  }
}