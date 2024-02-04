#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string clap = "";
        string str = to_string(i);
        for(int j = 0; j < str.length(); ++j)
        {
            if(str[j] == '3' || str[j] == '6' || str[j] == '9')
            {
                clap += "-";
            }
        }
        if(clap == "")
        {
            cout << i << " ";
        }
        else
        {
            cout << clap << " ";
        }
    }
}