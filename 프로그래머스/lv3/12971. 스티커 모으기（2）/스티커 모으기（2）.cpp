#include <iostream>
#include <vector>
using namespace std;
int dp[100001]; 
int dp2[100001];
int solution(vector<int> sticker)
{
    int answer =0;
    if(sticker.size() <= 3){
        for(int i = 0;i<sticker.size();i++)
            answer = max(answer,sticker[i]);
    }
    else
    {
        dp[1] = sticker[1];
        dp[2] = max(dp[1],sticker[2]);
        answer = max(dp[1],dp[2]);
     // 첫번째 스티커 없다고 가정
        for(int i = 3;i< sticker.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+sticker[i]);
            answer = max(dp[i],answer);
        }
        // 마지막 스티커가 없다고 가정
        dp2[0] = sticker[0];
        dp2[1] = max(dp2[0],sticker[1]);
        answer = max(max(answer,dp2[0]),dp2[1]);
        for(int i = 2;i<sticker.size()-1;i++){
            dp2[i] = max(dp2[i-1],dp2[i-2] + sticker[i]);
            answer = max(dp2[i],answer);
        }
    }

    return answer;
}