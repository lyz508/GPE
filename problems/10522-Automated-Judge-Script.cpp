#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

string tmp, ans, out;
vector< int > output;


int main(){
    int n, m, c=1;
    string tmp, ans, out, tmp2;
    while (cin >> n && n != 0){
        // init
        cin.ignore();
        ans = "";
        out = "";
        bool AC = false, PE = false;

        // input
        for (int i=0; i<n; i++){
            getline(cin, tmp);
            ans += tmp + '\n';
        }

        cin >> m;
        cin.ignore();
        for (int i=0; i<m; i++){
            getline(cin, tmp);
            out += tmp + '\n';
        }

        //AC
        if (ans == out)
            AC = true;
        //PE
        if (!AC){
            string t1="", t2="";
            for (int i=0; i<ans.length(); i++){
                if ( isdigit(ans[i]) )
                    t1 += ans[i];
            }
            for (int i=0; i<out.length(); i++){
                if ( isdigit(out[i]) )
                    t2 += out[i];
            }

            if (t1 == t2)
                PE = true;
        }

        // output
        if (AC)
            output.push_back(1);
        else if (PE)
            output.push_back(0);
        else
            output.push_back(-1);
    }

    for (int i=0; i<output.size(); i++){
        if (output[i] == 1){
            printf("Run #%d: Accepted\n", i+1);
        }
        else if (output[i] == 0){
            printf("Run #%d: Presentation Error\n", i+1);
        }
        else if (output[i] == -1){
            printf("Run #%d: Wrong Answer\n", i+1);
        }
    }

    return 0;
}