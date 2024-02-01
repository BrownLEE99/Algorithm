#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> work[1001];
int staff[1001];
bool ck[1001];
bool dfs(int index) {
    if(ck[index]) return false;
    ck[index] = true;

    for(auto i : work[index]) {
        if(!staff[i] || dfs(staff[i])) {
            staff[i] = index;
            return true;
        }
    }
    return false;
}
int main() {
    int N,M;
    cin >> N >> M;
    for(int i = 1, A, B; i <= N; i++) {
        cin >> A;
        while(A--) {
            cin >> B;
            work[i].push_back(B);
        }
    }
    int answer = 0;
    for(int i = 1; i <= N; i++) {
        fill(ck, ck + N, false);
        if(dfs(i))
            ++answer;
    }
    cout << answer;
}