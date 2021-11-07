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

### Example
1. 24941 Uncompress text

## 卡特蘭數 (Catalan Number)
- 括號匹配、標準young 表，出棧序列、Dyck Words、找零錢、筆畫群峰...
- 二叉樹數量，不相交弦問題...
- 為比自身小的子問題集合而成
- 以不合法路徑做理解。
```
序列數
1 , 1 , 2 , 5 , 14 , 42 , 132 , 429 , 1430 , 4862 , 16796 , 58786 , 208012 , 742900 , 2674440 , 9694845 , 35357670 , 129644790
```
```
Definition
fn=f0∗fn−1+f1∗fn−2+…+fn−1*f0
```

### Implementation (Build table)
```cpp=
void catalen(){
    dp[0] = 1;
    dp[1] = 1;
    for (int n=2; n<=20; n++){
        for (int i=0; i<n; i++){
            dp[n] += dp[i]*dp[n-1-i];
        }
    }
}
```

### Example
1. 10501 Safe Salutations (不相交弦問題)
2. 10605 Count the Tree (二叉樹數目問題)