#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdio>
using namespace std;

struct node{
    pair<int, int> pos;
    int n;
    node(pair<int, int> pos, int n){
        this->pos = pos;
        this->n = n;
    }
};

struct record{
    int x, y;
};

int main(){
    int m, mx;
    string tmp;
    bool *v = nullptr;
    vector< string > table;
    vector< record > ones;

    while (cin >> m){
        // ini
        int io = 0;
        table.clear();
        ones.clear();
        ones.resize(m * m);
        mx = 0;
        
        // input and record 1, 3 pos
        for (int i=0; i<m; i++){
            int j = 0;
        }

        // BFS find longest
        for (int s=0; s<ones.size(); s++){
            map < pair<int, int>, bool > v;

            // BFS
            queue< node > q;
            q.push(node(make_pair(ones[s].x, ones[s].y), 0));

            while (! q.empty() ){
                std::cout << "e";
                node front = q.front();
                q.pop();

                if (v.find(front.pos) != v.end()) // visited
                    continue;
                else if (table[front.pos.first][front.pos.second] == '3'){
                    mx = max (mx, front.n);
                }
                else
                    v[front.pos] = true;
            

                if (front.pos.first != 0){
                    q.push(node( make_pair(front.pos.first-1, front.pos.second),
                        front.n+1 ));
                }
                if (front.pos.first != m){
                    q.push(node( make_pair(front.pos.first+1, front.pos.second),
                        front.n+1 ));
                }
                if (front.pos.second != 0){
                    q.push(node( make_pair(front.pos.first, front.pos.second-1),
                        front.n+1 ));
                }
                if (front.pos.second != m){
                    q.push(node( make_pair(front.pos.first, front.pos.second+1),
                        front.n+1 ));
                }

            }
        }

        cout << mx;
    }


    return 0;
}