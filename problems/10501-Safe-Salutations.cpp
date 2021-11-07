#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector< long long > dp;

void catalen(){
    dp[0] = 1;
    dp[1] = 1;
    for (int n=2; n<=20; n++){
        for (int i=0; i<n; i++){
            dp[n] += dp[i]*dp[n-1-i];
        }
    }
}

int main(){
    int n;
    bool f = true;
    dp.resize(21);
    catalen();

    while (cin >> n){
        // Presentation
        if (f) 
            f = false;
        else
            printf("\n");
        
        printf("%lld\n", dp[n]);
    }

    return 0;
}
