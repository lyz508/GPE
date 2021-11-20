#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector< int > next_table;
void findNext(string str){
    next_table.clear();
    next_table.resize(str.length());
    next_table[0] = 0;
    for (int i=1; i<str.length(); i++){
        int j=next_table[i-1];

        // if not equal, back to formor next 
        // (continue at previous equal position)
        while (j>0 && str[i] != str[j])
            j = next_table[j-1];

        // if equal -> add length,
        // it not equal && go back to start pos -> len = 0
        if (str[i] == str[j])
            next_table[i] = j+1;
        else    
            next_table[i] = 0;
    }
}

int main(){
    string tmp;
    // what we want to find: len - prefix-subfix -> the string a
    // output n (len / a.len)
    while (cin >> tmp){
        if (tmp == ".")
            break;

        findNext(tmp);
        int k = tmp.length() - next_table[tmp.length()-1];
        if ( !(tmp.length() % k) )
            printf("%d\n", (int)tmp.length()/k);
        else
            printf("1\n");
    }
    
    return 0;
}