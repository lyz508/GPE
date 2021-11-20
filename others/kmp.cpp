#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector< int > next_table;
void findNext(string str){
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

    // printf("Partial Next Table: ");
    // for (int i=0; i<str.length(); i++)
    //     printf("%d ", next_table[i]);
}

void KMP(string str, string target){
    int str_len = str.length(),
        target_len = target.length(),
        p = 0, s = 0;
    while ( p<target_len && s < str_len ){
        if (target[p] == str[s]){
            p++; 
            s++;
        }
        else{
            if (p == 0)
                s++;
            else
                p = next_table[p-1]; // search from previous corresponding
        }
    }
    if (p == 0 || p != target_len)
        printf("Not found !\n");
    else
        printf("From %d to %d\n", s-target_len, s-1);
}

 int main(){
     string str, target;

     printf("Input string: ");
     cin >> str;
     findNext(str);

     printf("Input target: ");
     cin >> target;
     KMP(str, target);

     return 0;
 }