#include <iostream>
#include <vector>
#include <algorithm>
#define tr(x, y) for(int i = x; i < y; i++)
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int N, K;
    while (T--){
        cin >> N;
        vector<int> A(N);
        tr(0,N){
            cin >> A[i];
        }
        cin >> K;
        int johny = A[K-1];
        sort(A.begin(), A.end());
        tr(0, N){
            if (A[i]==johny) cout << i+1 << "\n";   
        }
    }
    return 0;
}
