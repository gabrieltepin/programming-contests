#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll A, B, a, b;
    while(cin >> A >> B && B!=0){
        unordered_map <ll, int> umap;
        int contA = 0, contB = 0;
        a=A; b=B;
        while(umap.find(a)==umap.end()){
            //cout << a << " " << contA << endl;
            umap[a]=contA++;
            if(a==1) break;
            if(a%2==0) a/=2;
            else a = 3*a+1;
        }
        while(umap.find(b)==umap.end()){
            //cout << b << endl;
            contB++;
            if(b%2==0) b/=2;
            else b = 3*b+1;
        }
        cout << A << " needs " << umap[b] << " steps, " << B << " needs "<< contB << " steps, they meet at "<< b << "\n";
    }
    return 0;
}