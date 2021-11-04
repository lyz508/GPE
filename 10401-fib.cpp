#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int limit = 47;
vector<int> v;
map<int, int> m;

int main(){
    // build table
    v.resize(limit);
    v[0] = 1;
    v[1] = 1;
    m[1] = 1;
    for (int i=2; i<limit; i++){
        v[i] = v[i-1] + v[i-2];
        m[v[i]] = i;
    }

    // input
    // m[*it] is the wanted one
    int cases,
        input, tmp;
    vector<int>::iterator it;
    cin >> cases;
    while (cases--){
        cin >> input;
        cout << input << " = ";

        tmp = input;
        if (tmp == 1){
            cout << "1 (fib)\n";
            continue;
        }
        it = upper_bound(v.begin(), v.end(), tmp);

        for (int i=m[*it]-1; i>=1; i--){
            if (tmp - v[i] >= 0){
                cout << 1;
                tmp -= v[i];
            }
            else
                cout << 0;
        }  

        cout << " (fib)\n";
    }
    
    return 0;
}