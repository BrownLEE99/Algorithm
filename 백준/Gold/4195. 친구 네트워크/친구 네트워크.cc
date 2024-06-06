#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string,string> um;
unordered_map<string,int> nums;
string parent[200002];
int depth [200002];
int N,cnt;
string find_parent(string node) {
    if(um[node] == node) {
        return node;
    }
    return um[node] = find_parent(um[node]);
}
void make_union(string x, string y) {

    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return;

    um[y] = x;
    nums[x] += nums[y];

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
        nums.clear();
        string a,b;
        for(int i = 0; i < N; i++ ){
            cin >> a >> b;
            if(um.count(a) == 0) {
                um.insert({a,a});
                nums.insert({a,1});
            }
            if(um.count(b) == 0) {
                um.insert({b,b});
                nums.insert({b,1});
            }
            make_union(a,b);
            cout << nums[find_parent(a)]<<"\n";
        }
    }
}