#include <iostream>
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    ll x;
    cin >> N;
    while (N--){
        int count = 0;
        cin >> x;
        for(ll y =5; y<=x; y*=5){
            count += x/y;
        }
        //there are more factors '5's then '2's in factorization, 
        //then we just need to count numbers of 5
        cout << count << endl;
    }
    return 0;
}
