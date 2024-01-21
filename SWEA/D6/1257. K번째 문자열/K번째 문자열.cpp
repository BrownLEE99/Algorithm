#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
set <string> string_set;

void PICK(string &str)
{
    for(int i = 0; i < str.length(); ++i)
    {
        for(int j = 1; j + i <= str.length(); ++j)
        {
            string substr = str.substr(i,j);
            string_set.insert(substr);
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
        string_set.clear();
        int index;
        cin >> index;
        string str;
        cin >> str;
        PICK(str);
        string result = "";
        // for(auto it = string_set.begin(); it != string_set.end(); ++it)
        // {
        //     cout << *it << "\n";
        // }
        if(string_set.size() < index) result = "none";
        else
        {
            //sort(string_set.begin(),string_set.end());
            vector <string> v(string_set.begin(),string_set.end());
            result = v[index-1];
        }
        cout << "#" << t << " " << result << "\n";
    }
}