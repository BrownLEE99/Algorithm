#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N,M;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char L[50][50];
pair <int,int> sooyeon;
vector<pair <int,int>> devil;
bool svisit[50][50];
int BFS()
{
    svisit[sooyeon.first][sooyeon.second] = true;
    queue <vector<int>> s;
    s.push({sooyeon.first,sooyeon.second,0});

    int cur_time = 0;
    int answer = 0;
    while(!s.empty())
    {
        vector<int> v = s.front();
        s.pop();

        // 불이 움직이는 타임
        if(cur_time < v[2])
        {
            vector <pair<int,int>> new_devil;
            for(int i = 0; i < devil.size(); ++i)
            {
                for(int j = 0; j < 4; ++j)
                {
                    int nx = devil[i].first + dx[j];
                    int ny = devil[i].second + dy[j];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if(L[nx][ny] == 'D' || L[nx][ny] == 'X') continue;
                    if(L[nx][ny] == '.')
                    {
                        new_devil.push_back({nx,ny});
                    }
                }
            }
            for(int i = 0; i < new_devil.size(); ++i)
            {
                if(L[new_devil[i].first][new_devil[i].second] == '.')
                {
                    L[new_devil[i].first][new_devil[i].second] = '*';
                    devil.push_back(new_devil[i]);
                }
            }
            cur_time = v[2];
        }
        if(L[v[0]][v[1]] == '*') continue;

        // 탈출 성공
        if(L[v[0]][v[1]] == 'D')
        {
            answer = v[2];
            break;
        }
        for(int i = 0; i < 4; ++i)
        {
            int nx = v[0] + dx[i];
            int ny = v[1] + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(L[nx][ny] == 'X' || L[nx][ny] == '*') continue;
            if(!svisit[nx][ny])
            {
                svisit[nx][ny] = true;
                s.push({nx,ny,v[2] + 1});
            }
        }
    }
    
    return answer;
}
void init()
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            svisit[i][j] = false;
        }
    }
    devil.clear();
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
        cin >> N >> M;
        init();
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                cin >> L[i][j];
                if(L[i][j] == 'S')
                {
                    sooyeon = {i,j};
                }
                if(L[i][j] == '*')
                {
                    devil.push_back({i,j});
                }
            }
        }
        int answer = BFS();
        if(answer != 0)
        {
            cout << "#" << t << " " << answer << "\n";
        }
        else
        {
            cout << "#" << t << " " << "GAME OVER" << "\n";
        }
    }
}