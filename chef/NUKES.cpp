#include <iostream>
#define fori(x, y) for(int i = x; i<y; i++)
#define rfori(x, y) for(int i = x; i>=y; i--)
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, N, K;
    cin >> A >> N >> K;
    fori(0, K){
        cout << A%(N+1) << " ";
        A/=(N+1);
    }
    cout << "\n";
    return 0;
}
