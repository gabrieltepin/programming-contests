#include <iostream>
typedef long long ll;
using namespace std;
//CUIDADO PRA NAO DIVIDIR POR ZERO!!
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    ll N, K;
    cin >> T;
    while (T--){
        cin >> N >> K;
        if (K!=0) cout << N/K << " " << N%K << "\n";
        else cout << 0 << " " << N << "\n";
    }
    return 0;
}
