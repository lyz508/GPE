#include <iostream>
#include <cstdio>
using namespace std;

long long table[51] = {};
void build_table(){
    table[0] = 1;
    table[1] = 1;
    for (int i=2; i<51; i++)
        table[i] = table[i-1] + table[i-2];
}

int main(){
    build_table();

    int num;
    while (cin >> num){
        if (num == 0)
            break;
        printf("%lld\n", table[num]);
    }

    return 0;
}