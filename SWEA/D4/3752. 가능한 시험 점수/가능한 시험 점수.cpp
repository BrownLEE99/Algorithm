#include <iostream>
#include <algorithm>
using namespace std;
int N;
int score[101];
int pos[10001];
void init()
{
    for(int s = 0; s <= 10000; ++s)
    {
        pos[s] = 0;
    }
}
void optimize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    optimize();
    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; ++t)
    {
        init();
        cin >> N;
        int total_score = 0;
        for(int i = 1; i <= N; ++i)
        {
            cin >> score[i];
            total_score += score[i];
        }  
        pos[0] = true;
        for(int i = 1; i <= N; ++i)
        {
            for(int s = total_score; s >= 0; --s)
            {
                if(pos[s] == 1){
                    pos[s + score[i]] = 1;
                }
            }
        }
        int cnt = 0;
        for(int s = 0; s <= total_score; ++s)
        {
            if(pos[s])
            {
                cnt++;
            }  
        }
        cout << "#" << t << " " << cnt << "\n";
    }
}