#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int L[101][101];
bool check[101][101];
bool visited[5001];
int dp[5001][5001];
int d[5001];
bool flag;
vector<pair<int,int>> v;
pair<int,int> find_square(int x,int y)
{
    int nx = x, ny = y;
    while(nx < N && L[nx][y] >= 1) nx++;
    while(ny < N && L[x][ny] >= 1) ny++;
    for(int i = x; i < nx; ++i)
    {
        for(int j = y; j < ny; ++j)
        {
            check[i][j] = true;
        }
    }
    return {nx - x, ny - y};
}
void init()
{
    flag = false;
    for(int i = 0; i < 5001;++i) 
    {
        visited[i] = false;
    }
    v.clear();
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            check[i][j] = false;
            dp[i][j] = 987654321;
        }
    }
}
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
void find_and_sort(vector<pair<int,int>> tmp)
{
    if(tmp.size() == v.size())
    {
        d[0] = tmp[0].first;
        for(int i = 1; i< tmp.size();++i)
        {
            d[i] = tmp[i].first;
        }
        d[tmp.size()] = tmp[tmp.size()-1].second;
        flag = true;
        return;
    }
    if(flag)return;
    for(int i = 0; i < v.size(); ++i)
    {
        if(flag) return;
        if(!visited[i])
        {
            if(tmp.size() == 0 || (tmp.back().second == v[i].first)){
                visited[i] = true;
                tmp.push_back(v[i]);
                find_and_sort(tmp);
                tmp.pop_back();
                visited[i] = false;
            }
        }
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
        init();
        cin >> N;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                cin >> L[i][j];
            }
        }
        
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(L[i][j] >= 1 && !check[i][j])
                {
                    v.push_back(find_square(i,j));
                }
            }
        }
        vector<pair<int,int>> tmp;
        sort(v.begin(),v.end(),cmp);
        find_and_sort(tmp);
        for(int n = 0; n < v.size(); n++)
        {
            for(int i = 1; i <= v.size() - n; i++)
            {
                int j = i + n;
                if(i == j){
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] =987654321;
                    for(int k = i; k <= j -1; ++k)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j]);
                        //cout << i <<" " <<  j << " " << dp[i][j] << "\n";
                    }
                }
            }
        }
        cout << "#" << t << " " << dp[1][v.size()] << "\n";
    }
}