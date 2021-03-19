#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define tr(i, m) for(int i = 0; i < m; i++)
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0, T, N;
    cin >> T;
    int i;
    while (t++ < T){
        cin >> N;
        vector <ll> S(N);
        ll dif=10000000000;
        tr(i, N){
            cin >> S[i];
        }
        sort(S.begin(), S.end());
        tr(i, N-1){
            dif = min(abs(S[i+1]-S[i]), dif);
        }
        cout << dif << endl;        
    } 
    return 0;
}
