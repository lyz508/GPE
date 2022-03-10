#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> prime;

bool testPrime(int x){
    for (int i=2; i * i <= x; i++){
        if (! (x % i))
            return false;
    }
    return true;
}

void ini(){
    prime.push_back(-1); // for index
    prime.push_back(2);
    for (int i=3; prime.size() < 3600; i++){
        if (testPrime(i))
            prime.push_back(i);
    }
}

struct Node{
    int now;
    Node *next, *last;
};

int main(){
    ini();
    int n;
    while (cin >> n && n != 0){
        // build circle
        Node root, *ptr = &root, *tmp;
        root.now = 1;
        for (int i=2; i<=n; i++){
            ptr->next = new Node;
            tmp = ptr;
            ptr = ptr->next;
            ptr->now = i;
            ptr->last = tmp;
        }
        ptr->next = &root; 
        root.last = ptr; // connect tail to head

        // delete by round
        int ith = 1, counter = prime[ith],
            current = n;
        ptr = &root;
        while (1){
            counter = counter % current; // accelerate
            while (counter-- > 1){
                ptr = ptr->next;
            }

            if (ptr->next->next != ptr){
                ptr->last->next = ptr->next;
                ptr->next->last = ptr->last;
                ptr = ptr->next;
                current --;
            }
            else{
                root = *(ptr->next);
                break;
            }

            ith ++;
            counter = prime[ith];
        }

        // output latest
        printf("%d\n", root.now);
    }


    return 0;
}