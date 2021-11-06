#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector< vector<char> > t;

int find_square(int x, int y){
    int rtn = 1, rad = 1;
    char slf = t[x][y];

    while (1){
        bool brk = false;
        // loop expand
        for (int i=-rad; i<=rad; i++){
            for (int j=-rad; j<=rad; j++){
                if (x+i < t.size() && x+i >= 0 &&
                    y+j < t[0].size() && y+j >= 0){
                    // judge equal
                    if (t[x+i][y+j] != slf){
                        brk = true;
                        break;
                    }
                }
                else{
                    brk = true;
                    break;
                }
            }
        }

        if (brk)
            break;
        else{
            rtn += 2;
            rad++;
        }
    }

    return rtn;
}

int main(){
    int cse, m, n, q;
    cin >> cse;

    while (cse--){
        cin >> m >> n >> q;
        t.clear();
        // input
        for (int r=0; r<m; r++){
            vector< char > v;
            for (int c=0; c<n; c++){
                char tmp = (char)getchar();
                if (tmp == '\n'){
                    c--;
                    continue;
                }
                v.push_back(tmp);
            }
            t.push_back(v);
        }

        // questions
        printf("%d %d %d\n", m, n, q);
        for (int i=0, x, y; i<q; i++){
            cin >> x >> y;
            printf("%d\n", find_square(x, y));
        }
    }

    return 0;
}