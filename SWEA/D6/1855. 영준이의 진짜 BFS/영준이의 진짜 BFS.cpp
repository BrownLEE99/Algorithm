#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int,int> p;

int N;
vector <int> adj[100001];
int parent[100001][20];
int depth[100001];
int max_depth;
bool visited[100001];

void init()
{
    for(int i = 0; i < 100001; ++i)
    {
        adj[i].clear();
        depth[i] = 0;
        visited[i] = false;
    }
}

int LCA(int x, int y, int cnt)
{
    // x의 깊이가 더 작은걸로 세팅
    if(depth[x] > depth[y]) swap(x,y);
    // 만약 x가 y의 첫번째 부모이면 간선하나를 지나므로 return 1
    if(parent[y][0] == x) return 1;

    // x와 y의 높이를 동일한 높이를 맞춰 준다
    // 일단 y가 높이를 낮추는 거라서 거기에 대한 방문한 간선을 저장한다.
    for(int i = 19; i>= 0; --i)
    {
        if(depth[y] - depth[x] >= (1<<i))
        {
            y = parent[y][i];
            cnt += (1 << i);
        }
    }
    // 동일한 높이이지만 부모가 다를 경우(다른 서브 트리에 존재하는 것)
    if(parent[y][0] != parent[x][0])
    {
        // 높이가 동일하므로 둘 다 줄이면서 공통 조상을 찾는다.
        for(int i = 19; i >= 0; --i)
        {
            // x, y 둘 다 움직이므로 2 * (1 << i)
            if(parent[x][i] != parent[y][i])
            {
                cnt += 2 * (1 << i);
                x = parent[x][i];
                y = parent[y][i];
            }
        }
    }
    // 만약에 부모가 동일한 자식들이면 +2 해서 리턴 (x -> 부모 -> y)
    if(parent[x][0] == parent[y][0])
    {
        return cnt + 2;
    }
}

long long int BFS()
{
    long long int ret = 0;
    queue <int> q;
    q.push(1);
    visited[1] = true;
    int prev = 1, cur;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int i = 0; i < adj[node].size(); ++i)
        {
            int cnode = adj[node][i];
            if(visited[cnode]) continue;
            q.push(cnode);
            visited[cnode] = true;
            cur = cnode;
            ret += LCA(prev, cur, 0);
            prev = cur;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    max_depth = (int)floor(log2(100001));

    int test_case;
    cin >> test_case;

    for(int t = 1; t <= test_case; ++t)
    {
        init();
        cin >> N;
        parent[1][0] = 0;
        depth[1] = 0;
        for(int i = 2; i <= N; ++i)
        {
            int pnode;
            cin >> pnode;
            adj[pnode].push_back(i);
            parent[i][0] = pnode;
            depth[i] = depth[pnode] + 1;
        }
        for(int y = 1; y <= 19; ++y)
        {
            for(int x = 1; x <= N; ++x)
            {
                parent[x][y] = parent[parent[x][y-1]][y-1];
            }
        }
        cout << "#" << t << " " << BFS() << "\n";
    }
    
}