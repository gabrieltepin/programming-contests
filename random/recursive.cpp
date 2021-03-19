#include<iostream>
using namespace std;

void f(int n, int*v){
    v[n] = 1 - v[n-1]*v[n-3]*v[n-4];
}
int main () {
    int v[2020];
    int s=2;
    v[0]=v[2]=0;
    v[1]=v[3]=1;
    v[4]=1;
    //cout << v[3];
    for (int i=4;i<=2018;i++){
        v[i] = 1 - v[i-1]*v[i-3]*v[i-4];
        s+= v[i];
    }
    cout << s << endl;
    return 0;
}