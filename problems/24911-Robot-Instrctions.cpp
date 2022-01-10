#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int same(string str){
    string tmp;
    int rtn;
    stringstream ss;
    ss << str;
    ss >> tmp;
    ss >> tmp;
    ss >> rtn;

    return rtn;
}

int main(){
    int t, n;
    string tmp;
    cin >> t;
    while (t--){
        vector<int> v;
        int pos = 0;
        v.push_back(0);
        cin >> n;
        cin.ignore();

        while (n--){
            getline(cin, tmp);
            
            if (tmp[0] == 'L'){
                pos -= 1;
                v.push_back(-1);
            }
            else if (tmp[0] == 'R'){
                pos += 1;
                v.push_back(1);
            }
            else{
                int s = same(tmp);
                v.push_back(v[s]);
                pos += v.back();
            }
        }

        printf("%d\n", pos);
    }

    return 0;
}