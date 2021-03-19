#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int W, P, arr[107];
    bool possible[107];
    fori(0, 107) possible[i] = false;
    cin >> W >> P;
    arr[0] = 0;
    arr[P+1] = W;
    fori(1, P+1){
        cin >> arr[i];
    }
    fori(1, P+2){
        forj(0, i){
            possible[arr[i]-arr[j]]=1;
        }
    }
    fori(1, 107)
        if(possible[i]) cout << i << " ";
    cout << "\n";
    return 0;
}