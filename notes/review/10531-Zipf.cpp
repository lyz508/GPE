#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int main(){
    int n, f = 1;
    string tmp;

    while (cin >> n){
        if (f)
            f = 0;
        else
            printf("\n");


        map<string, int> m;
        map<string, int>::iterator itr;
        vector<string> store;

        while (getline(cin, tmp) && tmp != "EndOfText"){
            // save only alpha
            string t = "";
            for (int i=0; i<tmp.size(); i++){
                if (isalpha(tmp[i])){
                    string w = "";
                    while (isalpha(tmp[i]))
                        w += tolower(tmp[i++]);

                    if (m.find(w) == m.end())
                        m[w] = 1;
                    else
                        m[w] ++;
                }
            }
        }

        // iterate & output
        for (itr = m.begin(); itr!=m.end(); itr++){
            if (itr->second == n)
                store.push_back(itr->first);
        }
        sort(store.begin(), store.end());
        for (int i=0; i<store.size(); i++)
            printf("%s\n", store[i].c_str());
    }

    return 0;
}