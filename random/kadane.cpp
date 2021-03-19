#include <iostream>
#define fori(x, y) for(int i = x; i < y; i++)
#define sz(x) sizeof(x)/sizeof(x[0])
#define m(x, y) (x>y)?x:y
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, -10, 3, 3, -2, 9, -1200, 11};
    int sum = 0;
    int maxTotal =- 100;
    //index delimita o inicio o subarray que esta sendo somado
    //isub e fsub sao os indices do subarray cuja soma eh maxima
    int index=0, isub=0, fsub=0;
    fori(0, sz(arr)){
        sum+=arr[i];
        if (maxTotal < sum){
            fsub=i;
            isub = index;
        }
        maxTotal = m(maxTotal, sum);
        if (sum<0) {
            sum = 0;
            index = i+1;
        }
    }
    //agora, printamos todos os elementos de arr[isub] a arr[fsub]
    //o intervalo de i corresponde a: (isub) <= i < (fsub+1)
    fori(isub, fsub+1) cout << arr[i] << " ";
    cout << "\n";
    //a maior soma do subarray:
    cout << maxTotal << "\n";
    return 0;
}
