#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w){ this->u=u; this->v=v; this->w=w; }
};

vector< int > ns;
void ini(){
    ns.resize(101);
    for (int i=0; i<101; i++){
        ns[i] = 2147483647;
    }
}


int main(){
    int n, s, t1, t2, u, v, mini, c=1, target;

    while (cin >> n && n != 0){
        cin >> s;
        ini();
        vector<Edge> es;
        while (cin >> t1 >> t2 && (t1 != 0 || t2 != 0)){
            es.push_back(Edge(t1, t2, -1));
        }
        // Bellman Ford(SPFA)
        ns[s] = 0;
        for (int t=0; t<n; t++){
            for (int i=0; i<es.size(); i++){
                u = es[i].u;
                v = es[i].v;
                if (ns[v] > ns[u] + es[i].w)
                    ns[v] = ns[u] + es[i].w;
            }
        }
        
        mini = 0;
        target = s;
        for (int i=1; i<=n; i++){
            if (ns[i] < mini){
                mini = ns[i];
                target = i;
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", c++, s, -mini, target);
    }
    

    return 0;
}