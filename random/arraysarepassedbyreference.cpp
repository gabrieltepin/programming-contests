#include <iostream>
using namespace std;
void print(int arr[M][M]){
    for(int i = 0; i< M; i++){
        for ( int j = 0; j< M; j++){\
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void foo(int arr[][3]){
    arr[1][1]= 0;
}
int main() {
    int arr[3][3]={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    print(arr);
    foo(arr);
    print(arr);

    return 0;
}

