#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <climits>
#include <cfloat>
using namespace std;

struct pr{
    pair< int, int > a, b;
};

pr gen_pr(pair<int, int> a, pair<int, int> b){
    pr rtn;
    rtn.a = a;
    rtn.b = b;
    return rtn;
}

bool judge_common(pr p, pair< int, int > p2){
    double s = ((double)1/2)*( p.a.first*p.b.second + 
        p.b.first*p2.second + p2.first*p.a.second -
        p.a.first*p2.second - p.b.first*p.a.second - p2.first*p.b.second );
    return (s == 0) ? true:false;
}

int main(){
    int cse;
    cin >> cse;

    for (int t=0; t<cse; t++){
        int c, count = 0;
        cin >> c;

        map< double, bool > r;  // record for slope
        map< double, vector< pr > > r_corres; // record points of a slope
        vector< pair<int, int> > ps; // store points

        for (int p=0, p1, p2; p<c; p++){
            cin >> p1 >> p2;
            ps.push_back( make_pair(p1, p2) );
        }

        // count, record slope
        for (int i=0; i<ps.size(); i++){
            for (int j=i+1; j<ps.size(); j++){
                // 1 calculating slope
                double m = (double)( ps[i].second - ps[j].second ),
                        n = (double)( ps[i].first - ps[j].first );
                // 2 judge for disivor isnt zero (including horizontal)
                if ( n!=0 ){
                    if ( r.find(m/n) == r.end() ){
                        vector< pr > v;
                        v.push_back( gen_pr(ps[i], ps[j]) );

                        r[m/n] = true;
                        r_corres[m/n] = v;
                        count++;
                    }
                    else{
                        bool is = false;
                        // judge if equal
                        for (int g=0; g<r_corres[m/n].size(); g++){
                            pr now = r_corres[m/n][g];
                            if ( judge_common(now, ps[i]) ){
                                is = true;
                                break;
                            }
                        }
                        if (!is){
                            count++;
                            r_corres[m/n].push_back( gen_pr(ps[i], ps[j]) );
                        }
                    }
                }
                // 3 judge for divisor goes to zero (verticle)
                else{
                    if ( r.find(FLT_MIN) == r.end() ){
                        vector< pr > v;
                        v.push_back( gen_pr(ps[i], ps[j]) );
                        
                        r[FLT_MIN] = true;
                        r_corres[FLT_MIN] = v;
                        count++;
                    }
                    else{
                        bool is = false;
                        for (int g=0; g<r_corres[FLT_MIN].size(); g++){
                            pr now = r_corres[FLT_MIN][g];
                            if ( judge_common(now, ps[i]) ){
                                is = true;
                                break;
                            }
                        }
                        if (!is){
                            count++;
                            r_corres[FLT_MIN].push_back( gen_pr(ps[i], ps[j]) );
                        }
                    }
                }
                
            }
        }

        // output
        printf("%d\n", count);
    }


    return 0;
}
