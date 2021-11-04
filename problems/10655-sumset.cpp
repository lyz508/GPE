#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    while (cin >> n && n != 0){
        vector<int> v;
        int ans;
        bool f = false;

        for (int i=0, tmp; i<n; i++){
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), greater<int>());

        for (int d = 0; d < n && !f; d++){
            for (int a = 0; a < n && !f; a++){
                if (a == d) continue;
                for (int b = a+1; b < n && !f; b++){
                    if (b == d) continue;
                    for (int c = b+1; c < n && !f; c++){
                        if (c == d) continue;
                        if (v[a] + v[b] + v[c] == v[d]){
                            f = true;
                            ans = v[d];
                        }

                    }
                }
            }
        }

        if (f)
            printf("%d\n", ans);
        else
            printf("no solution\n");
    }


    return 0;
}