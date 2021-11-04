#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair{
    int a;
    int b;
};

bool cmp(Pair p1, Pair p2){
    if (p1.b > p2.b)
        return false;
    if (p1.b == p2.b){
        if (p1.a < p2.a)
            return false;
    }
    return true;
}


int main(){
    int table[300];
    string tmp;
    bool r=false;
    while (getline(cin, tmp)){
        if (r)
            cout << "\n";
        for (int i=0; i<300; i++) table[i] = 0;
        for (int i=0; i<tmp.length(); i++)
            table[(int)tmp[i]]++;
        int nn = 299;
        for (int i=300-1; i>=0; i--){
            if (table[i] != 0){
                nn = i;
                break;
            }
        }
        vector<Pair> v;
        for (int i=nn; i>=0; i--){
            if (table[i] != 0){
                Pair p;
                p.a = i;
                p.b = table[i];
                v.push_back(p);
            }
        }
        sort(v.begin(), v.end(), cmp);
        for (int i=0; i<v.size(); i++)
            cout << v[i].a << " " << v[i].b << "\n";
        r = true;
    }

    return 0;
}