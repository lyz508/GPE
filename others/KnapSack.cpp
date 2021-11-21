#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int numObj = 3, numWeight=20;
int dp[numObj+1][numWeight+1],
    w[numObj], v[numObj];

int main(){
    memset(dp, 0, sizeof(dp));
    printf("value and weight: ");
    for (int i=0; i<3; i++)
        cin >> v[i] >> w[i];

    /*Knapsack*/
    for (int i=0; i<numObj; i++){
        for (int j=0; j<=numWeight; j++){
            if (j - w[i] < 0)
                dp[i+1][j] = dp[i][j];
            else
                dp[i+1][j] = max(
                    dp[i][j], // dont choose
                    dp[i][j - w[i]] + v[i]
                );
        }
    }
    printf("Highest: %d\n", dp[numObj][numWeight]);

    return 0;
}