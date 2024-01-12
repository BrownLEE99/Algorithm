#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int cnt[101];
void init()
{
    for(int i = 0 ; i < 101; ++i)
    {
        cnt[i] = 0;
    }
}
int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        init();
        int test_case;
        cin >> test_case;
        int max_cnt = 0;
        int max_number = 0;
        for(int i = 0; i < 1000; ++i)
        {
            int number;
            cin >> number;
            cnt[number]++;  
            if(cnt[number] > max_cnt)
            {
                max_cnt = cnt[number];
                max_number = number;
            }
            else if(cnt[number] == max_cnt)
            {
                if(max_number < number)
                {
                    max_number = number;
                }
            }
        }
        cout << "#" << t << " " << max_number << "\n";
    }
}