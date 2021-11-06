#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct P{
    // only take 0~9
    int teamNum,
        solved,
        panelty,
        submit,
        error[10];
};

void initP(P *p, int id){
    p->teamNum = id;
    p->panelty = 0;
    p->solved = 0;
    p->submit = 0;
    memset(p->error, 0, sizeof(p->error));
}

bool cmp(P a, P b){
    if (a.solved > b.solved)
        return true;
    if (a.solved < b.solved)
        return false;
    if (a.panelty < b.panelty)
        return true;
    if (a.panelty > b.panelty)
        return false;
    if (a.teamNum < b.teamNum)
        return true;
    return false;
}


int main(){
    // Information
    // solved problem
    // question condition
    // penalty time
    // Warning: case number

    int cases,
        teamNum,
        q,
        minute;
    string tmp,
           type;
    P players[101];

    cin >> cases;
    cin.ignore();
    getline(cin, tmp); // first blank

    while (cases--)
    {   
        for (int i=0; i<101; i++){
            initP(&(players[i]), i);
        }
        while (getline(cin, tmp) && (tmp != ""))
        {
            stringstream ss(tmp);
            ss >> teamNum >> q >> minute >> type;
            players[teamNum].submit = 1;
            //cout << teamNum << " " << q << " " << minute << " " << type << "\n";
            if (players[teamNum].error[q] == -1) continue;
            if (type == "I"){
                players[teamNum].error[q] ++;
            }
            else if (type == "C"){
                players[teamNum].solved++;
                players[teamNum].panelty += minute + 20*players[teamNum].error[q];
                players[teamNum].error[q] = -1;
            }
        }
        sort(players, players+101, cmp);
        for (int i=0; i<101; i++){
            if (players[i].submit == 1){
                cout << players[i].teamNum << " " <<  players[i].solved << " " << players[i].panelty << endl;
            }
        }
        if (cases > 0)
            cout << endl;
    }

    return 0;
}