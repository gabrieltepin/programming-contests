#include <iostream>
#include <cstdlib>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    cin >> A >> B;
    int C = abs(A-B);
    ((C+1)%10 == 0) ? cout << --C << endl : cout << ++C << endl;
    return 0;
}
