# 快速冪
- $O(lg n)$ 算 $n^n$
## Implementation
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

## Example
1. 10416 Last digit