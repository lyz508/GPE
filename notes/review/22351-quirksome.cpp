#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector< int > table[4];
void build_table(){
    for (int d=2; d<=8; d+=2){
        int div = pow(10, d), 
            sub_div = pow(10, d/2), t;

        for (int n=0; n*n<div; n++){
            int j = n*n, 
                k = (j/sub_div + j%sub_div);
            if ( k*k == j )
                table[d/2-1].push_back(n*n);
        }
    }
}

int main(){
    int n;
    build_table();
    while (cin >> n){
        for (int i=0; i<table[n/2-1].size(); i++)
            printf("%0*d\n", n, table[n/2-1][i]);
    }

    return 0;
}