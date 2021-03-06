#include "bits/stdc++.h"

using namespace std;

void print(string str){
    for (int i =0; i< str.size(); i++){
        cout << str[i];
    }
    cout << endl;
}

void perm (string str, int i, int n){
    if (i==n) print(str);
    for (int j=i; j<n; j++){
        swap(str[i], str[j]);
        perm(str, i+1, n);
        swap(str[i], str[j]);
    }
}

int main () {
    string str = "abc";
    int N = str.size();
    perm(str, 0, N);
    return 0;
}