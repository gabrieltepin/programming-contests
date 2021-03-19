#include <iostream>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define rforj(x, y) for(int j = x; j >= y; --j)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    char arr[100][100];
    string str;
    cin >> N;
    while(N--){
        cin >> str;
        double x = sqrt(str.size());
        int K = (int)x;
        if(K*K<str.size()) ++K;
        fori(str.size(), K*K) str+='*';
        //cout << str << endl;
        int t =0;
        rforj(K-1, 0){
            fori(0, K){
                arr[i][j]= str[t++];
            }
        }
        fori(0, K)
            forj(0, K)
                if(arr[i][j]!='*') cout << arr[i][j];
        cout << "\n";
    }
    
    return 0;
}