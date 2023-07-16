#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int isPalindrome(string str){
    int mid = str.length()/2;
    bool isGood = true;
    int diff = 0;
    bool oneGood = true;
    bool twoGood = true;
    for(int i = 0;i<=mid;i++){
        if(diff == 0){
            if(str[i] == str[str.size()-i-1]){
                continue;
            }else{
                diff = 1;
                i--;
            }
        }else if(diff == 1){
                if(i <= str.size()-i-2)
                    if(str[i] != str[str.size()-i-2]){
                        oneGood = false;
                    }
                if(i+1 <= str.size()-i-1)
                    if(str[i+1] != str[str.size()-i-1]){
                        twoGood = false;
                    }
        
        }
    }
    
    if(diff == 0) return 0;
    if(oneGood || twoGood) return 1;
    return 2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testCase;
    string str;
    cin >> testCase;
    while(testCase-- > 0){
        cin >> str;
        cout << isPalindrome(str);
        cout << "\n";
    }
}
