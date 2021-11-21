#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* LIS: Longest Increasing Subsequence
 * len: record IS length
 * prev: record last pos
 */
void LIS(vector<int> seq){
    int longest, pos;
    vector<int> len = vector<int>(seq.size(), 0),
        prev = vector<int>(seq.size(), -1),
        output;

    // dp len
    for (int i=0; i<seq.size(); i++){
        for (int j=i+1; j<seq.size(); j++){
            if (seq[i] < seq[j] && len[i] + 1 > len[j]){
                len[j] = len[i] + 1;
                prev[j] = i;
            }
        }
    }

    // find longest
    longest = len[0];
    pos = 0;
    for (int i=1; i<seq.size(); i++){
        if (len[i] > longest){
            longest = len[i];
            pos = i;
        }
    }

    // print out
    printf("Longest Increasing Subsequence: ");
    while (true){
        output.push_back(seq[pos]);
        if (prev[pos] == -1)
            break;
        pos = prev[pos];
    };
    reverse(output.begin(), output.end());
    for (int i: output)
        printf("%d ", i);
}

int main(){
    int n;
    vector<int> seq;
    printf("Input sequence: ");

    while (cin >> n)
        seq.push_back(n);

    LIS(seq);

    return 0;
}