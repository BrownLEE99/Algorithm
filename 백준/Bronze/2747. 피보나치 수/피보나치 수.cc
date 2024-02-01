#include <iostream>
using namespace std;
long int fibo[46];
long int getFibo(int i) {
    if(i== 0) return 0;
    else if(i==1) return 1;
    else {
        if(fibo[i]!= 0){
            return fibo[i];
        }
        return getFibo(i-1) + getFibo(i-2);
    }
}
int main() {
    int n ;
    cin >> n;
    for(int i = 0;i<=n;i++){
        fibo[i] = getFibo(i);
    }
    cout << fibo[n];
}