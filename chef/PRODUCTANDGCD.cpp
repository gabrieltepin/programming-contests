#include <iostream>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //faltou colocar um limite no while pra se evitar o TLE
    //antes tava : ...while(P>1){
    //depois:  ...while(P>1 && k*k<=P){
    ll N, P;
    cin >> N >> P;
    if (N==1){
        cout << P << "\n";
        return 0;
    }
    if (P==1){
        cout << 1 << "\n";
        return 0;
    }
    ll gcd =1, k=2;
    int cont=0;
    while(P>1 && k*k<=P){
        while(P%k==0){
            //cout << k << " " << P << endl;
            P/=k;
            cont++;
            if(cont==N){ 
                gcd*=k;
                cont=0;
            }
        }
        if(k==2)k++;
        else k+=2;
        cont=0;
    }
    cout << gcd << "\n";
    return 0;
}
