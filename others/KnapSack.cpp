#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

/* KnapSack Problem:
 *  1. find largest weight can be put into knapsack
 *  2. give one combination of largest situation
 * w_sum: all weight sum
 * n: total number of items
 * value: array of value
 * weight: array of weight
 * cost: array recording height value of current weight; Length: sum+1 
 * record: bool array, record if item can be put in that weight
 */

void KnapSack(vector<int> weight, vector<int> value, int w_sum){
    vector<int> cost = vector<int>(w_sum+1, 0);
    vector< vector<bool> > record(value.size(), vector<bool>(w_sum+1, false));

    for (int i=0; i<value.size(); i++){
        for (int j=w_sum; j>=weight[i]; j--){
            if (cost[j - weight[i]] + value[i] > cost[j]){
                cost[j] = cost[j - weight[i]] + value[i];
                record[i][j] = true;
            }
        }
    }

    // print out item
    for (int i=value.size()-1, j=w_sum; i>=0; i--){
        if (record[i][j]){
            printf("Have %dth item\n", i);
            j -= weight[i];
        }
    }
    printf("Heighest value: %d", cost[w_sum]);
}

int main(){
    vector<int> w, v;
    int t1, t2, w_sum;
    
    printf("Input capacity: ");
    cin >> w_sum;

    printf("Input: (value, weight)\n");
    while (cin >> t1 >> t2){
        v.push_back(t1);
        w.push_back(t2);
    }
    
    KnapSack(w, v, w_sum);

    return 0;
}