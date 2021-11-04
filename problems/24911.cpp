#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
using namespace std;

string criti[3] = {"LEFT", "RIGHT", "SAME AS "};

int main(){
    string tmp;
    int ists[200] = {}, ist, cases, nums, iists=1, pos;
    stringstream ss;

    cin >> cases;
    while (cases--)
    {
        pos = 0;
        memset(ists, 0, sizeof(ists));
        iists = 1;
        cin >> nums;
        getchar();
        for (int i=0; i<nums; i++){
            getline(cin, tmp);
            if (tmp == criti[0])
                ists[iists++] = -1;
            else if (tmp == criti[1])
                ists[iists++] = 1;
            else{
                ss.clear();
                ss.str(tmp.substr(criti[2].length(), tmp.length()));
                ss >> ist;
                ists[iists++] = ists[ist];
            }
        }
        for (int i=0; i<iists; i++)
            pos += ists[i];
        printf("%d\n", pos);
    }

    return 0;
}