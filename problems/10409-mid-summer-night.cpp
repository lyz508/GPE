#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int tmp, n, mid[2], m;
    vector<int> v;

    while (cin >> n){
        v.clear();
        m = 0;
        for (int i=0; i<n; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end());
        mid[0] = v[n/2];
        mid[1] = v[(n-1)/2];

        for (int i=0; i<v.size(); i++){
            if (v[i] == mid[0] || v[i] == mid[1])
                m++;
        }

        printf("%d %d %d\n", mid[1], m, mid[0]-mid[1]+1);
    }

    return 0;
}