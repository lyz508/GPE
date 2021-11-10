#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

struct node{
    vector< int > adj;
    int self;
};

int main(){
    // input
    int ds, first = 1;
    cin >> ds;
    cin.ignore();

    for (int dds=0; dds<ds; dds++){
        if (first == 1) // output new line
            first = 0;
        else
            printf("\n");

        string tmp;
        char mode;
        int nodes, n, m, solved = 0, unsolved = 0;
        vector< node > v;
        cin >> nodes;
        cin.ignore();
        v.resize(nodes+1);
        for (int i=0; i<v.size(); i++)
            v[i].self = i;

        while (getline(cin, tmp) && tmp.length()!=0){
            stringstream ss;
            ss << tmp;
            ss >> mode >> n >> m;
            
            if (mode == 'c'){
                v[n].adj.push_back(m);
                v[m].adj.push_back(n);
            }
            else if (mode == 'q'){
                // BFS
                queue< node > q;
                vector< bool > visited;
                bool found = false;

                visited.resize(nodes+1);
                q.push(v[n]);
                while (! q.empty()){
                    node f = q.front();
                    q.pop();
                    if (visited[ f.self ])
                        continue;
                    else
                        visited[ f.self ] = true;

                    for (int i=0; i<f.adj.size(); i++){
                        if ( f.adj[i]==m ){
                            found = true;
                            break;
                        }
                        q.push( v[f.adj[i]] );
                    }
                }
                // judge solve
                if (found)
                    solved++;
                else
                    unsolved++;
            }
        }

        printf("%d,%d\n", solved, unsolved);
    }



    return 0;
}