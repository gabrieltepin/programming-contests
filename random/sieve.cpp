#include <iostream>
#define fori(x, y) for (int i = x; i< y; i++)
#define sz(arr) (*(&arr+1) - arr)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 100;
    bool* isprime = new bool[N];
    memset(isprime, true, N);
    isprime[0]=false;
    isprime[1]=false;
    fori(0, N){
        if(isprime[i]==true){
            for(int j=i+i; j<N; j+=i){
                isprime[j] = false;
            }
        }
    }
    fori(0, N){
        if(isprime[i]==true)
            cout << i << " ";
    }
    return 0;
}

