#include <iostream>
#include <string>
#include <stack>
#define fori(x, y) for (int i = x; i< y; i++)
#define sz(arr) (*(&arr+1) - arr)
#define cpystr(x, y) for(int i = 0; i<)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 10, cont =1;
    string in = "1";
    while(N--){
        cout << in << endl;
        string out ="";
        fori(0, in.size()){
            if(in[i]!=in[i+1]){
                out += to_string(cont)+in[i];
                cont=1;
            }
            else 
                cont++;
        }
        in = out;
    }
    return 0;
}
