#include <string>
#include <vector>

using namespace std;
int B[60][60];
vector<vector<int>> rotate(vector<vector<int>> v){
    int S = v.size();
    vector<int> tmp(v.size(),0);
    vector<vector<int>> res(v.size(),tmp);
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v.size();j++){
            res[i][j] = v[v.size()-j-1][i];
        }
    }
    return res;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    for(int i =0;i<lock.size();i++){
        for(int j = 0;j<lock.size();j++){
            B[i+20][j+20] = lock[i][j];
        }
    }
    
    for(int i = 21;i<=20+key.size()+lock.size()-1;i++){
        for(int j = 21;j<=20+key.size()+lock.size()-1;j++){
            int startx = i-key.size();
            int starty = j-key.size();
            
            for(int r = 0;r<4;r++){
                key = rotate(key);
                for(int x = 0;x<key.size();x++){
                    for(int y = 0;y<key.size();y++){
                        B[x+startx][y+starty] ^= key[x][y];
                    }
                }
                bool isSuccess = true;
                for(int x = 0;x<lock.size();x++){
                    for(int y = 0;y<lock.size();y++){
                        if(B[x+20][y+20] != 1) {
                            isSuccess = false;
                            break;
                        }
                    }
                    if(!isSuccess) break;
                }
                if(isSuccess){
                    return true;
                }else{
                    for(int x = 0;x<key.size();x++){
                        for(int y = 0;y<key.size();y++){
                            B[x+startx][y+starty] ^= key[x][y];
                        }
                    }
                }
            }
        }
    }
    return false;
}