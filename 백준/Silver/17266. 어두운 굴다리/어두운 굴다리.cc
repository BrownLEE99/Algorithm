#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
int M;
vector <int> light;

int main(){
    cin >> N;
    cin >> M;
    for(int i = 0;i<M;i++){
        int location;
        cin >> location;
        light.push_back(location);
    }
    sort(light.begin(),light.end());
    int startToFirst = light[0]-0;
    int lastToEnd = N - light[light.size()-1];
    int maxH = 0;
    maxH = max(startToFirst,lastToEnd);
    for(int i = 1;i<light.size();i++){
        int gap = light[i] - light[i-1];
        maxH = max(maxH,(gap+1)/2);
    }
    cout << maxH;
}
