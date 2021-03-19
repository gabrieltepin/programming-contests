#include <bits/stdc++.h>
using namespace std;

void pal(string frase, int i){
    for (int k=i; k<frase.size();k++){
        cout << frase << endl;
        swap(frase[i], frase[k]);
        pal(frase, i+1);
        swap(frase[i], frase[k]);
    }
}
int main () {
    pal("abcd", 0);
    return 0;
}