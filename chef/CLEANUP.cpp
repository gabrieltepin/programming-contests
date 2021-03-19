#include <iostream>
#include <vector>
#include <bitset>
#define tr(x, y) for(int i = x; i < y; i++)
using namespace std;
typedef long long ll;
int main () {
    int T;
    cin >> T;
    int m, n;
    int done;
    while (T--){
        cin >> n >> m;
        vector <int> v(n, 0);
        //if job already been done, v[done-1] = 2
        tr(0,m){
            cin >> done;
            v[done-1] = 2;
        }
        //chef's turn is 0, assistant's turn is 1
        int turn = 0;
        //if job hasn't been done yet, assign turn
        tr(0, n){
            if(v[i]!=2){
                v[i] = turn;
                turn = turn ^ 1;
            }
        }
        //print chef's jobs
        tr(0, n){
            if(v[i]==0){
                cout << i+1 << " ";
            }
        }
        //print assistant's jobs
        cout << "\n";
        tr(0, n){
            if(v[i]==1){
                cout << i+1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
