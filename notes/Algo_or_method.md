# Algo or method
## 快速冪
- $O(lg n)$ 算 $n^n$
### Implementation
```cpp=
// faster power
int fp(int n, int p){
    if (p == 1) // end condition
        return n;

    int rtn, cp;
    if ( p%2 == 0 ){ // even
        cp = fp(n, p/2);
        rtn = cp * cp;
    }
    else{ // odd
        cp = fp(n, (p-1)/2);
        rtn = n * cp * cp;
    }

    return rtn;
}
```

### Example
1. 10416 Last digit

## 字串處理
- 轉數字
```cpp=
for (int i=0; i<tmp.length(); i++){
    // turn word
    if ( i<tmp.length() && isalpha(tmp[i]) ){
        string word = "";
        while ( isalpha(tmp[i]) ){
            word += tmp[i++];
        }
    }
    // turn number
    if ( i<tmp.length() && isdigit(tmp[i]) ){
        int v = 0;
        while ( isdigit(tmp[i]) ){
            v = v * 10 + tmp[i++] - '0';
        }
    }
    if ( i<tmp.length() && !isalnum(tmp[i]) ){
        // pass...
    }
}
```