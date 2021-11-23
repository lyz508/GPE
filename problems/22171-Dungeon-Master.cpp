#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
struct Node{
    int x, y, z;
    int len;
};
 
int L, R, C,
    map[31][31][31],
    dx[6] = {0, 0, 0, 0, 1, -1},
    dy[6] = {0, 0, -1, 1, 0, 0},
    dz[6] = {1, -1, 0, 0, 0, 0};

bool visited[31][31][31];
Node S, E; //start, end
 
void bfs(){
    int rtn = -1;
     // ini
    memset(visited, 0, sizeof(visited));

    queue <Node> q;
    q.push(S);
    visited[S.x][S.y][S.z] = 1;

    while (q.size()){
        Node now = q.front();
        q.pop();
        if (now.x == E.x && now.y == E.y && now.z == E.z){
            rtn = now.len;
            break;
        }
        for (int i=0; i<6; i++){
            int c_x = now.x + dx[i],
                c_y = now.y + dy[i],
                c_z = now.z + dz[i];

            if (c_x >= 0 && c_x < L &&
                c_y >= 0 && c_y < R &&
                c_z >= 0 && c_z < C &&
                map[c_x][c_y][c_z] != '#' &&
                !visited[c_x][c_y][c_z]){
                q.push( {c_x, c_y, c_z, now.len+1} );
                visited[c_x][c_y][c_z] = true;
            }
        }
    }
    
    if (rtn == -1)
        printf("Trapped!\n");
    else
        printf("Escaped in %d minute(s).\n", rtn);
}
 
int main() {
    string s;

    while (cin >> L >> R >> C){
        //end condition
        if (L == 0 && R == 0 && C == 0) 
            break;

        for (int i=0; i<L; i++){
            for (int j=0; j<R; j++){
                cin >> s;
                for (int k=0; k<C; k++){
                    map[i][j][k] = s[k];

                    if (s[k] == 'S')
                        S = {i, j, k, 0};
                    if (s[k] == 'E')
                        E = {i, j, k, 0};
                }
            }
        }

        bfs();
    }
    return 0;
}