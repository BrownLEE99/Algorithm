#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int S,N;
int L[101][101];
bool checkDamage(int x,int y,int length,int cnt)
{
    int tmp = 0;
    for(int i = x; i <= x + length -1; ++i)
        for(int j = y; j <= y + length - 1; ++j)
            if(L[i][j] == 1) tmp++;

    return (cnt == tmp);   
}
void attach(int x, int y, int length)
{
    for(int i = x; i <= x + length -1; ++i)
        for(int j = y; j <= y + length - 1; ++j)
            L[i][j] = 0;
}
int main()
{
    int test_case;
    int T;
    cin >> T;
    for(test_case = 1; test_case <= T; test_case++)
    {
        cin >> S;
        cin >> N;
        for(int i = 0; i <= S; ++i)
            for(int j = 0; j <= S; ++j)
                L[i][j] = 0;
        for(int i = 0,x,y; i < N; ++i)
        {
            cin >> x >> y;
            L[x][y] = 1;
        }
        
        vector<vector<int>> answer;
        int total = 0;
        for(int l = 9; l >= 5; --l)
            for(int x = 1; x <= S-2; ++x)
                for(int y = 1; y <= S-2; ++y)
                    if(checkDamage(x,y,3,l))
                    {
                        attach(x,y,3);
                        total++;
                        answer.push_back({x,y,3});
                    }
        
        for(int l = 4; l >= 2; --l)
            for(int x = 1; x <= S-1; ++x)
                for(int y = 1; y <= S-1; ++y)
                    if(checkDamage(x,y,2,l))
                    {
                        attach(x,y,2);
                        total++;
                        answer.push_back({x,y,2});
                    }

        for(int x = 1; x <= S; ++x)
            for(int y = 1; y <= S; ++y)
                if(checkDamage(x,y,1,1))
                {
                    attach(x,y,1);
                    total++;
                    answer.push_back({x,y,1});
                }
        
        cout << "#" << test_case << " " << total << " ";
        for(auto v: answer)
        {
            cout << v[0] << " " << v[1] << " " << v[2] << " ";
        }
        cout << "\n";

    }
}