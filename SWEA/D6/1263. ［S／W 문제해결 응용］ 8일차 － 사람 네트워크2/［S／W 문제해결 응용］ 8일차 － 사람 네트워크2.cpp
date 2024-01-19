#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector <int> adj[1001];
bool visited[1001];
void init()
{
    for(int i = 0; i < 1001; ++i) visited[i] = false;
}
int CC(int nd)
{
    queue <pair<int,int>> q;
    q.push({nd,0});

    visited[nd] = true;
    int sum = 0;
    while(!q.empty())
    {
        int node = q.front().first;
        int len = q.front().second;

        q.pop();
        for(int i = 0; i < adj[node].size(); ++i)
        {
            int new_node = adj[node][i];
            if(!visited[new_node])
            {
                visited[new_node] = true;
                sum += len + 1;
                q.push({new_node,len+1});
            }
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    for(int t = 1; t <= test_case; ++t)
    {
        cin >> N;
        for(int i = 1; i <= N; ++i)
        {
            adj[i].clear();
            for(int j = 1; j <= N; ++j)
            {
                int flag;
                cin >> flag;
                if(flag)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int min_sum = 987654321;
        for(int i = 1; i <= N; ++i)
        {
            init();
            min_sum = min(min_sum,CC(i));
        }
        cout << "#" << t << " " << min_sum << "\n";
    }
}