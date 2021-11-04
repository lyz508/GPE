#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int cases, tmp, many, mid[2];
    bool odd;
    vector<int> table;

    while (cin >> cases){
        many = 0;
        table.clear();
        for (int time=0; time<cases; time++){
            cin >> tmp;
            table.push_back(tmp);
        }
        sort(table.begin(), table.end());
        mid[0] = table[(cases-1)/2];
        mid[1] = table[cases/2];
        odd = true;
        
        for (int i=0; i<table.size(); i++){
            if (table[i] == mid[0] || table[i] == mid[1])
                many++;
        }
        printf("%d %d %d\n", mid[0], many, mid[1]-mid[0]+1);
    }

    return 0;
}