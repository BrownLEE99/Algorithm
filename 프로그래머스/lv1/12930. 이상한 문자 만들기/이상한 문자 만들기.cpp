#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] != ' '){
            if(idx%2 == 0){
                s[i] = toupper(s[i]);
            }else{
                s[i] = tolower(s[i]); 
            }
            idx++;
        }else{
            idx= 0;
        }
    }
    return s;
}