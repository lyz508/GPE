#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct iNode{
    string name;
    vector<iNode> children;
};

bool cmp(iNode a, iNode b){
    if (a.name >= b.name)
        return false;
    return true;
};

// sort iNodes with string order
void ordered(iNode& root){
    if (root.children.size() == 0) return;
    sort(root.children.begin(), root.children.end(), cmp);

    for (int i=0; i<root.children.size(); i++){
        ordered(root.children[i]);
    }
}

// insert node with vector names
void insert(iNode &root, vector<string> ns){
    if (ns.size() == 0) return;

    int f = -1;
    for (int i=0; i<root.children.size(); i++){
        if (root.children[i].name == ns[0]){
            f = i;
            break;
        }
    }

    if (f != -1){ // find -> insernt to exist
        ns.erase(ns.begin() + 0);
        insert(root.children[f], ns);
    }
    else{ // cant find -> build new iNode
        iNode new_node;
        new_node.name = ns[0];
        ns.erase(ns.begin() + 0);
        root.children.push_back(new_node);
        
        insert(root.children.back(), ns);
    }
}

void print_out(iNode &root, int t){
    for (int i=0; i<t; i++){
        printf(" ");
    }

    printf("%s\n", root.name.c_str());
    for (int i=0; i<root.children.size(); i++){
        print_out(root.children[i], t+1);
    }
}

int main(){
    iNode root;
    int n;
    string parse = "\\";
    cin >> n;

    for (int t=0; t<n; t++){
        string s;
        cin >> s;
        vector<string> names;
        // break to find insertion order
        while (s.find(parse) != string::npos){
            names.push_back( s.substr(0, s.find(parse)) );
            s.erase(0, s.find(parse) + parse.length());
        }
        names.push_back(s);

        // insert with data line
        insert(root, names);
    }
    // sort
    ordered(root);

    // print out
    for (int i=0; i<root.children.size(); i++){
        print_out(root.children[i], 0);
    }

    return 0;
}