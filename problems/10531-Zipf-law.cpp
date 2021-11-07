#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string toLower(string str){
    for (int i=0; i<str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

int main(){
    int n, f = 1;
    while (cin >> n){
        if (f) f = 0;
        else
            printf("\n");

        map< string, int > m;
        map< string, int >::iterator itr;
        vector< string > output;

        string tmp;
        while (getline(cin, tmp) && tmp != "EndOfText"){
            for (int i=0; i<tmp.size(); i++){
                if ( isalpha(tmp[i]) ){
                    string w = "";
                    while ( isalpha(tmp[i]) )
                        w += tmp[i++];
                    w = toLower(w);
                    
                    // insert
                    if (m.find(w) == m.end())
                        m[w] = 1;
                    else
                        m[w] ++;
                }
            }
        }

        // show
        for ( itr=m.begin(); itr!=m.end(); itr++ ){
            if ( itr->second==n )
                output.push_back(itr->first);
        }
        sort(output.begin(), output.end());
        for (int i=0; i<output.size(); i++)
            printf("%s\n", output[i].c_str());
    }

    return 0;
}