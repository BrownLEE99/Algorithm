#include <iostream>
#include <vector>
using namespace std;
int V,E,nd1,nd2;
int parent[10001];
int total_child[10001];
vector <int> child[10001];
vector <int> node_parent[2];
int GET_CHILD(int node)
{
    int child_sum = 0;
    for(int i = 0; i < child[node].size(); ++i)
    {
        child_sum += GET_CHILD(child[node][i]);
    }
    total_child[node] = child_sum+1;
    return total_child[node];
}

void GET_PARENT(int node, int type)
{
    if(parent[node] == 0) return;
    node_parent[type].push_back(parent[node]);
    GET_PARENT(parent[node], type);
}
void init()
{
    for(int i = 0; i < 10001; ++i)
    {
        child[i].clear();
        parent[i] = 0;
        total_child[i] = 0;
    }
    node_parent[0].clear();
    node_parent[1].clear();
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
        init();
        cin >> V >> E >> nd1 >> nd2;
        for(int i = 0; i < E; ++i)
        {
            int p,c;
            cin >> p >> c;
            parent[c] = p;
            child[p].push_back(c);
        }
        parent[1] = 0;
        GET_CHILD(1);
        GET_PARENT(nd1,0);
        GET_PARENT(nd2,1);
        int answer = 0;
        for(int i = 0; i < node_parent[0].size(); ++i)
        {
            for(int j = 0; j < node_parent[1].size(); ++j)
            {
                if(node_parent[0][i] == node_parent[1][j])
                {
                    answer = node_parent[0][i];
                    break;
                }
            }
            if(answer != 0) break;
        }
        cout << "#" << t << " " << answer << " " << total_child[answer] << "\n";
    }
}