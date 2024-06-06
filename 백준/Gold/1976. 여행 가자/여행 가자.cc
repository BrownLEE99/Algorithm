#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int parent[202];
int getP(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = getP(parent[x]);
}
void Union(int a,int b){
    a = getP(a);
    b = getP(b);
    
    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}
int main(){
    cin >> n;
    cin >> m;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i =0;i<n;i++){
        int a;
        for(int j = 0;j<n;j++){
            cin >> a;
            if(a == 1){
                Union(i+1,j+1);   
            }
        }
    }
    vector <int> in;
    for(int i = 0;i<m;i++){
        int a;
        cin >> a;
        in.push_back(a);
    }
    int p = parent[in[0]];
    bool flag = true;
    for(int i = 0;i<in.size();i++){
        if(parent[in[i]] != p){
            flag = false;
            break;
        }
    }
    cout << (flag ? "YES" : "NO");
}