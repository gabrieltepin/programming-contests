#include <iostream>
#include <string.h>
#include <math.h>
#define fori(x, y) for(int i = x; i<y; i++)
#define rfori(x, y) for(int i = x; i>=y; i--)
#define M 100001
#define sz(arr) (*(&arr +1)- arr)
typedef long long ll;
using namespace std;
//segmented sieve
//primelist below is just to check what numbers j are prime,
//so we should to mark the primes' multiples in range
//sqrt(sqrt(1000000000)) == 177.82
int primelist[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
127, 131, 137, 139, 149, 151, 157, 163, 167, 173 ,179 ,181 ,191 ,193};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, m, n;
    cin >> T;
    while(T--){
        cin >> m >> n;
        bool primesinrange[m-n];
        memset(primesinrange, 1, m-n);
        for(int j = 3; j<=pow(n, 0.5); j+=2){
            bool ok =1;
            //check if j is prime to avoid redundance
            fori(0, sz(primelist)){
                if(j%primelist[i]==0 && j!=primelist[i]){
                    ok = 0;
                    i=sz(primelist);
                }
            }
            //if j is prime then mark all its multiples in the range
            if(ok){
                int k = m/j;
                if (j*k<m) k++;
                while(j*k<=n){
                    if(k!=1) primesinrange[j*k-m]=0;
                    k++;
                }
            }
        }
        fori(m,n+1){
            if((primesinrange[i-m] && i!=1 && i%2==1) || i==2) cout << i << "\n"; 
        }
        cout << "\n";
    }
    return 0;
}
