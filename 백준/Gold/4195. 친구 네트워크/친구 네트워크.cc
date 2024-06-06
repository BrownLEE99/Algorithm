#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string,int> um;
int parent[200002];
int sizes [200002];
int N,cnt;
int find_parent(int node) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}
void make_union(int x, int y) {

    x = find_parent(x);
    y = find_parent(y);
    if(x == y) return ;
    if( x > y) swap(x,y);
    sizes[x] += sizes[y];
    parent[y] = x;
}
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int test_case;
    cin >> test_case;
    cnt = 0;
    for(int t = 0 ; t < test_case; t++) {
        cin >> N;
        um.clear();
        cnt = 1;
        string a,b;
        for(int i = 0; i < N; i++ ){
            cin >> a >> b;
            if(um.count(a) == 0) {
                um[a] = cnt++;
                parent[um[a]] = um[a];
                sizes[um[a]] = 1;
            }
            if(um.count(b) == 0) {
                um[b] = cnt++;
                parent[um[b]] = um[b];
                sizes[um[b]] = 1;
            }
            make_union(um[a],um[b]);
            int x = find_parent(um[a]);
            int y = find_parent(um[b]);
            cout << max(sizes[x],sizes[y]) << "\n";
            // cout << a << ":" <<um[a] << " " << b << ":" << um[b] << "\n";
        }
    }
}