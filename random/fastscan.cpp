#include <stdio.h>
#define fori(x, y) for(int i = x; i<y; i++)
#define rfori(x, y) for(int i = x; i>=y; i--)
typedef long long ll;
using namespace std;
inline int inp(){
    int noRead=0;
    char p=getchar_unlocked();
    while(p<33)
        p=getchar_unlocked();
    while(p>32){
        noRead = (noRead << 3) + (noRead << 1) + (p - '0');
        p=getchar_unlocked();
    }
    return noRead;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int T, N;
    ll v;
    T = inp();
    while (T--){
        int cont =0;
        ll m=numeric_limits<ll>::max(); //maximum speed so far
        N = inp();
        fori(0, N){
            v = inp();
            if(m>v){
                m=v;
                cont++;
            } 
        }
        printf("%d\n", cont);
    }
    return 0;
}
