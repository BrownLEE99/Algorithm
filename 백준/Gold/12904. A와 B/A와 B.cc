#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;
string input;
string output;
int answer  = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> input;
    cin >> output;

    while(output.length() > input.length()){
        char lastWord = output[output.length()-1];
        output = output.substr(0,output.length()-1);
        if(lastWord == 'B'){
            reverse(output.begin(),output.end());
        }
    }
    if(output == input){
        cout << 1;
    }else{
        cout << 0;
    }
}
