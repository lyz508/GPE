#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > map;

void LIS(vector<int> seq){
    vector<int> len = vector<int>(seq.size(), 1),
                prev = vector<int>(seq.size(), -1);
    for (int i=0; i<seq.size(); i++){
        for (int j = i+1; j<seq.size(); j++){
            if (seq[i] < seq[j] && len[i] + 1 > len[j]){
                len[j] = len[i] + 1;
                prev[j] = i;
            }
        }
    }
}

char find(int x, int y){
    int rtn = 0;
    if (map[x][y] == '*')
        return '*';

    for (int r=-1; r<=1; r++){
        for (int c=-1; c<=1; c++){
            if (x+r >= 0 && x + r <= map.size() &&
                y+c >=0 && y+c <= map[0].size() && map[x+r][y+c] == '*')
                rtn ++;
        }
    }

    return '0' + rtn;
}

int main(){
    int num;
    vector< vector<int> > len(num, vector<int>(num, 0));


    return 0;
}