#include <iostream>
#include <string>
#include <unordered_map>
#define fori(x, y) for (int i = x; i< y; i++)
#define sz(arr) (*(&arr+1) - arr)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string roman="CCXCX";
    //considering all letter appears at most three times and 
    //the letters follow the rule: I only before V and X, V only before X...
    unordered_map <char, int> umap;
    bool isvalid = true;
    int teto = 10000;
    umap['I'] = 1;
    umap['V'] = 5;
    umap['X'] = 10;
    umap['L'] = 50;
    umap['C'] = 100;
    umap['D'] = 500;
    umap['M'] = 1000;
    int N =0;
    int cont = 1;
    fori(0, roman.size()){
        //cout << i << " " << teto << " ";
        if(roman[i]!=roman[i+1]){
            if(umap[roman[i+1]]>umap[roman[i]]){
                teto = umap[roman[i]];
                N-=cont*umap[roman[i]];
                cont =1;
            }
            //o else aqui, da maneira que esta definido, dispensa a verificacao 
            //no caso de roman[i+1] exceder o tamanho do roman
            else {
                if (umap[roman[i+1]]>=teto) isvalid = false;
                N+=cont*umap[roman[i]];
                cont =1;
            }
        }
        else{
            cont++;
        }
    }
    if(isvalid) cout << N << endl;
    else cout << "invalid" << endl;
    return 0;
}
