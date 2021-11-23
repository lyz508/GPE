#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

vector<int> len, previ, seq;
vector< vector<int> > record;
int L, pos;

void print_LIS(int i, vector<int> v){
    bool f = false;
    for (int k=0; k<i; k++){
        if (seq[k] <= seq[i] &&
            len[k] == len[i]-1){
                vector<int> r = v;
                r.push_back(seq[k]);
                print_LIS(k, r);
                f = true;
            }
    }

    if (!f){
        reverse(v.begin(), v.end());
        record.push_back(v);
        return;
    }
}

void LIS(){
    len = vector<int>(seq.size(), 1);
    previ = vector<int>(seq.size(), -1);
    record.clear();

    for (int i=0; i<seq.size(); i++){
        for (int j=i+1; j<seq.size(); j++){
            if (seq[j] >= seq[i] && len[j] < len[i] + 1){
                len[j] = len[i] + 1;
                previ[j] = i;
            }
        }
    }

    // find longest
    L = len[0];
    pos = 0;
    for (int i=1; i<len.size(); i++){
        if (len[i] > L){
            L = len[i];
            pos = i;
        }
    }

    for (int i=0; i<seq.size(); i++){
        vector<int> v;
        if (len[i] == L){
            v.push_back(seq[i]);
            print_LIS(i, v);
        }
    }

    printf("%lld\n", (int)record.size());
    for (int i=0; i<record.size(); i++){
        for (int j=0; j<L; j++){
            printf("%lld", record[i][j]);
            if (j != L-1)
                printf(" ");
        }
        printf("\n");
    }
}

int32_t main(){
    cin.sync_with_stdio();
    cin.tie(0);


    int t, n;
    cin >> t;

    while (t--){
        vector<int> v;

        cin >> n;
        for (int i=0, tmp; i<n; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        seq=v;
        LIS();
    }

    return 0;
}