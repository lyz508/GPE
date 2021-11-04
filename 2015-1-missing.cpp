#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int main(){

    int m, n, *c_table;
    vector<int> v;

    c_table = new int[70000];
    memset(c_table, 0, sizeof(c_table));

    scanf("%d%d", &m, &n);

    for (int i=0, tmp; i<n; i++){
        scanf("%d", &tmp);
        v.push_back(tmp);
        c_table[tmp]++;
    }

    for (int t=0; t<m-1; t++){
        int table[70000] = {};
        for (int j=0, tmp; j < n-1; j++){
            scanf("%d", &tmp);
            table[tmp]++;
        }

        for (int i=0; i<v.size(); i++){
            // printf("%d %d\n", table[v[i]], c_table[v[i]]);

            if (table[v[i]] != c_table[v[i]]){
                printf("%d\n", v[i]);
                c_table[v[i]]--;
                if (c_table[v[i]] == 0)
                    v.erase(v.begin() + i);
            }
        }
        n --;
    }



    return 0;
}