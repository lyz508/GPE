#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


string v2str(vector<int> v){
    string rtn = "";
    for (int i=0; i<v.size(); i++){
        stringstream ss;
        string str;
        ss << v[i];
        ss >> str;
        rtn += str;
    }
    return rtn;
}

int main(){
    int n;
    while (cin >> n && n != 0){
        map<string, int> table;
        map<string, int>::iterator itr;

        for (int t=0; t<n; t++){
            vector<int> v;
            for (int i=0, tmp; i<5; i++){
                cin >> tmp;
                v.push_back(tmp);
            }
            sort(v.begin(), v.end());
            string tmp = v2str(v);

            if (table.find(tmp) != table.end())
                table[tmp] += 1;
            else
                table[tmp] = 1;
        }

        int max = 0, count = 0;
        // iterate map
        for (itr = table.begin(); itr != table.end(); itr++){
            if (itr->second == max)
                count += itr->second;
            else if (itr->second > max){
                max = itr->second;
                count = itr->second;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}