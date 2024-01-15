#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N;
pair <int,int> company;
pair <int,int> home;
vector<pair<int,int>> clients;
bool visited[10];
int min_cost;
void DFS(pair<int,int> cur, int cost)
{
    if(min_cost < cost) return;
    bool flag = false;
    for(int i = 0; i < clients.size(); ++i)
    {
        if(!visited[i])
        {
            flag = true;
            visited[i] = true;
            DFS(clients[i], cost + abs(cur.first - clients[i].first) + abs(cur.second - clients[i].second));
            visited[i] = false;
        }
    }
    if(flag == false)
    {
        int total_cost = cost + abs(cur.first - home.first) + abs(cur.second - home.second);
        if(min_cost > total_cost) min_cost = total_cost;
    }
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
        for(int i = 0; i < N; ++i) visited[i] = false;
        cin >> company.first >> company.second;
        cin >> home.first >> home.second;

        for(int i = 0; i < N; ++i)
        {
            int x,y;
            cin >> x >> y;
            clients.push_back({x,y});
        }
        min_cost = 987654321;
        DFS(company,0);
        clients.clear();

        cout << "#" << t << " " << min_cost << "\n";
    }
}