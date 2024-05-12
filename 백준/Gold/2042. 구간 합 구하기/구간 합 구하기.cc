#include <iostream>
using namespace std;

typedef long long int ll;

#define MAX_SQRT (1000)

int N,M,K;
ll arr[1001000];
ll sqrtSum[MAX_SQRT + 10];

// 합의 구간을 루트(N 최댓값)으로 설정한 것
void sqrtDecomposition()
{
    int sqrtIndex = 0;
    int count = N / MAX_SQRT;
    int start, end;

    for(int i = 0; i < count; i++)
    {
        start = i * 1000;
        end = start + 1000;

        for(int k = start; k < end; k++)
            sqrtSum[sqrtIndex] += arr[k];

        sqrtIndex++;
    }
    start = count * 1000;
    end = N;

    for(int k = start; k < end; k++) {
        sqrtSum[sqrtIndex] += arr[k];
    }
}

void update(int index, ll value)
{
    int sqrtIndex = index / MAX_SQRT;

    sqrtSum[sqrtIndex] -= arr[index];
    arr[index] = value;
    sqrtSum[sqrtIndex] += arr[index];
}

ll getSum(int left, int right)
{
    ll sum = 0;
    int leftSqrtIndex = left / MAX_SQRT;
    int rightSqrtIndex = right / MAX_SQRT;

    if(leftSqrtIndex == rightSqrtIndex)
    {
        for(int i = left; i <= right; i++) {
            sum += arr[i];
        }
        return sum;
    }
    for(int i = leftSqrtIndex + 1; i < rightSqrtIndex;i++) {
        sum += sqrtSum[i];
    }
    int end = (leftSqrtIndex + 1) * 1000;
    for(int i = left; i < end; i++) sum += arr[i];
    int start = (rightSqrtIndex) * 1000;
    for(int i = start; i<= right;i++) sum += arr[i];

    return sum;
}

int main()
{
    cin >> N >> M >> K;
    for(int i = 0; i< N;i++){
        cin >> arr[i];
    }
    sqrtDecomposition();

    for(int i = 0; i< M+K;i++) {
        int a;
        cin >> a;
        if(a == 1){
            int b;
            ll c;
            cin >> b >> c;
            update(b-1,c);
        } else {
            int b,c;
            cin >> b >> c;
            cout << getSum(b-1,c-1) << "\n";
        }
    }
    return 0;
}