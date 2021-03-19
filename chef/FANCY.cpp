#include <iostream>
#include <string>
#include <sstream>
#define fori(x,y) for(int i = x; i < y ; i++)
typedef long long ll;
using namespace std;
bool isfancy(string str, int tam){
    //menos de 3 letras
    if(tam<3) 
        return 0;
    //exatamente 3 letras e not eh a palavra
    if (tam==3 && str[tam-1] == 't' && str[tam-2] == 'o' && str[tam-3] == 'n') 
        return 1; 
    //a ultima palavra eh not
    if (tam>3 && str[tam-1] == 't' && str[tam-2] == 'o' && str[tam-3] == 'n' && str[tam - 4] == ' ') 
        return 1;
    //not no meio da frase
    fori(0, tam-3){
        if (str[i] == 'n' && str[i+1] == 'o' && str[i+2] == 't' && str[i+3] == ' ') return 1;
    }
    //sem not
    return 0;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    cin.ignore();
    while (T--){
        string str;
        getline(cin, str, '\n');
        //cout << str << endl;
        int tam = str.size();
        if (isfancy(str, tam))
            cout << "Real Fancy\n";
        else   
            cout << "regularly fancy\n"; 
    }
    return 0;
}
