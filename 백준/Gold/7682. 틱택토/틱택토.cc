#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    while(true){
        string str;
        cin >> str;
        if(str == "end") break;
        int tt[3][3];
        int cnt = 0;
        int xcount = 0;
        int ocount = 0;
        int ncount = 0;
        for(int i = 0;i<str.length()/3;i++){
            for(int j = 0;j<str.length()/3;j++){
                char c = str[cnt++];
                if(c == 'X'){
                    tt[i][j] = -1;
                    xcount++;
                }
                if(c == 'O'){
                    tt[i][j] = 1;
                    ocount++;
                }
                if(c == '.') {
                    tt[i][j] = 0;
                    ncount++;
                }
            }
        }
        bool valid = true;
        int xwin = 0;
        int owin = 0;
        // 가로 확인
        for(int i = 0;i<3;i++){
            int sum = 0;
            for(int j = 0;j<3;j++){
                sum += tt[i][j];
            }
            if(sum == 3) owin++;
            if(sum == -3) xwin++;
        }
        // 세로 확인
        for(int i = 0;i<3;i++){
            int sum = 0;
            for(int j = 0;j<3;j++){
                sum += tt[j][i];
            }
            if(sum == 3) owin++;
            if(sum == -3) xwin++;
        }
        // 대각선 확인
        int sum1 = tt[0][0] + tt[1][1] + tt[2][2];
        int sum2 = tt[0][2] + tt[1][1] + tt[2][0];
        if(sum1 == 3 || sum2 == 3) owin++;
        if(sum1 == -3 || sum2 == -3) xwin++;
        if(xwin > 0 && owin > 0) valid = false;
        if(xwin > 0) if(xcount != ocount+1) valid = false;
        if(owin > 0) if(xcount != ocount) valid = false;
        if(xwin == 0 && owin == 0) if(!(xcount == ocount || xcount == ocount+1)) valid = false;
        if(xwin == 0 && owin == 0) if(ncount != 0) valid = false;
        if(valid) cout << "valid\n";
        else cout << "invalid\n";
    }
}
