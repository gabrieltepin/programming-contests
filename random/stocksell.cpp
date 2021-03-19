#include <iostream>
#include <bitset>
#include <limits>
#define fori(x, y) for (int i = x; i< y; i++)
#define sz(arr) (*(&arr+1) - arr)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int min_price_so_far =  numeric_limits<int>::max();
    int max_profit_today = numeric_limits<int>::min();
    int max_profit_so_far = numeric_limits<int>::min();
    //array em ordem de precos diarios dos stocks
    //lucro maximo: compra a 2, vende a 29994
    int arr[] = {10, 2, 412, 414, 4848, 29994, 141};
    fori(0, sz(arr)){
        max_profit_today = arr[i] - min_price_so_far;
        max_profit_so_far = max(max_profit_so_far, max_profit_today);
        min_price_so_far = min(min_price_so_far, arr[i]);
    }
    cout << max_profit_so_far << endl;
    return 0;
}

