#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    string tmp, novel = "";
    vector< string > table;
    vector< int > vs;
    map< string, bool > m;
    int i;

    while (getline(cin, tmp) && tmp != "0"){
        if (tmp.length() == 0){ // ignore break line
            novel += "\n";
            continue;
        }

        string out = "";
        for (int i=0; i<tmp.length(); i++){
            if ( i<tmp.length() && isalpha(tmp[i]) ){
                string word = "";
                while ( isalpha(tmp[i]) ){
                    word += tmp[i++];
                }
                
                if (m.find(word) == m.end()){ // insert to the front if DNE
                    table.insert( table.begin(), word );
                    m[word] = true;
                }
                out += word;
            }
            if ( i<tmp.length() && isdigit(tmp[i]) ){
                int v = 0;
                while ( isdigit(tmp[i]) ){
                    v = v * 10 + tmp[i++] - '0';
                }
                
                out += table[v-1];
                string tmp = table[v-1];
                table.erase(table.begin() + v-1);
                table.insert(table.begin(), tmp);
                vs.push_back(v);
            }
            if ( i<tmp.length() && !isalnum(tmp[i]) ){
                out += tmp[i];
            }
        }

        novel += out + "\n";
    }

    cout << novel;

    return 0;
}