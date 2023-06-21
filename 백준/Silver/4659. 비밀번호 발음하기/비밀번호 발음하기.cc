#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool cls(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}
int main(){
    while(true){
        string str;
        cin >> str;
        if(str == "end") break;
        bool rule1 = false;
        bool rule2 = true;
        bool rule3 = true;
        char prev = '.';
        for(int i = 0;i<str.length();i++){
            char c = str[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                rule1 = true;
            }
            if(i > 0 && prev == c){
                if(!(c == 'e' || c == 'o')){
                    rule3 = false;
                    break;
                }
            }
            if(i>1){
                if(cls(c) == cls(str[i-1]) && cls(str[i-1]) == cls(str[i-2])){
                    rule2 = false;
                    break;
                }
            }
            prev = c;
        }
        if(rule1 && rule3 && rule2){
            cout << "<" << str << ">" << " is acceptable.\n";
        }else{
            cout << "<" << str << ">" << " is not acceptable.\n";
        }
    }
}
