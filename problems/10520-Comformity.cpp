#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

string toStr(vector< int > v){
    stringstream ss;
    string rtn;
    for (int i=0; i<5; i++)
        ss << v[i];
    ss >> rtn;
    return rtn;
}

int main(){
    int n;
    while (cin >> n){
        if (n == 0)
            break;

        map< string, int > m;
        map< string, int >::iterator itr;
        string t;

        for (int i=0, tmp; i<n; i++){
            vector< int > v;
            for (int j=0; j<5; j++){
                cin >> tmp;
                v.push_back(tmp);
            }
            // sort to gen key
            sort(v.begin(), v.end());
            t = toStr(v);

            // push if not find
            if ( m.find(t)==m.end() )
                m[t] = 1;
            else
                m[t]++;
        }

        int max = 0, count = 0;
        for (itr=m.begin(); itr!=m.end(); itr++){
            if (itr->second > max){
                count = itr->second;
                max = itr->second;
            }
            else if (itr->second == max){
                count += itr->second;
            }
        }

        printf("%d\n", count);
    }


    return 0;
}