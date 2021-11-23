#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector< vector<char> > map;

// transfer
char find(int x, int y){
    if (map[x][y] == '*')
        return '*';

    int rtn = 0;
    for (int r=-1; r<=1; r++){
        for (int c=-1; c<=1; c++){
            if (x+r >= 0 && x+r < map.size() &&
                y+c >= 0 && y+c < map[0].size())
                if (map[x+r][y+c] == '*')
                    rtn ++;
        }
    }

    return '0'+rtn;
}

int main(){
    int c = 1, m, n;

    while ( cin>>m>>n ){
        if ( m==0 && n==0 ) break;
        map.clear();
        // input
        for (int r=0; r<m; r++){
            vector< char > v;
            for (int c=0; c<n; c++){
                char t = (char)getchar();
                if (t == '\n'){
                    c--;
                    continue;
                } // ignore '\n'
                v.push_back(t);
            }
            map.push_back(v);
        }

        // print map
        if (c != 1) printf("\n");
        printf("Field #%d:\n", c++);
        
        for (int r=0; r<m; r++){
            for (int c=0; c<n; c++){
                cout << find(r, c);
            }
            cout << "\n";
        }
    }


    return 0;
}