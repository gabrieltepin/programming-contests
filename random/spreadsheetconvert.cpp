#include <iostream>
#include <string>
#include <math.h>
#define rfori(x, y) for (int i = x-1; i>= 0; i--)
//#define sz(arr) (*(&arr+1) - arr) this doesn't work with strings!!!
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "ZZ";
    int N = str.size();
    int num=0;
    rfori(N, 0){
        //"A" stands for 1, but 'A' = 65 ASCII, and '@' = 64 ASCII 
        //So upper case - '@' should correspond to the index numeration
        num += (str[i] - '@')*pow(26, i);
    }
    cout << num << endl;

    return 0;
}

