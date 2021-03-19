#include <iostream>
#include <bitset>
#define fori(x, y) for (int i = x; i< y; i++)
#define sz(arr) (*(&arr+1) - arr)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]= {1, 9, 3, 6, 2, 0, 9};
    int tam = sz(arr);
    int carryin=8; //basically, the inicial sum is also a carry
    for(int i = tam-1; i>=0; i--){
        if(carryin+arr[i]>9){
            arr[i] = (carryin+arr[i])%10;
            carryin=1;
        }
        else{
            arr[i] = (carryin+arr[i]);
            carryin =0;
        }
    }
    fori(0, tam) cout <<arr[i];
    return 0;
}

