#include <iostream>
#include <bitset>
using namespace std;

int pow(int x, int y){
    if(y==0 || x ==1) return 1;
    if(y==1) return x;
    bool parity = y&1;
    int tmp = pow(x,y/2);
    if (parity) x = x*tmp*tmp;
    else x = tmp*tmp;
    return x;
}
/* non recursive:
int pow(int x, int n){
    int pow =1;
    while (n){
        if (n&1) pow = x*pow;
        x*=x;
        n>>1;
    }
    return pow;
}
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << pow(8, 2);
    return 0;
}

