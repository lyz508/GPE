#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main(){
    int m, n, money;
    map<string, int> s;
    string tmp;
    cin >> m >> n;

    // money
    for (int i=0; i<m; i++){
        cin >> tmp >> money;
        s[tmp] = money;
    }
    for (int c = 0, t; c < n; c ++){
        t = 0;
        while (cin >> tmp && tmp != "."){
            if (s.find(tmp) != s.end()){
                t += s[tmp];
            }
        }
        printf("%d\n", t);
    }

    return 0;
}