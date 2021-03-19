#include "bits/stdc++.h"
using namespace std;

bool isInteger(double M){
    return floor(M)==M;
}

int main () {
    long long unsigned int N=1, M;
    for (int i=1; i<32; i++)
        N*=i;
    cout << N << endl;
    for (int i=16;i<32;i++){
        M = N/(i*i*(i+1)*(i+1));
        cout << isInteger(M) << " " << i << endl;
    }
    return 0;
}
