#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i<y; i++)
#define rfori(x, y) for(int i = x; i>=y; i--)
using namespace std;
int main(){
    //"lembrar que escolher em um array ordenado k ultimos elementos 
    //e k primeiros elementos forma subarrays distintos entre si"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, K;
    cin >> T;
    while(T--){
        cin >> N >> K;
        int arr[N], sum=0, Wk=0, Wk_rev=0;
        fori(0, N){
            cin >> arr[i];
            sum+=arr[i];
        }
        sort(arr, arr+N);
        fori(0, K){
            Wk+=arr[i];
        }
        rfori(N-1, N-K){
            Wk_rev+=arr[i];
        }
        int sol1 = abs(sum - 2*Wk);
        int sol2 = abs(sum - 2*Wk_rev);
        cout << max(sol1, sol2) << "\n";
    }
    return 0;
}
