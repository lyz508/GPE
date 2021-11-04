#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long t[1000010] = {};
int counct = 0;

int do3n_1(long long n){
    int length = 1;
    while (n != 1){
        if (n % 2 != 0)
            n = 3*n +1;
        else
            n = n/2;
        length ++;
    }
    return length;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio();

    long long i, j, max, tmp, start, end;
    
    for (int i=1; i<1000000; i++){
        t[i] = do3n_1(i);
    }

    while (cin >> i >> j){
        start = min(i, j);
        end = std::max(i, j);
        max = t[start];
        for (long long num=start+1; num<=end; num++){
            max = std::max((long long int)max, t[num]);
        }
        printf("%d %d %d\n", i, j, max);
    }
    return 0;
}