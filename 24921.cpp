#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node{
    char which;
    int x;
    int y;
};

// Use the thinking:
//  move possible ones to center
//  construct the `s` is the first work

int main(){
    int night,
        s, wa, wb, u = 10000,
        i, j, k, l;
    Node a1, a2, b1, b2;
    cin >> night;
    for (int d=1; d<=night; d++){
        cin >> a1.x >> a1.y >> a2.x >> a2.y
            >> b1.x >> b1.y >> b2.x >> b2.y;
        wa = (a2.x - a1.x ) * (a2.y - a1.y);
        wb = (b2.x - b1.x ) * (b2.y - b1.y);
        i = max(a1.x, b1.x);
        j = max(a1.y, b1.y);
        k = min(a2.x, b2.x);
        l = min(a2.y, b2.y);
        s = ( i - k ) * ( j - l );
        if (i >= k || j >= l) s = 0;
        printf("Night %d: %d %d %d\n", d, s, wa+wb-2*s, u-(wa+wb-s));
    }

    return 0;
}