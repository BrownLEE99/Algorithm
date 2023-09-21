#include <iostream>
using namespace std;
int parent[501];
bool isCycle[501];
int findP(int node) {
    if(parent[node] == node) return node;
    else return parent[node] = findP(parent[node]);
}
int unionP(int a,int b) {
    a = findP(a);
    b = findP(b);

    if(a == b) return a;
    else {
        if( a> b) {
            parent[a] = b;
        }else {
            parent[b] = a;
        }
    }
    return -1;
}
void checkP(int node) {
    isCycle[node] = true;
    if(parent[node] == node) return;
    checkP(parent[node]);
}
int main() {
    int n,m;
    int T = 1;
    while(true) {
        cin >> n >> m;
        if(n==0 && m == 0) break;
        for(int i = 1;i<=n;i++){
            parent[i] = i;
            isCycle[i] = false;
        }
        int answer = 0;
        for(int i = 0;i<m;i++){
            int a,b;
            cin >> a >> b;
            int P = unionP(a,b);
            if(P != -1) {
                isCycle[P] = true;
            }
        }
        for(int i = 1;i<=n;i++){
            if(isCycle[i]) {
                checkP(i);
            }
        }
        cout << "Case " << T << ": ";
            for(int i = 1;i<=n;i++){
                if(parent[i] == i && !isCycle[i]) {
                    answer++;
                }
            }
            if(answer == 1){
                cout << "There is one tree.";
            }else if(answer > 1){
                cout << "A forest of " << answer << " trees.";
            } else if(answer == 0){
                cout << "No trees.";
            }

        
        cout << "\n";
        T++;
    }
}