
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V,E;
vector <int> adj[1001];
int pre[1001];
void SLV(queue <int> q)
{
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        //cout << "node: " << node << " " << pre[node] << "\n";

        if(pre[node] == 0)
        {
            pre[node]--;
            cout << node << " ";
            for(int i = 0; i < adj[node].size(); ++i)
            {
                int next = adj[node][i];
                pre[next]--;
                q.push(next);
            }
        }
    }
}
void init()
{
    for(int i = 1; i <= V; ++i) 
    {
        pre[i] = 0;
        adj[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case = 10;
    for(int t = 1; t <= test_case; ++t)
    {
        cin >> V >> E;
        init();
        for(int i = 0; i < E; ++i)
        {
            int s,e;
            cin >> s >> e;
            adj[s].push_back(e);
            pre[e]++;
        }
        queue <int> q;
        for(int i = 1; i <= V; ++i)
        {
            if(pre[i] == 0)
            {
                q.push(i);
            }
        }
        cout << "#" << t << " ";
        SLV(q);
        cout << "\n";
    }
}