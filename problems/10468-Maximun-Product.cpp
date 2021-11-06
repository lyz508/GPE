#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector< int > v;

int main(){
    int c, t = 1;
    while (cin >> c){
        v.clear();
        for (int i=0, tmp; i<c; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        long long max_one = 0;
        for (int n=0; n<c; n++){
            for (int i=0; i<v.size()-n; i++){
                long long cmp = v[i];
                
                for (int m=1; m<=n; m++){
                    cmp *= v[i+m];
                }

                max_one = max(max_one, cmp);
            }
        }

        printf("Case #%d: The maximum product is %lld.\n\n", t++, (max_one < 0) ? 0 : max_one);
    }


    return 0;
}