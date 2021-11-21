#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define ele pair<int, int>

void find(vector< pair<int, ele> > seq){
    vector<int> len = vector<int>(seq.size(), 1),
                prev = vector<int>(seq.size(), -1),
                output;
    int max, pos;

    // adjust LIS statement
    for (int i=0; i<seq.size(); i++){
        for (int j=i+1; j<seq.size(); j++){
            if (seq[j].second.first > seq[i].second.first 
                && seq[j].second.second < seq[i].second.second
                && len[i] + 1 > len[j]){
                len[j] = len[i] + 1;
                prev[j] = i;
            }
        }
    }

    // find larget
    max = len[0];
    pos = 0;
    for (int i=1; i<len.size(); i++){
        if (len[i] >= max){
            max = len[i];
            pos = i;
        }
    }

    // print out
    while (true){
        output.push_back(seq[pos].first);
        if (prev[pos] == -1)
            break;
        pos = prev[pos];
    }
    reverse(output.begin(), output.end());

    printf("%d\n", (int)output.size());
    for (int i=0; i<output.size(); i++)
        printf("%d\n", output[i]);

}

bool cmp (pair<int, ele> e1, pair<int, ele>e2){
    if (e1.second.first > e2.second.first)
        return false;
    if (e1.second.first == e2.second.first && e1.second.second < e2.second.second)
        return false;
    if (e1.second.first == e2.second.first && e1.second.second == e2.second.second)
        return true;
    return true;
}

int main(){
    int t1, t2, i=1;
    vector< pair<int, ele> > seq;
    while (cin >> t1 >> t2){
        seq.push_back(make_pair(i++, make_pair(t1, t2)));
    }
    sort (seq.begin(), seq.end(), cmp);

    find(seq);
    
    return 0;
}