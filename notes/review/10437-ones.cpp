#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    string inp;
    int n, t1, t2, c = 1;
    vector<double> table;

    while (cin >> inp){
        table.clear();

        for (int i=0; i<inp.size()-1; i++){
            if (inp[i] != inp[i+1])
                table.push_back(i + 0.5);
        }

        cin >> n;
        printf("Case %d:\n", c++);

        while (n--){
            cin >> t1 >> t2;
            int tmp1, tmp2, w = 0;
            tmp1 = min(t1, t2);
            tmp2 = max(t1, t2);

            for (int i=0; i<table.size(); i++){
                if (table[i] >= tmp1 && table[i] <= tmp2)
                    w = 1;
            }
            if (w)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }

    return 0;
}