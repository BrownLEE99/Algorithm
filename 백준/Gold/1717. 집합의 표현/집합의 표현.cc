#include <iostream>
#include <vector>
using namespace std;

int N,M;
int parent[1000001];

int find_parent(int node) {
    if (parent[node] == node) return node;
    return parent[node] == node ? node : (parent[node] = find_parent(parent[node]));
}

void make_union(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}
int main() {
    ios_base :: sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0 ; i< M ; i++) {
        int cmd,x,y;
        cin >> cmd >> x >> y;
        if(!cmd) {
            make_union(x,y);
        } else {
            if(find_parent(x) == find_parent(y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}