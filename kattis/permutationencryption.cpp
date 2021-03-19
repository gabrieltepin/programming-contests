#include <iostream>
#include <string>
#include <sstream>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, key[25];
    string str, sbstr;
    while (cin >> n && n!=0){
        fori(1, n+1){
            cin >> key[i];
        }
        cin.ignore();
        getline(cin, str);
        //cout << str << endl;
        int a = 0;
        while(str.size()%n!=0) str+= " ";
        cout << "'";
        while(a<str.size()){
            sbstr = str.substr(a, n);
            fori(1, n+1){
                cout << sbstr[key[i]-1];
            }
            a+=n;
        }
        cout << "'\n";
    }
    return 0;
}