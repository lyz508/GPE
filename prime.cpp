#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

bool isPrime(int x){
    if (x % 2 == 0){
        if (x != 2)
            return false; 
        if (x == 2)
            return true;
    }
    for (int i=2; i * i < x; i++){
        if (x % i == 0)
            return false;
    }
    return true;
};

int main(){
    vector<int> v;

    for (int i=2; i<100000; i++){
        if (isPrime(i))
            v.push_back(i);
    }
    printf("%d", v.size());

    return 0;
}