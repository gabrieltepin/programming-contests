#include <iostream>
#include <bitset>
#define fori(x, y) for (int i = x; i< y; i++)
#define M 7
#define size(arr) (*(&arr+1) - arr)
using namespace std;
//like the dutch flag problem
void pivoting (int x, int (&arr)[M]){
    int i =0, j=M-1;
    while (i<j){
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;
        swap(arr[i], arr[j]);
    }
    fori(0, M) cout << arr[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]= {1, 9, 3, 6, 2, 0, -10};
    pivoting(1, arr);
    return 0;
}

