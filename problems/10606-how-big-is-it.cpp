#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        double ans = 1e9, cur, tmp;
        vector<double> v, p;

        cin >> n;
        p.resize(n);

        for (int i=0; i<n; i++){
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());

        do {
            p[0] = v[0];
            cur = 2*v[0];
            for (int i=1; i<v.size(); i++){
                p[i] = v[i];
                for (int j=0; j<i; j++) // maintain RHS
                    p[i] = max(p[i], p[j] + 2*sqrt(v[i]*v[j]));
                cur = max(cur, p[i] + v[i]);
            }
            ans = min(ans, cur);
        }while (next_permutation(v.begin(), v.end()));
        printf("%.3lf\n", ans);
    }

    return 0;
}