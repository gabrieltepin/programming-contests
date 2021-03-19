#include <iostream>
#define fori(x,y) for(int i = x; i < y ; i++)
using namespace std;
//..NONZERO ELEMENTS!!! NOT ONLY ONE ELEMENT PER TURN FFFFUUUU
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    //a for BOB, b for ALICE, BOB is first
    int N, a, b, x;
    while (T--){
        int BOB=0, ALICE=0, BOTH=0;
        cin >> N >> a >> b;
        fori(0, N){
            cin >> x;
            if (x%a==0 && x%b==0) BOTH++;
            if (x%a==0 && x%b!=0) BOB++;
            if (x%a!=0 && x%b==0) ALICE++;
        }
        //cout << BOTH << " " << BOB << " "<< ALICE << endl;
        if(BOTH>0) BOB++;
        //cout << BOB << " "<< ALICE << endl;
        if(BOB<=ALICE) cout << "ALICE\n";
        else cout << "BOB\n";
    }   
    return 0;
}
