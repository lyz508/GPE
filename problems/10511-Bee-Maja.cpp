#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector< pair<int, int> > table;

void build(){
    int round = 1;

    table.resize(120000);
    table[1] = make_pair(0, 0);
    table[2] = make_pair(0, 1);
    for (int p=3; p<120000;){
        for (int i=0; i<round && p < 120000; i++){
            table[p] = make_pair( table[p-1].first-1, table[p-1].second );
            p++;
        }
        for (int i=0; i<round && p < 120000; i++){
            table[p] = make_pair( table[p-1].first, table[p-1].second-1 );
            p++;
        }
        for (int i=0; i<round && p < 120000; i++){
            table[p] = make_pair( table[p-1].first+1, table[p-1].second-1 );
            p++;
        }
        for (int i=0; i<round && p < 120000; i++){
            table[p] = make_pair( table[p-1].first+1, table[p-1].second );
            p++;
        }
        for (int i=0; i<round+1 && p < 120000; i++){
            table[p] = make_pair( table[p-1].first, table[p-1].second+1 );
            p++;
        }
        for (int i=0; i<round && p < 120000; i++){
            table[p] = make_pair( table[p-1].first-1, table[p-1].second+1 );
            p++;
        }
        round++;
    }
}

int main(){
    int n;
    build();

    while (cin >> n){
        printf("%d %d\n", table[n].first, table[n].second);
    }

    return 0;
}