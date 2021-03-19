#include <iostream>
#include <math.h>
#define fori(x, y) for(int i = 0; i < y; i++)
#define rfori(x, y) for(int i = x; i >= y; i--)
using namespace std;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    while (T--){
        cin >> N;
        int diff;
        int k = pow(1.0*N, 0.5);
        rfori(k, 1){
            if(N%i==0){
                diff = N/i - i;
                i=0;
            }
        }
        cout << diff << "\n";
    }
    return 0;
}